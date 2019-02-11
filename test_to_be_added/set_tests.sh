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

TEST_FILE="tests.txt"

declare printf_tests_repo="../printf_tests/"
if [ ! -d $printf_tests_repo ]
then
#	mkdir "$printf_tests_repo"
	echo $printf_tests_repo
fi
declare -a FOLDER=$(cat $TEST_FILE | cut -d ";" -f1 | sort | uniq)
for dir in $FOLDER
do
	if [ ! -d $printf_tests_repo$dir ]
	then
#		mkdir "$printf_tests_repo$dir"
		echo "$printf_tests_repo$dir"
	fi
done

for dir in $FOLDER
do
	# Grab the type for a given repository
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


#For putting tests:
#sed -i.bak "s/XXX/\"Hello dude%d\", 42/g" KK_TYPE_NAME.C && rm *.bak

### Format: FOLDER;TYPE;NAME;ARG ###

echo "OOOOOOOOOOOOOOOOOOOOOOOOOOO"

FOLDERS_TEST=()
IFS=$'\n'       # make newlines the only separator
set -f          # disable globbing
i=0
for q in $(cat < "tests.txt"); do
	FOLDERS_TEST[$i]+="$(echo $q | cut -d ';' -f1)"
	if [ !$(cd $printf_tests_repo/${FOLDERS_TEST[$i]} 2>/dev/null) ]
	then
		echo "$printf_tests_repo${FOLDERS_TEST[$i]}"
	fi
#	echo "${FOLDERS_TEST[$i]}"
	((i++))
done






