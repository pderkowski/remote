CXX=g++
RM=rm -rf
LDLIBS=-lboost_system -lboost_thread -lpthread

CLIENT_SRCS=$(shell find src/client -type f -name '*.cpp')
CLIENT_OBJS=$(subst .cpp,.o,$(CLIENT_SRCS))

SERVER_SRCS=$(shell find src/server -type f -name '*.cpp')
SERVER_OBJS=$(subst .cpp,.o,$(SERVER_SRCS))

CLIENT_EXEC=$(BIN)/client
SERVER_EXEC=$(BIN)/server

BIN=bin
MKDIR_P=mkdir -p

all: mkdir client server

mkdir: $(BIN)

$(BIN):
	$(MKDIR_P) $(BIN)

client: $(CLIENT_EXEC)

$(CLIENT_EXEC): $(CLIENT_OBJS)
	$(CXX) -o $(CLIENT_EXEC) $(CLIENT_OBJS) $(LDLIBS)

server: $(SERVER_EXEC)

$(SERVER_EXEC): $(SERVER_OBJS)
	$(CXX) -o $(SERVER_EXEC) $(SERVER_OBJS) $(LDLIBS)

%.o: %.cpp
	$(CXX) -c $? -o $@


clean:
	$(RM) $(CLIENT_OBJS) $(SERVER_OBJS)

dist-clean: clean
	$(RM) $(BIN)