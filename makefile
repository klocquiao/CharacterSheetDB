CC := g++
CPPFLAGS = -std=c++17 -Wall -Wextra -Werror -Wfatal-errors -Wno-sign-compare -Wnon-virtual-dtor -g 
LFLAGS := -lncurses
SOURCES :=  $(wildcard model/*.cpp) $(wildcard *.cpp)
TARGET := db

all: app

app:
	$(CC) $(CPPFLAGS) $(SOURCES) -o $(TARGET) $(LFLAGS)

clean:
	rm -f $(TARGET)

