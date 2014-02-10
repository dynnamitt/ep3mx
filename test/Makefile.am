check_LIBRARIES = libtest-dummy-handler.a
libtest_dummy_handler_a_SOURCES = test-dummy-handler.c

check_PROGRAMS = parse-dummy
parse_dummy_SOURCES = ../src/parser.c
parse_dummy_LDADD = libtest-dummy-handler.a



check_SCRIPTS = parse_sample.sh

TESTS = parse_sample.sh

CLEANFILES = $(TESTS) 

parse_sample.sh : Makefile.am
	echo './parse-dummy < fixture/sample.xml | head -n1 | grep -E "a$$"' > $@
	chmod +x $@

