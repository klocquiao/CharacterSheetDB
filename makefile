# Set the C++ compiler options:
#   -std=c++17 compiles using the C++17 standard (or at least as 
#    much as is implemented by the compiler, e.g. for g++ see
#    http://gcc.gnu.org/projects/cxx0x.html)
#   -Wall turns on all warnings
#   -Wextra turns on even more warnings
#   -Werror causes warnings to be errors 
#   -Wfatal-errors stops the compiler after the first error
#   -Wno-sign-compare turns off warnings for comparing signed and 
#    unsigned numbers
#   -Wnon-virtual-dtor warns about non-virtual destructors
#   -g puts debugging info into the executables (makes them larger)
CPPFLAGS = -std=c++17 -Wall -Wextra -Werror -Wfatal-errors -Wno-sign-compare -Wnon-virtual-dtor -g 

main_test: main.o menu.o character.o database.o menudisplays.o mainmenu.o addmenu.o findmenu.o deletemenu.o listmenu.o
	g++ -o main_test menu.o main.o character.o database.o menudisplays.o mainmenu.o addmenu.o findmenu.o deletemenu.o listmenu.o -lncurses 

main:
	g++ -c $(CPPFLAGS) main.cpp

menu:
	g++ -c $(CPPFLAGS) menu.cpp

character:
	g++ -c $(CPPFLAGS) character.cpp

database:
	g++ -c $(CPPFLAGS) database.cpp

menudisplays:
	g++ -c $(CPPFLAGS) menudisplays.cpp

mainmenu:
	g++ -c $(CPPFLAGS) mainmenu.cpp

addmenu:
	g++ -c $(CPPFLAGS) addmenu.cpp

findmenu:
	g++ -c $(CPPFLAGS) findmenu.cpp

deletemenu:
	g++ -c $(CPPFLAGS) deletemenu.cpp

listmenu:
	g++ -c $(CPPFLAGS) listmenu.cpp


clean:
	rm -f main_test menu.o main.o character.o database.o mainmenu.o addmenu.o findmenu.o menudisplays.o deletemenu.o listmenu.o

