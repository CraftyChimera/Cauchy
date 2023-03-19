#!/bin/bash

lex cauchylex.l
mv lex.yy.c lex.yy.cpp
g++ lex.yy.cpp -o lex
./lex
