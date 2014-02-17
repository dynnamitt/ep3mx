#ifndef opf_h
#define opf_h

#include <sys/queue.h>


#ifndef METAVAL_JOIN_STR
#define METAVAL_JOIN_STR ", "
#endif


/**
 *
 * opfmeta_entry_s (typedef+struct)
 *
 * \c .ns namespace
 * \c .key 
 * \c .value
 *
 * Psudo xpath code that defines key-variants
 * (found so far) in div OPF3 files:
 *
 * \c 1a. key_prefix = if ( ns($elem) != ns(opf) ) then ns-shortcut($elem)
 * \c 1b. key_prefix = if ( ns($elem) = ns(opf) ) then ''
 * \c 2. key = if ( count($elem/@*)=1 and $leme ) then
 * ...
 * \c 3. key = if ( count($elem/@*)=1 and not($el/text())
 * ...
 * \c 4. key = if ( $elem/@name and $el/@content )
 *
 */
typedef struct opfmeta_entry_s {
  
  char *ns, *key, *val;
  
  SLIST_ENTRY(opfmeta_entry_s) entries;

} opfmeta_entry_s;

/*
 * head struct typedef
 */
typedef SLIST_HEAD(opfmeta_head_s, opfmeta_entry_s) opfmeta_head_s;


/*
 * \c opfm_h = opfmeta_slist_head 
 *
 * returns a squashed (set) version of param
 *
 */
opfmeta_head_s *squash_opfmeta(const opfmeta_head_s *opfm_h);

#endif
