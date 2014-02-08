#include <stdio.h>
#include <ctype.h>
#include "dbg.h"
#include "expat.h"
#include "parser.h"


// type conf_ep3mx_handlers
void simple_elname_printer(XML_Parser p){

    XML_SetStartElementHandler(p,startElement);

}

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



int
ep3mx_parse(FILE* xml,
    const conf_ep3mx_handlers conf_hndlers )
{
  char buf[BUFSIZE];
  XML_Parser parser = XML_ParserCreateNS(NULL,'\t');
  check_mem(parser);

  int done;
  int depth = 0;

  XML_SetUserData(parser, &depth);

  if(conf_hndlers == NULL){
    simple_elname_printer(parser);
  }else{
    conf_hndlers(parser);
  }

  // main parse loop
  do {
    int len = (int)fread(buf, 1, sizeof(buf), xml);
    done = len < sizeof(buf);

    if (XML_Parse(parser, buf, len, done) == XML_STATUS_ERROR) {
      sentinel( "XML %s at line %" XML_FMT_INT_MOD "u\n", 
          XML_ErrorString(XML_GetErrorCode(parser)), 
          XML_GetCurrentLineNumber(parser));
    }

  } while (!done);

  XML_ParserFree(parser);
  return 0;

error:
  if(parser) XML_ParserFree(parser);
  return 1;

}
