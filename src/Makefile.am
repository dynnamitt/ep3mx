AM_CFLAGS=-Wall

noinst_LIBRARIES = libopf-handler.a
libopf_handler_a_SOURCES = opf-handler.c squash-meta-slist.c 

bin_PROGRAMS = parse-ep3
parse_ep3_SOURCES = parser.c
parse_ep3_LDADD = libopf-handler.a
