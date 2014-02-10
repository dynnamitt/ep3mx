#include "include/parser.h"

#define BUFSIZE 10240

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



int main (int argc, char** argv)
{
  FILE* xml = stdin;
  char buf[BUFSIZE];
  XML_Parser parser = XML_ParserCreateNS(NULL,'\t');
  check_mem(parser);

  int done;
  int depth = 0;

  XML_SetUserData(parser, &depth);
  XML_SetStartElementHandler(parser,startElement);

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
