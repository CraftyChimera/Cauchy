#!/bin/bash
bison -d parse.y
flex cauchylex.l 
bison parse.y
gcc parse.tab.c -o program
./program
