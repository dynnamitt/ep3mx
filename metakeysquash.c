#include <stdio.h>
#include <ctype.h>
#include "dbg.h"
#include "expat.h"


int print_a_message(const char *msg)
{
    printf("A STRING: %s\n", msg);

    return 0;
}

int
main(int argc, char *argv[])
{
  XML_Parser parser = XML_ParserCreate(NULL);
  print_a_message("done!");
}
