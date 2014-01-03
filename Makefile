P=metakeysquash
OBJECTS=
CFLAGS= -g -Wall -O3
LDLIBS= -lexpat
CC=c99

.PHONY: check

check: 
	@./$(P); echo " return-code: $$?"

$(P): $(OBJECTS)
