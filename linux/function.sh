#!/usr/bin/bash

# functions
function kilep {
	exit
}

function hello {
	echo szia
	echo $1
}

hello alma
hello alma3

#aritmentica
echo $((1+2))
echo $((2**4))
echo $((20/3))
echo $((20%3))
x=5
echo $((x++))
echo $((x++))

# bc
echo "10+3.3" | bc
echo "10^2" | bc

# values
echo "var=10;var" | bc
echo "var=10;var^=2;var" | bc
y=`echo "var=500;var%=7;var" | bc`
echo $y

# increment decrement
echo "var=10;++var" | bc
echo "var=10;var++" | bc
echo "var=10;--var" | bc
echo "var=10;var--" | bc

# realational operators: true - 1, false - 0
echo "10>5" | bc
echo "1==2" | bc

# logical operators: &&, ||, !
# a number is true if is it non-zero
echo "10 && 5" | bc
echo "0 || 0" | bc
echo "! 0" | bc

# functions
# s(x) -> sine, c(x) -> cosine (in radian)
# a(x) -> arctangent (in radian)
# l(x) -> natural logarithm
# e(x) -> exponential function based on e
# sqrt(x) -> square root
# length(x) -> length of the number characters
# read() -> reads the number of the standard input
# scale(expression)
# last(), ibase, obase (ibase - binary or something else to decimal, obase - from decimal to sometinhg else)

pi=`echo "h=10;4*a(1)" | bc -l`

# conditional
echo 'n=8;m=10;if(n>m) print "n bigger" else print "m bigger"' | bc -l

# loops

echo "for(i=1; i<=5; i++){i;}" | bc
echo "i=1;while(i<=5){i;i+=1}" | bc

kilep
echo valami
