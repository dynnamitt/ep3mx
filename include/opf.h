#include <sys/queue.h>

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
 * \c opfmeta_slist_head SLIST_HEAD 
 *
 * returns a squashed (set) version of param
 *
 */
opfmeta_entry_s *squash_opfmeta(const opfmeta_entry_s *opfmeta_slist_head);
