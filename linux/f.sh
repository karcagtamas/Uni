#!/usr/bin/bash

ls ./ -la

export teszt=false

echo "Darab: $#"

echo "Fájl: $0"

if [ $# -gt 0 ]
then 
	echo "Van arg"
	if [ -r $1 ]
	then
		tartalom=$(cat $1)
		echo $tartalom
	elif [ -f $1 ]
	then
		echo 'No perm'
	else
		echo 'No exist'
	fi
else
	echo "Nincs arg"
fi
