#ifndef parser_h
#define parser_h

#include <stdio.h>
#include <expat.h>

#define BUFSIZE 10240

#ifdef XML_LARGE_SIZE
#if defined(XML_USE_MSC_EXTENSIONS) && _MSC_VER < 1400
#define XML_FMT_INT_MOD "I64"
#else
#define XML_FMT_INT_MOD "ll"
#endif
#else
#define XML_FMT_INT_MOD "l"
#endif

//default impl of conf_ep3mx_handlers interface
void simple_elname_printer(XML_Parser p);


void startElement(void *userData, const char *name, const char **atts);

typedef void (*conf_ep3mx_handlers)(XML_Parser p);

int ep3mx_parse(FILE *xml, const conf_ep3mx_handlers setter);

#endif
