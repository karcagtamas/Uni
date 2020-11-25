#!/usr/bin/bash


# Create variables
a=10

# $0 - started program
# $# - count of paramters
# $1-n - paramters

# -gt -> greater than (number)
# lt -> less than (number)
# ! -> not (space is important)
# -n STRING -> length of string is not empty
# -z STRING -> length of string is empty

# ==, = -> equal (string)
# != -> not equal (string)
# -eq -> equal (number)

# -d FILE -> file exists and is a driectory
# -e FILE -> exists
# -f FILE -> is a file
# -r FILE -> exists and has read permission
# -s FILE -> exists and size is not empty
# -w FILE -> exists and has write permission
# -x FILE -> exists and has execute permission
# -L FILE -> is symbolic link

# [ ] normal - spaces are important
# [[ ]] - with '==' at right side, you does not need to "" characters -> [[ "$gyumi" == *[bB]an* ]] 
# && and ||
# With (( )) I can use ==, <=, >=
if (( $# == 1 ))
then
	if (( $1 % 2 == 0))
	then
		echo 'paros'
	else
		echo 'paratlan'
	fi

	if (( $1 > 5 && $1 < 10))
	then
		echo 'yap'
	else 
		echo 'nopp'
	fi 
else
	echo 'not valid'	
fi


# For in gave number list
for i in 1 2 3 4 5
do
	echo "Hello $i"
done

for i in 1 3 9 11
do
	echo $i
done

# Generate number hash
for i in {1..10}
do
	echo $i
done

start=1
end=10
# First echo - not user variables
echo {$start..$end}

# With eval, it will evaulate the variables, after it do the task
eval echo {$start..$end}

for i in egy ketto harom
do 
	echo $i

	# break - break out of the for iteration
	# continue - break out of the current iteration and continue with the next
done

# C lang
for ((i=1;i<5;i++)); do echo $i; done;

# infinite loop - foo ((;;)); do echo $u; done

# while loop
x=1
while [ $x -le 5 ]
do
	echo "Hi: $x"
	x=$(( $x + 1 ))
done

# true = ':'

# let = (( )) for arithmetic operations
counter=20
until [ $counter -lt 10 ]
do
	echo counter $counter
	# -= +=
	let counter-=1
done


