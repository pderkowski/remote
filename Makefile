CXX=g++
RM=rm -f
LDLIBS=-lboost_system -lboost_thread -lpthread

SRCS=$(shell find src/ -type f -name '*.cpp')
OBJS=$(subst .cc,.o,$(SRCS))

all: remote

remote: $(OBJS)
	g++ -o remote $(OBJS) $(LDLIBS) 

tool.o: tool.cc support.hh

server.o: server.cpp

clean:
	$(RM) $(OBJS)

dist-clean: clean
	$(RM) remote