ALLC     := $(wildcard *.c)
ALLBIN   := $(patsubst %.c,bin/%,$(ALLC))

bin/% : %.c
	mkdir -p bin
	gcc -o $@ $^ -lm

all : $(ALLBIN)
