CC = g++
BUILD_DIR = build
SRC_DIR = src
INCLUDE_DIR = include
INCLUDE = -I$(INCLUDE_DIR)
CFLAGS = -std=c++11 -Wall -Werror $(INCLUDE)
EXECUTABLE_FILE = ThreadLibrary.out

OBJECTS = \
	$(BUILD_DIR)/KernelThread.o\
	$(BUILD_DIR)/CommandHandler.o\
	$(BUILD_DIR)/KernelThreadQueue.o\
	$(BUILD_DIR)/Process.o\
	$(BUILD_DIR)/ThreadLibrary.o\
	$(BUILD_DIR)/UserThread.o\
	$(BUILD_DIR)/Main.o\

KernelThread = \
	$(SRC_DIR)/KernelThread.cpp\
	$(INCLUDE_DIR)/KernelThread.h\
	$(INCLUDE_DIR)/KernelThread-inl.h\

CommandHandler = \
	$(SRC_DIR)/CommandHandler.cpp\
	$(INCLUDE_DIR)/CommandHandler.h\
	$(INCLUDE_DIR)/CommandHandler-inl.h\

KernelThreadQueue = \
	$(SRC_DIR)/KernelThreadQueue.cpp\
	$(INCLUDE_DIR)/KernelThreadQueue.h\
	$(INCLUDE_DIR)/KernelThreadQueue-inl.h\

Process = \
	$(SRC_DIR)/Process.cpp\
	$(INCLUDE_DIR)/Process.h\
	$(INCLUDE_DIR)/Process-inl.h\

ThreadLibrary = \
	$(SRC_DIR)/ThreadLibrary.cpp\
	$(INCLUDE_DIR)/ThreadLibrary.h\
	$(INCLUDE_DIR)/ThreadLibrary-inl.h\

UserThread = \
	$(SRC_DIR)/UserThread.cpp\
	$(INCLUDE_DIR)/UserThread.h\
	$(INCLUDE_DIR)/UserThread-inl.h\

Main = \
	$(SRC_DIR)/Main.cpp\

all: $(BUILD_DIR) $(EXECUTABLE_FILE)

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

$(BUILD_DIR)/KernelThread.o: $(KernelThread)
	$(CC) $(CFLAGS) -c $(SRC_DIR)/KernelThread.cpp -o $(BUILD_DIR)/KernelThread.o

$(BUILD_DIR)/CommandHandler.o: $(CommandHandler) 
	$(CC) $(CFLAGS) -c $(SRC_DIR)/CommandHandler.cpp -o $(BUILD_DIR)/CommandHandler.o

$(BUILD_DIR)/KernelThreadQueue.o: $(KernelThreadQueue)
	$(CC) $(CFLAGS) -c $(SRC_DIR)/KernelThreadQueue.cpp -o $(BUILD_DIR)/KernelThreadQueue.o

$(BUILD_DIR)/Process.o: $(Process)
	$(CC) $(CFLAGS) -c $(SRC_DIR)/Process.cpp -o $(BUILD_DIR)/Process.o

$(BUILD_DIR)/ThreadLibrary.o: $(ThreadLibrary)
	$(CC) $(CFLAGS) -c $(SRC_DIR)/ThreadLibrary.cpp -o $(BUILD_DIR)/ThreadLibrary.o

$(BUILD_DIR)/UserThread.o: $(UserThread)
	$(CC) $(CFLAGS) -c $(SRC_DIR)/UserThread.cpp -o $(BUILD_DIR)/UserThread.o

$(BUILD_DIR)/Main.o: $(Main)
	$(CC) $(CFLAGS) -c $(SRC_DIR)/Main.cpp -o $(BUILD_DIR)/Main.o

$(EXECUTABLE_FILE): $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o $(EXECUTABLE_FILE)

.PHONY: clean
clean:
	rm -rf $(BUILD_DIR) *.o *.out