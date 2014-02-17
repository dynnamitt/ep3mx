#include "include/dbg.h"
#include "include/opf.h"
#include <sys/queue.h>

// test disconnected from PARSER code

int main(void){

  // head def
  SLIST_HEAD(head_s, opfmeta_entry_s) opfmeta_head;

  // head init
  SLIST_INIT(&opfmeta_head);
  
  // defentrys
  opfmeta_entry_s no1 = { .ns = "http://dublinCore", .key = "dc_title", .val = "Publication no.1"};
  opfmeta_entry_s no2 = { .ns = "http://dublinCore", .key = "dc_subject", .val = "C coding"};
  opfmeta_entry_s no3 = { .ns = "http://dublinCore", .key = "dc_subject", .val = "GNU Autotools"};

  // ins
  SLIST_INSERT_HEAD(&opfmeta_head, &no1, entries);
  SLIST_INSERT_HEAD(&opfmeta_head, &no2, entries);
  SLIST_INSERT_HEAD(&opfmeta_head, &no3, entries);

  

  // boing
  opfmeta_entry_s *squashed_head = squash_opfmeta(&opfmeta_head);

  //free?
  

}
