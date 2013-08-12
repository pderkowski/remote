CXX=g++
RM=rm -f
CPPFLAGS=-g $(shell root-config --cflags)
LDFLAGS=-g $(shell root-config --ldflags)
LDLIBS=$(shell root-config --libs)

SRCS=$(shell find src/ -type f -name '*.cpp')
OBJS=$(subst .cc,.o,$(SRCS))

all: remote

remote: $(OBJS)
    g++ $(LDFLAGS) -o remote $(OBJS) $(LDLIBS) 

clean:
    $(RM) $(OBJS)

dist-clean: clean
    $(RM) remote