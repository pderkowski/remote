CPP=g++

SRC_DIR=src
EXEC_DIR=bin
INCLUDE_DIRS=$(shell pwd)/$(SRC_DIR)

CPPFLAGS=$(foreach dir, $(INCLUDE_DIRS), -I$(dir)) -std=c++11 -c -MD -MP
LDLIBS=-lboost_system -lboost_thread -lpthread
WARNINGS=-Wall -Wextra -pedantic -Wshadow

CLIENT_DIR=$(SRC_DIR)/client
CLIENT_SRCS=$(shell find $(CLIENT_DIR) -type f -name '*.cpp')
CLIENT_OBJS=$(subst .cpp,.o,$(CLIENT_SRCS))

SERVER_DIR=$(SRC_DIR)/server
SERVER_SRCS=$(shell find $(SERVER_DIR) -type f -name '*.cpp')
SERVER_OBJS=$(subst .cpp,.o,$(SERVER_SRCS))

COMMON_DIR=$(SRC_DIR)/common
COMMON_SRCS=$(shell find $(COMMON_DIR) -type f -name '*.cpp')
COMMON_OBJS=$(subst .cpp,.o,$(COMMON_SRCS))

DEPS=$(shell find . -type f -name '*.d')

MKDIR_P=mkdir -p
RM=rm -rf

.PHONY: all clean distclean

all: mkdir server client 

client: $(CLIENT_OBJS) $(COMMON_OBJS)
	$(CPP) -o $(EXEC_DIR)/$@ $? $(LDLIBS)

server: $(SERVER_OBJS) $(COMMON_OBJS)
	$(CPP) -o $(EXEC_DIR)/$@ $? $(LDLIBS)

mkdir: $(EXEC_DIR)

clean:
	$(RM) $(CLIENT_OBJS) $(SERVER_OBJS) $(DEPS)

distclean: clean
	$(RM) $(EXEC_DIR)

%.o: %.cpp
	$(CPP) $(CPPFLAGS) $(WARNINGS) $< -o $@

$(EXEC_DIR):
	$(MKDIR_P) $(EXEC_DIR)

-include $(DEPS)