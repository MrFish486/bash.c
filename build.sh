#!/bin/bash
mkdir bin
gcc -o 'bin/ls' 'ls.c' -lm
gcc -o 'bin/rm' 'rm.c'
gcc -o 'bin/cat' 'cat.c'
