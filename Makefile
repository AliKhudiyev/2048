
GCC		= g++
FLAGS	= --std=c++17 -Wextra
LINK	= $(shell pkg-config --cflags --libs sdl2)

SRC		= $(wildcard src/*.cpp)

2048: 
	$(GCC) $(FLAGS) -I\lib $(SRC) $(LINK) -o $@

info:
	@echo $(SRC)

clean: 
	$(RM) 2048