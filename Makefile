CFLAGS=-Wall -g -std=c++11 -stdlib=libc++
CC=clang++

SRCDIR = src
SRCS = main.cpp alole.cpp buffer.cpp console.cpp data.cpp input.cpp

OBJDIR = obj
OBJS=$(addprefix $(OBJDIR)/,$(patsubst %.cpp,%.o,$(SRCS)))
EXECUTABLE=alole

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $@

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c -o $@ $<

$(OBJDIR)/input.o: $(SRCDIR)/input.cpp
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -f $(EXECUTABLE) $(OBJDIR)/*

.PHONY: all clean obj/input.o
