#!/bin/bash
# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    set_tests.sh                                       :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abarthel <abarthel@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/07 18:24:49 by abarthel          #+#    #+#              #
#    Updated: 2019/02/07 18:24:49 by abarthel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# File name where the tests are written
TEST_FILE="tests.txt"



### REPOSITORY, MAIN, MAKEFILE, LAUNCHER.H ###
# Check if repository exists
declare printf_tests_repo="../printf_tests/"
# Clean rule for repository, set to default (state before running script)
if test $1; then
	if [ $1 = "clean" ]; then
		rm -rf $printf_tests_repo
		rm launchers.h
		cp ./archive/launchers.h ./
		rm main.c
		cp ./archive/main.c ./
		exit
	fi
fi
# Creates repo
if [ ! -d $printf_tests_repo ]
then
	mkdir "$printf_tests_repo"
	#echo $printf_tests_repo
fi
# Check if main.c exists
#declare main=$printf_tests_repo"main.c"
#if [ ! -f $main ]
#then
#	cp -f main.c $printf_tests_repo
#	#echo "cp main.c $printf_tests_repo"
#fi
# Check if Makefile exists
declare Makefile=$printf_tests_repo"Makefile"
if [ ! -f $Makefile ]
then
	cp -f Makefile $printf_tests_repo
	#echo "cp Makefile $printf_tests_repo"
fi
# Check if launcher.h exists
#declare launcherH=$printf_tests_repo"launchers.h"
#if [ ! -f $launcherH ]
#then
#	cp -f launchers.h $printf_tests_repo
#	#echo "cp launchers.h $printf_tests_repo"
#fi



### CREATE TESTS ###
declare -a FOLDER=$(cat $TEST_FILE | cut -d ";" -f1 | sort | uniq)
# Creates a repository for each category
for dir in $FOLDER
do
	if [ ! -d $printf_tests_repo$dir ]
	then
		mkdir "$printf_tests_repo$dir"
		#echo "$printf_tests_repo$dir"
	fi
done
# Fill main.c && launcher.h
for dir in $FOLDER
do
	echo ""
	# Add prototypes to launchers.h
	declare prototype="void  $dir""_launcher(t_err_info *info);"
	sed -e '/PROTOTYPES/a\'$'\n'"$prototype" launchers.h > launchers.bak && cp -f launchers.bak launchers.h && rm launchers.bak
	# Add functions call to main.c
	declare functionscall="$dir""_launcher(info);"
	sed -e '/FUNCTIONS/a\'$'\n'"\	$functionscall" main.c > main.bak && cp -f main.bak main.c && rm main.bak
	echo $printf_tests_repo
	echo "00_$dir""_launcher.c" #to copy 00_FOLDER_launcher.c
	declare -a TYPE=$(cat $TEST_FILE | grep $dir | cut -d ";" -f2)
	declare -a NAME=$(cat $TEST_FILE | grep $dir | cut -d ";" -f3)
	IFS=$' '
	set -f
	index=0
	for i in $TYPE
	do
#		echo ${TYPE[$index]}
#		echo ${NAME[$index]}
		echo $dir${TYPE[$index]}${NAME[$index]}
	done
done

# Copies the launchers.h to the test repository
cp launchers.h $printf_tests_repo
cp main.c $printf_tests_repo

#For putting tests:
#sed -i.bak "s/XXX/\"Hello dude%d\", 42/g" KK_TYPE_NAME.C && rm *.bak

### Format: FOLDER;TYPE;NAME;ARG ###

#echo "OOOOOOOOOOOOOOOOOOOOOOOOOOO"

#FOLDERS_TEST=()
#IFS=$'\n'       # make newlines the only separator
#set -f          # disable globbing
#i=0
#for q in $(cat < "tests.txt"); do
#	FOLDERS_TEST[$i]+="$(echo $q | cut -d ';' -f1)"
#	if [ !$(cd $printf_tests_repo/${FOLDERS_TEST[$i]} 2>/dev/null) ]
#	then
#		echo "$printf_tests_repo${FOLDERS_TEST[$i]}"
#	fi
##	echo "${FOLDERS_TEST[$i]}"
#	((i++))
#done



