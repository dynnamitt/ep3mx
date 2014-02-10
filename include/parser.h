#ifndef parser_h
#define parser_h
#include <stdio.h>
#include <stdio.h>
#include <ctype.h>
#include "dbg.h"
#include <expat.h>


#ifdef XML_LARGE_SIZE
#if defined(XML_USE_MSC_EXTENSIONS) && _MSC_VER < 1400
#define XML_FMT_INT_MOD "I64"
#else
#define XML_FMT_INT_MOD "ll"
#endif
#else
#define XML_FMT_INT_MOD "l"
#endif

#endif
