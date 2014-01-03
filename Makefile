P=metakeysquash
OBJECTS=
CFLAGS= -g -Wall -O3
LDLIBS= -lexpat
CC=c99

.PHONY: check

check: $(P)
	valgrind -q ./$(P) < sample.xml
	valgrind -q ./$(P) < sample-bad.xml

$(P): $(OBJECTS)
