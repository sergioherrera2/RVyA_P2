DIROBJ := obj/
DIREXE := exec/
DIRHEA := include/
DIRSRC := src/

CFLAGS := -I$(DIRHEA) -c -Wall -ansi
LDFLAGS := -lglut -lGLU -lGL
CC := gcc

all: dirs helloOpenGL helloOpenGL2 test

dirs:
	mkdir -p $(DIROBJ) $(DIREXE)

helloOpenGL: $(DIROBJ)helloOpenGL.o 
	$(CC) -o $(DIREXE)$@ $^ $(LDFLAGS)
	
helloOpenGL1: $(DIROBJ)helloOpenGL1.o 
	$(CC) -o $(DIREXE)$@ $^ $(LDFLAGS)

test: $(DIROBJ)test.o 
	$(CC) -o $(DIREXE)$@ $^ $(LDFLAGS)

$(DIROBJ)%.o: $(DIRSRC)%.c
	$(CC) $(CFLAGS) $^ -o $@

clean: 
	rm -rf *~ core $(DIROBJ) $(DIREXE) $(DIRHEA)*~ $(DIRSRC)*~
