#ifndef PHP_EACCKSUM_H
#define PHP_EACCKSUM_H

#define PHP_EACCKSUM_EXT_NAME "eaccksum"
#define PHP_EACCKSUM_EXT_VERSION "1.0"
#define PHP_EACCKSUM_EXT_NS "eaccksum"

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif /* HAVE_CONFIG_H */

#include "php.h"

#ifdef ZTS
#include "TSRM.h"
#endif

#if defined(ZTS) && defined(COMPILE_DL_EACCKSUM)
ZEND_TSRMLS_CACHE_EXTERN()
#endif

#endif /* PHP_EACCKSUM_H */
