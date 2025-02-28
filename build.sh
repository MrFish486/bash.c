#!/bin/bash
mkdir bin
gcc -o 'bin/ls' 'ls.c' -lm
gcc -o 'bin/rm' 'rm.c'
gcc -o 'bin/cat' 'cat.c'
gcc -o 'bin/mv' 'mv.c'
gcc -o 'bin/cp' 'cp.c'
gcc -o 'bin/date' 'date.c'
