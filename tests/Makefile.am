check_SCRIPTS = parse_sample.sh

TESTS = parse_sample.sh

CLEANFILES = $(TESTS)

parse_sample.sh : Makefile.am
	echo '../src/parse-stdin < fixture/sample.xml | grep "b"' > $@
	chmod +x $@

