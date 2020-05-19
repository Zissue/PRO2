OPCIONS = -D_JUDGE_ -D_GLIBCXX_DEBUG -O2 -Wall -Wextra -Werror -Wno-sign-compare -std=c++11

program.exe: program.o Cjt_idiomas.o Idioma.o Tabla.o Treecode.o
	g++ -o program.exe program.o Cjt_idiomas.o Idioma.o Tabla.o Treecode.o $(OPCIONS)
	rm *.o

program.o: program.cc 
	g++ -c program.cc $(OPCIONS)

Cjt_idiomas.o: Cjt_idiomas.cc Cjt_idiomas.hh 
	g++ -c Cjt_idiomas.cc $(OPCIONS)

Idioma.o: Idioma.cc Idioma.hh 
	g++ -c Idioma.cc $(OPCIONS)

Tabla.o: Tabla.cc Tabla.hh 
	g++ -c Tabla.cc $(OPCIONS)

Treecode.o: Treecode.cc Treecode.hh 
	g++ -c Treecode.cc $(OPCIONS)

clean:
	rm *.o
	rm *.exe
	rm *.gch
	rm *.tar
	rm *.x

objects: program.cc Cjt_idiomas.cc Cjt_idiomas.hh Idioma.cc Idioma.hh Tabla.cc Tabla.hh Treecode.cc Treecode.hh
	g++ -c program.cc Cjt_idiomas.cc Idioma.cc Tabla.cc Treecode.cc $(OPCIONS)

tar: program.cc Cjt_idiomas.cc Cjt_idiomas.hh Idioma.cc Idioma.hh Tabla.cc Tabla.hh Treecode.cc Treecode.hh
	tar -cvf practica.tar program.cc Cjt_idiomas.cc Cjt_idiomas.hh Idioma.cc Idioma.hh Tabla.cc Tabla.hh Treecode.cc Treecode.hh Makefile html.zip

doxygen: Doxyfile
	doxygen Doxyfile

to:
	g++ -c Treecode.cc Tabla.cc test.cc $(OPCIONS)
tx:
	g++ -o test.x Treecode.o Tabla.o test.o $(OPCIONS)
zip:
	doxygen Doxyfile
	zip -r html.zip html/