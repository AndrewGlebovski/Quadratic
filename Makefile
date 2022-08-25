# Путь к компилятору
COMPILER=g++

# Флаги компиляции
FLAGS=-Wshadow -Winit-self -Wredundant-decls -Wcast-align -Wundef -Wfloat-equal -Winline -Wunreachable-code -Wmissing-declarations -Wmissing-include-dirs -Wswitch-enum -Wswitch-default -Weffc++ -Wmain -Wextra -Wall -g -pipe -fexceptions -Wcast-qual -Wconversion -Wctor-dtor-privacy -Wempty-body -Wformat-security -Wformat=2 -Wignored-qualifiers -Wlogical-op -Wmissing-field-initializers -Wnon-virtual-dtor -Woverloaded-virtual -Wpointer-arith -Wsign-promo -Wstack-usage=8192 -Wstrict-aliasing -Wstrict-null-sentinel -Wtype-limits -Wwrite-strings -D_DEBUG -D_EJUDGE_CLIENT_

# Папка с файлами типа .o
BIN_DIR=bin

all: run


run: main io solve test
	$(COMPILER) $(BIN_DIR)/main.o $(BIN_DIR)/io.o $(BIN_DIR)/solve.o $(BIN_DIR)/test.o -o run.exe

main: main.cpp quad_solver.hpp
	$(COMPILER) $(FLAGS) -c main.cpp -o $(BIN_DIR)/main.o

io: io.cpp quad_solver.hpp
	$(COMPILER) $(FLAGS) -c io.cpp -o $(BIN_DIR)/io.o

solve: solve.cpp quad_solver.hpp
	$(COMPILER) $(FLAGS) -c solve.cpp -o $(BIN_DIR)/solve.o

test: test.cpp quad_solver.hpp
	$(COMPILER) $(FLAGS) -c test.cpp -o $(BIN_DIR)/test.o
