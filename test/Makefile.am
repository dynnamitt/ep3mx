check_LIBRARIES = libtest-handler.a
libtest_handler_a_SOURCES = test-handler.c

check_PROGRAMS = parse-test 
# TODO avoid dbl compile !! just link
parse_test_SOURCES = ../src/parser.c
parse_test_LDADD = libtest-handler.a



check_SCRIPTS = parse_sample.sh

TESTS = parse_sample.sh

CLEANFILES = $(TESTS) 

parse_sample.sh : Makefile.am
	echo './parse-test < fixture/sample.xml | head -n1 | grep -E "a$$"' > $@
	chmod +x $@

