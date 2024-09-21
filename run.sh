#!/bin/bash


qmake
make
make clean
rm .qmake.stash Makefile
./AlgebraXpert 
rm AlgebraXpert