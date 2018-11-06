#ifndef EAC_CKSUM_H
#define EAC_CKSUM_H

#include <stdint.h>
#include <stdio.h>

struct eac_cksum_state {
  uint8_t buf[32];
  uint8_t log_sum[32];
  uint32_t aes[8];
  unsigned int buf_used;
};

void eac_cksum_state_init(struct eac_cksum_state *s);

#define EAC_CKSUM_VERIFY_OK 1
#define EAC_CKSUM_VERIFY_NOK 0
#define EAC_CKSUM_NO_LOG_CHECKSUM 2

int eac_cksum_verify(struct eac_cksum_state *s, FILE *f);

#endif
