#!/usr/bin/bash
export extensionPath="$HOME/code-stats/extensions.txt"
export ignorePath="$HOME/code-stats/ignores.txt"
export ignoreTempPath="$HOME/code-stats/ignore-temp.txt"
export mainHome="$HOME/code-stats/"
export filesPath="$HOME/code-stats/files.txt"
export logPath="$HOME/code-stats/log.dat"
title()
{
	tput setaf 4
	echo $1
	tput sgr0
}

value()
{
	echo -n "$1"
	tput setaf 3
	echo -n $2
	tput sgr0
	echo "$3"
}

success()
{
	tput setaf 2
	echo $1
	tput sgr0
}

error()
{
	tput setaf 1
	echo $1
	echo "ERROR - `date` - $1" >> $logPath
	tput sgr0
}

info()
{
	tput setaf 5
	echo "$1"
	tput sgr0
}

list_extensions()
{
	# Read in extension
	readarray list < $extensionPath

	# Read file paths to all extension
	title "Extensions:"
	for e in ${list[@]};do
		echo "- ${e}"
	done
}

list_ignores()
{
	title "Ignored folder names:"
	while read line; do
		echo "- ${line}"
	done < $ignorePath
}

help()
{
	title "Help"
	info "help -"
	echo "	Show program options"
	echo
	info "extensions -"
	echo "	List of commands for extensions"
	echo
	info "	add <name of extension> -"
	echo "		Add extension with this name"
	echo
	info "	delete <name of extension> -"
	echo "		Delete extension with this name"
	echo
	info "	list -"
	echo "		Lists all added extension"
	echo
	info "	clear -"
	echo "		Clear list of extensions"
	echo
	info "ignores -"
	echo "	List of commands for ignores"
	echo
	info "	add <name of folder> -"
	echo "		Add ignore expression with this name"
	echo
	info "	delete <name of folder> -"
	echo "		Delete ignore expression with this name"
	echo
	info "	list -"
	echo "		Lists all added ignored folder"
	echo
	info "	clear -"
	echo "		Clear list of ignored folders"
	echo
	info "<path to folder> - "
	echo "	Calculate statistics for each file extension and for the given poject folder"
	echo
	info "	export <path to destination folder> - "
	echo "		Export the stats to a file"
	echo
}

list_extension_commands()
{
	title "Extensions"
	info "add <name of extension> -"
	echo "	Add extension with this name"
	echo
	info "delete <name of extension> -"
	echo "	Delete extension with this name"
	echo
	info "list -"
	echo "	Lists all added extension"
	echo
	info "clear -"
	echo "	Clear list of extensions"
	echo
}

list_ignore_commands()
{
	title "Ignores"
	info "add <name of folder> -"
	echo "	Add ignore expression with this name"
	echo
	info "delete <name of folder> -"
	echo "	Delete ignore expression with this name"
	echo
	info "list -"
	echo "	Lists all added ignored folder"
	echo
	info "clear -"
	echo "	Clear list of ignored folders"
	echo
}

find_files()
{
	> $filesPath
	# Read file paths to all extension
	readarray ignoreList < $ignorePath
	ignoreScript=""
	for i in ${ignoreList[@]};do
		ignoreScript="$ignoreScript! -path */$i/* "
	done

	for e in ${list[@]};do
		info "READ - ${e}"
		if [ -f "$mainHome$e.txt" ]
		then
			rm $mainHome$e.txt
		fi
		$(find $1 -type f -name "*.${e}" ${ignoreScript} | tee ${mainHome}${e}.txt >> $filesPath)
	done
}

add_extension()
{
	if [ ! "$1" == "" ]
	then
		re="[[:space:]]+"
		if [[ "$1" =~ $re ]]
		then
			error "Invalid value - invalid value for extension adding"
			exit 1
		fi
		f=false
		# Read in extension
		readarray list < $extensionPath

		# Read file paths to all extension
		for e in ${list[@]};do
			if [ "$e" == "$1" ]
			then
				f=true
			fi
		done

		if [ "$f" == false ]
		then
			echo "$1" >> $extensionPath
			info "Value successfully added"
		else
			error "Value '$1' already exists in the extension list"
			exit 1
		fi
	else
		error "Invalid operation - invalid value parameter for extension adding"
		exit 1
	fi
}

add_ignore()
{
	if [ ! "$1" == "" ]
	then
		f=false

		# Read file paths to all extension
		while read line; do
			if [ "$line" == "$1" ]
			then
				f=true
			fi
		done < $ignorePath

		if [ "$f" == false ]
		then
			echo "$1" >> $ignorePath
			info "Value successfully added"
		else
			error "Value '$1' already exists in the ignore list"
			exit 1
		fi
	else
		error "Invalid operation - invalid value parameter for ignore adding"
		exit 1
	fi
}

delete_extension()
{
	if [ ! "$1" == "" ]
	then
		f=false
		# Read in extension
		readarray list < $extensionPath

		# Read file paths to all extension
		for e in ${list[@]};do
			if [ "$e" == "$1" ]
			then
				f=true
			fi
		done

		if [ "$f" == false ]
		then
			error "Value '$1' does not exist in the extension list"
			exit 1
		else
			echo > $extensionPath
			for e in ${list[@]};do
				if [ ! "$e" == "$1" ]
				then
					echo "$e" >> $extensionPath
				fi
			done 
			info "Value successfully deleted"
		fi
	else
		error "Invalid operation - invalid value parameter for extension delete"
		exit 1
	fi
}

delete_ignore()
{
	if [ ! "$1" == "" ]
	then
		f=false

		# Read file paths to all ignore
		while read line; do
			if [ "$line" == "$1" ]
			then
				f=true
			fi
		done < $ignorePath

		if [ "$f" == false ]
		then
			error "Value '$1' does not exist in the ignore list"
			exit 1
		else
			while read line; do
				if [ ! "$line" == "$1" ]
				then
					echo "$line" >> $ignoreTempPath
				fi
			done < $ignorePath
			cat $ignoreTempPath > $ignorePath
			rm $ignoreTempPath
			info "Value successfully deleted"
			exit 1
		fi
	else
		error "Invalid operation - invalid value parameter for ignore deleteing"
		exit 1
	fi
}

clear_extensions()
{
	> $extensionPath
}

clear_ignores()
{
	> $ignorePath
}

echo 'Hi!'

if [ $# -gt 0 ]
then
	case $1 in
		extensions)
			case $2 in
				list)
					list_extensions
				;;
				add)
					add_extension "$3"
				;;
				delete)
					delete_extension "$3"
				;;
				clear)
					clear_extensions
				;;
				*)
					list_extension_commands
				;;
			esac
		;;
		ignores)
			case $2 in
				list)
					list_ignores
				;;
				add)
					add_ignore "$3"
				;;
				delete)
					delete_ignore "$3"
				;;
				clear)
					clear_ignores
				;;
				*)
					list_ignore_commands
				;;
			esac
		;;
		help)
			help
		;;
		*)
			if [ -d $1 ]
			then
				# Read in extension
				readarray list < $extensionPath

				paramCount=0
				lastWas=""
				exportDir=""

				# Read params for code file checking
				for param in "$@"
				do
					if [ $paramCount -ne 0 ] 
					then
						case $param in
							export)
								if [ $(( $paramCount + 1 )) -eq $# ]
								then
									error "Invalid operation - event will not have any value"
									exit 1
								else
									lastWas=$param
								fi
								;;
							*)
								case $lastWas in
									export)
										if [[ $exportDir == "" ]]
										then
											if [ -d $param ]
											then
												exportDir=$param
											else
												error "Export path does not exists"
												exit 1
											fi
										else
											error "Invalid operation - more export path than one"
											exit 1
										fi
										;;
									*)
										error "Invalid operation - not valid event"
										exit 1
										;;
								esac
								;;
						esac
									
					fi
					let "paramCount++"
				done


				# Create export file, if export is enabled
				if [ ! "$exportDir" == "" ]
				then
					lastCharIndex=$((${#exportDir}-1))
					lastChar="${exportDir:$lastCharIndex:1}"
					if [ "$lastChar" == "/" ]
					then
						exportDir="${exportDir}export-`date +%F`-`date +%T`.txt"
					else
						exportDir="${exportDir}/export-`date +%F`-`date +%T`.txt"
					fi

					echo "Programming file statistics: `date`" > $exportDir
					echo >> $exportDir
				fi

				# Find files with the set extensions
				find_files $1

				while read file; do
					
				done < $filesPath

				# Stats for all files
				readarray files < $filesPath
				fileCount=${#files[@]}
				allLineSum=0
				allCharSum=0

				# Stats for each file types
				echo
				echo "Specific file types:"
				for e in ${list[@]};do
					
					readarray subFiles < $mainHome$e.txt
					length=${#subFiles[@]}
					title $e
					if [ ! "$exportDir" == "" ]
					then
						echo $e >> $exportDir
					fi
					if [ $length -gt 0 ]
					then
						
						percent=$(bc <<< "scale=2;$length*100/$fileCount")
						header=$(echo $percent | head -c 1)
						value "- Count: " $length
						if [ "$header" == "." ]
						then	
							value "- Percent: 0" "$percent%"
						else 
							value "- Percent: " "$percent%"
						fi
						
						
						## Calculate character and line stats
						charSum=0
						lineSum=0
						for file in ${subFiles[@]};do
							currentChar=$(cat $file | wc -c)
							charSum=$((charSum+currentChar))
							currentLine=$(cat $file | wc -l)
							lineSum=$((lineSum+currentLine))
						done
						value "- All characters: " $charSum
						charAvg=$(bc <<< "scale=2;$charSum/$length")
						value "- Character Avg/file: " $charAvg
						value "- All lines: " $lineSum
						lineAvg=$(bc <<< "scale=2;$lineSum/$length")
						value "- Line Avg/file: " $lineAvg
						echo

						allLineSum=$((allLineSum+lineSum))
						allCharSum=$((allCharSum+charSum))

						if [ ! "$exportDir" == "" ]
						then
							echo "- Count: " $length >> $exportDir
							if [ "$header" == "." ]
							then	
								echo "- Percent: 0" "$percent%" >> $exportDir
							else 
								echo "- Percent: " "$percent%" >> $exportDir
							fi
							echo "- All characters: " $charSum >> $exportDir
							echo "- Character Avg/file: " $charAvg >> $exportDir
							echo "- All lines: " $lineSum >> $exportDir
							echo "- Line Avg/file: " $lineAvg >> $exportDir
							echo >> $exportDir
						fi
					else
						info "- There are nothing from this file type in the selected folder"
						echo
						if [ ! "$exportDir" == "" ]
						then
							echo "- There are nothing from this file type in the selected folder" >> $exportDir
							echo >> $exportDir
						fi
					fi
					rm $mainHome$e.txt
				done

				# All files
				title "Project Summary"
				value "Your project has " $fileCount " files"
				value "Your project has " $allLineSum " lines"
				value "Your project has " $allCharSum " characters"

				allLineAvg=$(bc <<< "scale=2;$allLineSum/$fileCount")
				value "Your project has " $allLineAvg " line Avg / file"
				allCharAvg=$(bc <<< "scale=2;$allCharSum/$fileCount")
				value "Your project has " $allCharAvg " character Avg / file"

				if [ ! "$exportDir" == "" ]
				then
					echo "Project Summary" >> $exportDir
					echo "Count of files: " $fileCount >> $exportDir
					echo "Count of lines: " $allLineSum >> $exportDir
					echo "Count of characters: " $allCharSum >> $exportDir
					echo "Avg lines / files: " $allLineAvg >> $exportDir
					echo "Avg characters / files: " $allCharAvg >> $exportDir
					echo >> $exportDir
				fi

				rm $filesPath
			else
				error "Invalid directory path"
				exit 1
			fi
		;;
	esac
else
	error "You does not have enough parameter"
	exit 1
fi

