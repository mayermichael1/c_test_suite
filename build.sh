#!/bin/bash

DEBUG="-g -O0"

gcc $DEBUG -o -fpic -shared -o out/example.so src/example.cpp 
bear -- gcc $DEBUG -o out/test test.cpp

