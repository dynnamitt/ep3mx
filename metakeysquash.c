#include <stdio.h>
#include <ctype.h>
#include "dbg.h"
#include "expat.h"

#define BUFSIZE 2048

int print_a_message(const char *msg)
{
    printf("A STRING: %s\n", msg);

    return 0;
}

int
main(int argc, char *argv[])
{
  char buf[BUFSIZE];
  XML_Parser parser = XML_ParserCreate(NULL);
  int done;
  int depth = 0;
  XML_SetUserData(parser, &depth);
  /* XML_SetElementHandler(parser, startElement, endElement); */
  do {
    int len = (int)fread(buf, 1, sizeof(buf), stdin);
    done = len < sizeof(buf);
    if (XML_Parse(parser, buf, len, done) == XML_STATUS_ERROR) {
      sentinel("boyy");
      /* sentinel( "%s at line %" XML_FMT_INT_MOD "u\n", XML_ErrorString(XML_GetErrorCode(parser)), XML_GetCurrentLineNumber(parser)); */
    }

  } while (!done);

  XML_ParserFree(parser);
  return 0;

error:
  if(parser) XML_ParserFree(parser);
  return 1;

}
