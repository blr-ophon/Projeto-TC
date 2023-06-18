CC = g++
OPT = -O0
CFLAGS = -g -Wall -Wextra -pedantic $(OPT)

INCLUDES= -I./include 

SRC_DIR := ./src
BUILD_DIR := ./build
BIN_DIR := ./bin

CFILES := $(shell find $(SRC_DIR) -name '*.cpp')
OBJECTS := $(CFILES:$(SRC_DIR)/%.cpp=$(BUILD_DIR)/%.o)
EXEC := ${BIN_DIR}/exec

${EXEC}: ${OBJECTS} 
	mkdir -p $(dir $@)
	$(CC) ${CFLAGS} ${INCLUDES} ${OBJECTS} -o $@ 

${BUILD_DIR}/%.o: ${SRC_DIR}/%.cpp
	mkdir -p $(dir $@)
	$(CC) ${CFLAGS} ${INCLUDES} -c $< -o $@ 

clean:
	rm -rf ${BUILD_DIR} 
	rm -rf ${BIN_DIR} 
	rm *.txt

run: ${EXEC}
	$^ 

debug: ${EXEC}
	cgdb --args $^ 
