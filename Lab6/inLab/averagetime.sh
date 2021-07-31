#!/bin/bash
#Justin Liu, jl8wf    Date: 10/11/2020    Filename: averagetime.sh

read -r -p "Type in the dictionary file. " dictionary
read -r -p "Type in the grid file. " grid

echo "$dictionary"
echo "$grid"

RUNNING_TIME1=`./a.out ${dictionary} ${grid} | tail -1`

RUNNING_TIME2=`./a.out ${dictionary} ${grid} | tail -1`

RUNNING_TIME3=`./a.out ${dictionary} ${grid} | tail -1`

RUNNING_TIME4=`./a.out ${dictionary} ${grid} | tail -1`

RUNNING_TIME5=`./a.out ${dictionary} ${grid} | tail -1`

echo $((( ${RUNNING_TIME1}+${RUNNING_TIME2}+${RUNNING_TIME3}+${RUNNING_TIME4}+${RUNNING_TIME5})/5 ))
