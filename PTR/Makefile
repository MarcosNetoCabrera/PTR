# Makefile para projetos do curso
# e-mail: andrecavalcante@ufam.edu.br
#

PRJ=$(shell basename "$(CURDIR)")

sources = $(filter-out $(srcdir)/main.c, $(wildcard $(srcdir)/*.c))
includes= $(wildcard $(incdir)/*.h)
objects = $(patsubst $(srcdir)/%.c, $(objdir)/%.o, $(sources))

srcdir=./src
incdir=./inc
objdir=./obj
libdir=./lib

CC=gcc
CFLAGS=-Wall -O3 -I $(incdir)
CPPFLAGS=
LDFLAGS=-L $(libdir)
LDLIBS=-ggdb
#LDLIBS=-lm -lpthread -lstdc++

all: $(PRJ)

showvars:
	@echo $(PRJ)
	@echo Dirs: $(incdir) $(srcdir) $(objdir) $(libdir)
	@echo Sources:  $(sources)
	@echo Objects:  $(objects)
	@echo Includes: $(includes)
	@echo CC: $(CC)
	@echo FLAGS: $(CFLAGS) $(CPPFLAGS)
	@echo LDFLAGS: $(LDFLAGS)
	@echo LIBS: $(LDLIBS)

$(PRJ): $(srcdir)/main.c $(objects) $(includes)
	$(CC) $(CFLAGS) $(CPPFLAGS) -o $(PRJ) $(srcdir)/main.c $(includes) $(objects) $(LDFLAGS) $(LDLIBS)

$(objdir)/%.o: $(srcdir)/%.c
	$(CC) -c $(CFLAGS) $(CPPFLAGS) -o $@ $<

.PHONY: clean run

clean:
	@rm -rf $(PRJ) $(objdir)/*.o $(srcdir)/*~

run:
	@./$(PRJ) "$(ARGS)"
