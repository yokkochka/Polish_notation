CC = gcc
CFLAGS = -Wall -Wextra -Werror -std=c11 

SRC = graph.c functions_step_3.c functions_step_2.c functions_step_1.c functions_step_4.c
BUILD_PATH = ./build

all : start
	$(CC) $(CFLAGS) $(SRC) -o $(BUILD_PATH)/graph -lm

start :
	mkdir -p ./build

format :
	clang-format -n *.c *.h
	clang-format -i *.c *.h

cppcheck :
	cppcheck --enable=all --suppress=missingIncludeSystem *.c

clean : 
	rm ./build/*
	rm -rf ./build