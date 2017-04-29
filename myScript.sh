#!/bin/bash

#argument 1 will be the student file

COMPILER=g++
FILENAME=$1
EXECUTABLE=studentExec
FLAGS=-o

rm $EXECTUABLE
$COMPILER $FILENAME $FLAGS $EXECUTABLE

FILENAME=input
EXTENSION=.txt

STUDENT=student

AUTOGRADER=autograder
SOLUTION=output

for i in {1..10}
do
	./$EXECUTABLE < ${FILENAME}${i}${EXTENSION} > ${STUDENT}${i}${EXTENSION}
	./$AUTOGRADER $i
done

