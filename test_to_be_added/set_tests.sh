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


declare printf_tests_repo="../printf_tests/"
declare -a FOLDER=("conversions" "width" "flags")
declare -a TYPE=("int" "long" "unisgnedint")

#################################################################################
################# Declare names of the tests ####################################
declare -a NAME_int=("oneint" "twoint" "nan" "overflow" "zero")
declare -a NAME_long=("onelong" "twolong" "nan" "overflow" "zero")
declare -a NAME_unsignedint=("oneunsignedint" "twounsignedint" "nan" "overflow" "zero")


#################################################################################
############## ALGO BUILDING THE FILES AND REPOS ################################
declare index_type
for f in "${FOLDER[@]}"
do
	index_type=0
	echo "$printf_tests_repo$f" # Replace echo by mkdir
	for t in ${TYPE[@]}
	do
############################# BLOCK 1: INT ######################################
		if [ $index_type == 0 ]
		then
			for n in ${NAME_int[@]}
			do
				echo "cp XX_TYPE_NAME.c $printf_tests_repo$f/01_$t"_"$n.c" # Replace echo by cp
			done
		fi
############################ BLOCK 2: LONG ######################################
		if [ $index_type == 1 ]
		then
			for n in ${NAME_long[@]}
			do
				echo "cp XX_TYPE_NAME.c $printf_tests_repo$f/01_$t"_"$n.c" # Replace echo by cp
			done
		fi
########################## BLOCK 3: UNSIGNED INT ################################
		if [ $index_type == 2 ]
		then
			for n in ${NAME_unsignedint[@]}
			do
				echo "cp XX_TYPE_NAME.c $printf_tests_repo$f/01_$t"_"$n.c" # Replace echo by cp
			done
		fi
		index_type=$(echo "$index_type + 1" | bc)
	done
done
