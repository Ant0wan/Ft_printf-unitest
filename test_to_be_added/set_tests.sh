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

#### Script for building test functions and adding includes. ####

## Declare test repo path
declare printf_tests_repo="../printf_tests/"

## Declare repos
declare -a FOLDER=("conversions" "width" "flags")

## Declare types by repo
declare -a TYPE=("int" "long" "unisgnedint")

## Declare names by types
#int
declare -a NAME_int=("oneint" "twoint" "nan" "overflow" "zero")
#long
declare -a NAME_long=("onelong" "twolong" "nan" "overflow" "zero")
#unsigned int
declare -a NAME_long=("oneunsignedint" "twounsignedint" "nan" "overflow" "zero")

declare -a NAME
declare -a ARRAY


for f in "${FOLDER[@]}"
do
	echo "$printf_tests_repo$f" # Replace echo by mkdir
	for t in ${TYPE[@]}
	do
		for n in ${NAME_int[@]}
		do
			echo "cp XX_TYPE_NAME.c $printf_tests_repo$f/01_$t"_"$n" # Replace echo by cp
		done
	done
done

#cp XX_TYPE_NAME.c
