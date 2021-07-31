#!/bin/bash
#Justin Liu, jl8wf    Date: 10/11/2020    Filename: averagetime.sh

read -r -p "enter the exponent for count.cpp " input

MAX=5
declare -i total
total=0

if [[ "$input" == "quit" ]]; then
    exit 0
else
    for i in $(seq 1 $MAX) ; do
	echo Running iteration ${i}...
	total+=`./a.out ${input} | tail -1`
	echo ${total}
	echo time taken: `./a.out ${input} | tail -1` ms
    done
fi
echo 5 iterations took ${total} ms
echo Average time was $(( total / 5 )) ms
