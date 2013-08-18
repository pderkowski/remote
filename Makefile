CXX=g++

SRC_DIR=src
EXEC_DIR=bin
INCLUDE_DIRS=$(shell pwd)/$(SRC_DIR)

CFLAGS=$(foreach dir, $(INCLUDE_DIRS), -I$(dir)) -c
LDLIBS=-lboost_system -lboost_thread -lpthread

CLIENT_SRCS=$(shell find $(SRC_DIR)/client -type f -name '*.cpp')
CLIENT_OBJS=$(subst .cpp,.o,$(CLIENT_SRCS))

SERVER_SRCS=$(shell find $(SRC_DIR)/server -type f -name '*.cpp')
SERVER_OBJS=$(subst .cpp,.o,$(SERVER_SRCS))

MKDIR_P=mkdir -p
RM=rm -rf

.PHONY: all clean dist-clean

all: mkdir client server

client: $(CLIENT_OBJS)
server: $(SERVER_OBJS)
client server:
	$(CXX) -o $(EXEC_DIR)/$@ $? $(LDLIBS)

mkdir: $(EXEC_DIR)

clean:
	$(RM) $(CLIENT_OBJS) $(SERVER_OBJS)

dist-clean: clean
	$(RM) $(EXEC_DIR)

%.o: %.cpp
	$(CXX) $(CFLAGS) $? -o $@

$(EXEC_DIR):
	$(MKDIR_P) $(EXEC_DIR)

