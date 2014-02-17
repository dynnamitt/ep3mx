AM_CFLAGS=-Wall

check_LIBRARIES = libtest-handler.a
libtest_handler_a_SOURCES = test-handler.c

check_PROGRAMS = parse-test squash-meta-test

# compile `parse-test` using src/ code file
#
# TODO avoid dbl compile !! but HOWTO just do OBJ link?
parse_test_SOURCES = $(top_srcdir)/src/parser.c
parse_test_LDADD = libtest-handler.a 


# compile `squash-meta` using local file
#
squash_meta_test_SOURCES = squash-meta.c 
squash_meta_test_LDADD = $(top_srcdir)/src/libopf-handler.a 

check_SCRIPTS = parse_sample.sh

TESTS = parse_sample.sh squash-meta-test 

# some leftovers (must die @ clean-time) 
# from below custom targets
CLEANFILES = $(TESTS) 

parse_sample.sh : Makefile.am
	echo './parse-test < fixture/sample.xml | head -n1 | grep -E "a$$"' > $@
	chmod +x $@

