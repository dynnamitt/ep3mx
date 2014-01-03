P=metakeysquash
OBJECTS=
CFLAGS= -g -Wall -O3
LDLIBS= -lexpat
CC=c99

.PHONY: check ctags 

check: $(P)
	valgrind -q ./$(P) < sample.xml
	-valgrind -q ./$(P) < sample-bad.xml

$(P): $(OBJECTS)

aux_headers/ :
	mkdir -p $@

aux_headers/expat.h : aux_headers/
	-ln -s $$(find /usr/include -name expat.h) $@

ctags: tags
tags: aux_headers/expat.h
	ctags -R 
