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
#Format in TEST-FILE: FOLDER;TYPE;NAME;ARG

### REPOSITORY and MAKEFILE ###
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
fi
declare Makefile=$printf_tests_repo"Makefile"
if [ ! -f $Makefile ]
then
	cp -f Makefile $printf_tests_repo
fi

### CREATE TESTS ###
declare -a FOLDER=$(cat $TEST_FILE | cut -d ";" -f1 | sort | uniq)
# Creates a repository for each category
for dir in $FOLDER
do
	if [ ! -d $printf_tests_repo$dir ]
	then
		mkdir "$printf_tests_repo$dir"
	fi
done
# Fill main.c, launcher.h, testsfiles, types.h and launchers
for dir in $FOLDER
do
	echo ""
	# Add prototypes to launchers.h
	declare prototype="void  $dir""_launcher(t_err_info *info);"
	sed -e '/PROTOTYPES/a\'$'\n'"$prototype" launchers.h > launchers.bak && cp -f launchers.bak launchers.h && rm launchers.bak
	# Add functions call to main.c
	declare functionscall="$dir""_launcher(info);"
	sed -e '/FUNCTIONS/a\'$'\n'"\	$functionscall" main.c > main.bak && cp -f main.bak main.c && rm main.bak
	sed 's/FOLDER/'$dir'/g' 00_FOLDER_launcher.c > 00_$dir""_launcher.c
	sed 's/FOLDER/'$dir'/g' FOLDER.h > $dir.h
	declare TYPE=$(cat $TEST_FILE | grep $dir | cut -d ";" -f2)
	declare NAME=$(cat $TEST_FILE | grep $dir | cut -d ";" -f3)
	read -a type <<< $TYPE
	read -a name <<< $NAME
	index=0
	for i in $TYPE
	do
		digit="$(printf %02d $(echo "$index+1" | bc))"
		#echo $digit
		#echo "${type[index]}"
		#echo "${name[index]}"
		ARG="$(cat $TEST_FILE | grep $dir';' | grep ${type[index]}';' | grep ${name[index]}';' | cut -d ";" -f4)"
		sed "s/XXX/$ARG/g" XX_TYPE_NAME.c | sed "s/XX/$digit/g" | sed "s/TYPE/${type[index]}/g" | sed "s/NAME/${name[index]}/g" > $digit""_${type[index]}""_${name[index]}.c
		mv $digit""_${type[index]}""_${name[index]}.c "$printf_tests_repo$dir"
		sed -e '/LOAD TESTS/a\'$'\n'"\	load_test(&${type[index]}_${name[index]}, &testlist, \"${type[index]}_${name[index]}\", 0);" 00_$dir""_launcher.c > 00_$dir""_launcher.bak && cp -f 00_$dir""_launcher.bak 00_$dir""_launcher.c && rm 00_$dir""_launcher.bak
		sed -e '/PROTOTYPES/a\'$'\n'"int\	${type[index]}_${name[index]}(void);" $dir.h > $dir.bakh && cp -f $dir.bakh $dir.h && rm $dir.bakh
		((index++))
	done
	mv "00_$dir""_launcher.c" "$printf_tests_repo$dir"
	mv $dir.h "$printf_tests_repo$dir"
done
# Copies the launchers.h to the test repository
cp launchers.h $printf_tests_repo
cp main.c $printf_tests_repo
