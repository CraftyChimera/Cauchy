#!/bin/bash
bison -d parse.y
flex cauchylex.l 
bison parse.y
gcc -o program parse.tab.c intmdt_code.c
./program
