DIROBJ := obj/
DIREXE := exec/
DIRHEA := include/
DIRSRC := src/

CFLAGS := -I$(DIRHEA) -c -Wall -ansi
LDFLAGS := -lglut -lGLU -lGL
CC := gcc

all: dirs helloOpenGL helloOpenGL1 helloOpenGL3 helloOpenGL4 helloOpenGL5 helloOpenGL6 helloOpenGL7 helloOpenGL8

dirs:
	mkdir -p $(DIROBJ) $(DIREXE)

helloOpenGL: $(DIROBJ)helloOpenGL.o 
	$(CC) -o $(DIREXE)$@ $^ $(LDFLAGS)
	
helloOpenGL1: $(DIROBJ)helloOpenGL1.o 
	$(CC) -o $(DIREXE)$@ $^ $(LDFLAGS)

helloOpenGL3: $(DIROBJ)helloOpenGL3.o 
	$(CC) -o $(DIREXE)$@ $^ $(LDFLAGS)

helloOpenGL4: $(DIROBJ)helloOpenGL4.o 
	$(CC) -o $(DIREXE)$@ $^ $(LDFLAGS)

helloOpenGL5: $(DIROBJ)helloOpenGL5.o 
	$(CC) -o $(DIREXE)$@ $^ $(LDFLAGS)

helloOpenGL6: $(DIROBJ)helloOpenGL6.o 
	$(CC) -o $(DIREXE)$@ $^ $(LDFLAGS)

helloOpenGL7: $(DIROBJ)helloOpenGL7.o 
	$(CC) -o $(DIREXE)$@ $^ $(LDFLAGS)

helloOpenGL8: $(DIROBJ)helloOpenGL8.o 
	$(CC) -o $(DIREXE)$@ $^ $(LDFLAGS)

$(DIROBJ)%.o: $(DIRSRC)%.c
	$(CC) $(CFLAGS) $^ -o $@

clean: 
	rm -rf *~ core $(DIROBJ) $(DIREXE) $(DIRHEA)*~ $(DIRSRC)*~
