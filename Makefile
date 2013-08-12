CXX=g++
RM=rm -f

SRCS=$(shell find src/ -type f -name '*.cpp')
OBJS=$(subst .cc,.o,$(SRCS))

all: remote

remote: $(OBJS)
	g++ -o remote $(OBJS)

clean:
	$(RM) $(OBJS)

dist-clean: clean
	$(RM) remote