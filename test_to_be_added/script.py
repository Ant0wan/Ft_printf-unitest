#!/usr/bin/python3
# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    script.py                                          :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abarthel <abarthel@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/08 12:27:18 by abarthel          #+#    #+#              #
#    Updated: 2019/02/08 12:27:18 by abarthel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

import os, errno

path = os.getcwd()
dirname = "/hello"

full_path = path + dirname

try:
    os.mkdir(full_path)
except OSError:
    print ("Creation of the directory %s failed" % full_path)
