#include "parser.h"

void
startElement(void *userData, const char *name, const char **atts)
{
    printf("startElem:");
    printf(name );
    printf( "\n" );

    // if opf:meta and cnt_attrs=2
    //
    // if cnt_attrs=1
}
