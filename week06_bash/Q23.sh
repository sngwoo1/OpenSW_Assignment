#!/bin/bash

factorial(){

	NUM_1="$1"
	N="$1"
	result=1

	while [ $N -gt 0 ]; do
		result=$((result * N))
		N=$((N-1))
	done

	echo "Factorial of $1 is $result"
}

read -p "Enter a number: " NUM
factorial $NUM
