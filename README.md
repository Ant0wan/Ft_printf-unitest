Ongoing project:

Still to be made:
- documentation README.md
- CircleCI build test
- Quality code and reviews


Recently be done:
- check the returning value of printf on top of output
- script to build and code the tests tree
- added templates
- added macro in testings for easy replacing
- void function for testing printf
- added few tests made be not at the right place (conversions)
- testing function template for printf testing
- framework using stdio.h





# Ft_printf-unitest [![42](https://i.imgur.com/9NXfcit.jpg)](i.imgur.com/9NXfcit.jpg)[![freetime](https://i.imgur.com/8IcDLkc.png)](i.imgur.com/8IcDLkc.png)

This micro-framework is a fork of Libunit [a 42 project] - a C Programming Language Micro-framework dedicated to unit testings. The framework is able to execute series of tests on C functions - one after the other - without interruption. It has been made for testing Ft_printf [a 42 project].

The framework is linked to a script building test tree and all .c, .o, .h, repositories and makefile needed to perform the test of the "rendu" project - necessarily a version of ft_printf/printf like function source code.

---

## Description

- The symbolic link `start.sh` launch the script `set_tests.sh` in the `./test_to_be_added/` repository. The script builds the tests and its tree based on the input in file './test_to_be_added/test_to_be_added`.

- The symbolic link `write_your_tests.txt` allows acces to the `tests.txt` file in in the `./test_to_be_added/` repository. It contqins all tests applied to the "rendu" project. It follow the syntax:

| Signal | Description |
| --- | --- |
|     |     |  


Tests can be added to tests.txt folling the above-mentionned format, e.g.

```shell=
vim write_your_tests.txt
```

input:

```shell=
unicode;chr;infinity;"%ls", L'∞'
```

some characters are not compatible with the framework: `/` and `\`. It is due to sed substitues not properly secured in `set_tests.sh`.

- The framework stores tests in a list with a specific name which is written to the standard output.
- Each test is executed in a separate process.
- Each process is closed at the end of the test and gives the hand back to the parent process.
- It catches the result of the child process and the type of interruption if it crashes (e.g. SegFault or BusError).

The compiled library is named libunit.a and is stored in `./framework/` repository.
The library is linked to the given code in `./rendu/` repository - should be the ft_printf source code containing a makefile.

The project contains a ith usual rules (make, clean, fclean, re).

### The Micro-framework

- At the end of the tests execution, the name of each test is written with its corresponding results.

Results follow the format:

| Signal | Description |
| --- | --- |
| **OK** | Test succeeded |
| **KO** | Test failed |
| **SEGV** | Segmentation Fault detected |
| **BUSE** | Bus Error detected |

- The total number of tests and the count of succeeded tests are displayed.

- In the case of a success, the routine exists returning zero (0).

- If any of the tests fails, the routine returns minus one (-1).

- Only the result of each test is displayed.

Screenshot:

[![ftprintftest](https://i.imgur.com/)](i.imgur.com/)

### Test routines

The testing routines follow the specifications below:

- each routine must be placed in a folder tests/[function_to_test]

- each test is encapsulated in a function which follows the prototype:


- tests does not write on standard output

- for each function, the corresponding tests are grouped in the same folder, with a specific source file called "Launcher"

- the Launcher is used to load and run all the test to the choosen function

- only one function per file

- each name of test file begins with a number followed by an underscore. It defines the run order

Example:
```shell=
04_basic_test_four_a.c
```

- file with a name starting by ```00_xxx``` will always be considered as the "Launcher"

- the main containing the tests is located in the root folder

- the main calls all the Launchers

- the Makefile associated with the program contains an additional dependency called ```test```

- the ```test``` dependency compiles the program with the test files and run its binary file

- the source code of the micro-framework in located in the folder named "framework"

- each routine has its own makefile including ```test``` dependency

---

## Usage

- Clone repository

```shell=
git clone https://github.com/Ant0wan/Libunit.git
```

- Copy your work in the "rendu" repository

```shell=
cp -f [mywork_repository] Libunit/rendu/
```

- Compile and Run tests

```shell=
make -C [tests_directory] test
```

- Check output !

### Demo

[![Libunitdemo](https://i.imgur.com/4IV7ijk.gif)](i.imgur.com/4IV7ijk.gif)








































## Installation

```shell=
git clone https://github.com/Ant0wan/Ft_printf-unitest.git && cd Ft_printf-unitest/
```

Copy your ft_printf soucre code in the repository:

```shell=
cp -f [Makefile+auteur+*.c+*.h+...] Ft_printf-unitest/rendu/
```

--- 


