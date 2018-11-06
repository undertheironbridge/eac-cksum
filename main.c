#include "eac-cksum.h"

#include <assert.h>
#include <errno.h>
#include <stdio.h>
#include <string.h>

#define NUM_ELEMENTS(x) ((sizeof(x)) / sizeof(*x))

static void print_result(const struct eac_cksum_state *s, const char *name,
                         int is_nok) {
  char cksum[128];
  for (unsigned int i = 0; i < NUM_ELEMENTS(s->aes); ++i) {
    uint8_t bytes[4];
    memcpy(bytes, s->aes + i, sizeof(bytes));
    snprintf(cksum + (i * 8), sizeof(cksum) - (i * 8), "%02X%02X%02X%02X",
             bytes[0], bytes[1], bytes[2], bytes[3]);
  }
  if (is_nok) {
    printf("%s : NOK, computed %s\n", name, cksum);
  } else {
    printf("%s : %s\n", name, cksum);
  }
}

static int read_file(const char *name) {
  struct eac_cksum_state s;
  eac_cksum_state_init(&s);
  FILE *f = fopen(name, "rb");
  if (!f) {
    char errbuf[256];
    strerror_r(errno, errbuf, sizeof(errbuf));
    printf("%s : Failed to open : %s\n", name, errbuf);
    return 1;
  }
  int rv = 0;
  int result = eac_cksum_verify(&s, f);
  switch (result) {
  case EAC_CKSUM_VERIFY_OK:
    printf("%s : OK\n", name);
    break;

  case EAC_CKSUM_NO_LOG_CHECKSUM:
    print_result(&s, name, 0);
    break;

  case EAC_CKSUM_VERIFY_NOK:
    rv = 1;
    print_result(&s, name, 1);
    break;

  default:
    assert(0);
  }
  fclose(f);
  return rv;
}

int main(int argc, char **argv) {
  int rv = 0;
  for (int i = 1; i < argc; ++i) {
    rv |= read_file(argv[i]);
  }
  return rv;
}
