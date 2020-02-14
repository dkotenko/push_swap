#!/bin/bash

gcc -o random_number random_number.c libft/libft.a &&
case $# in
0)
echo "No arguments supplied. Type 'bash get_range.sh --help' for information"
;;

1)
	if [ $1 == '--help' ];
	then
		echo "This script generates a range of non-duplicated INTs"
		echo "Usage: bash get_range.sh size [lower bound] [upper bound]"
		echo "Hint: you can assign the range to variable: 'ARG=\$(bash get_range.sh size [lower bound] [upper bound])'"
		echo "Arguments:"
		echo -e "\tsize - mandatory"
		echo -e "\tlower - optional. Lower without upper sets script to generate numbers in range (-lower, lower)"
		echo -e "\tupper - optional"
	else		
		echo $ARG
	fi
;;

2)
	setenv ARG="$(./random_number $1 $2)"
	echo $ARG
;;

3)
	setenv ARG="$(./random_number $1 $2 $3)"
;;
esac	

