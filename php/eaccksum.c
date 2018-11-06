#include "../eac-cksum.h"
#include "php_eaccksum.h"

PHP_FUNCTION(eaccksum_verify) {
  /*
   1. define variables for string value and length
   */
  char *name;
  size_t name_len;

  /*
   2. parse parameters using FAST ZPP Api
   https://wiki.php.net/rfc/fast_zpp
   */
  ZEND_PARSE_PARAMETERS_START(1, 1)
  Z_PARAM_STRING(name, name_len)
  ZEND_PARSE_PARAMETERS_END();

  struct eac_cksum_state s;
  eac_cksum_state_init(&s);
  long rv = -1;
  FILE *f = fopen(name, "rb");
  if (f) {
    rv = eac_cksum_verify(&s, f);
    fclose(f);
  }
  RETURN_LONG(rv);
}

const zend_function_entry php_eaccksum_functions[] = {ZEND_NS_NAMED_FE(
    PHP_EACCKSUM_EXT_NS, verify, ZEND_FN(eaccksum_verify), NULL) PHP_FE_END};

zend_module_entry eaccksum_module_entry = {
    STANDARD_MODULE_HEADER,
    PHP_EACCKSUM_EXT_NAME,
    php_eaccksum_functions, /* Functions */
    NULL,                   /* MINIT */
    NULL,                   /* MSHUTDOWN */
    NULL,                   /* RINIT */
    NULL,                   /* RSHUTDOWN */
    NULL,                   /* MINFO */
    PHP_EACCKSUM_EXT_VERSION,
    STANDARD_MODULE_PROPERTIES};

#ifdef COMPILE_DL_EACCKSUM
#ifdef ZTS
ZEND_TSRMLS_CACHE_DEFINE()
#endif
ZEND_GET_MODULE(eaccksum)
#endif
