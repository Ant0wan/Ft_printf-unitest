# Ft_printf-unitest [![42](https://i.imgur.com/9NXfcit.jpg)](i.imgur.com/9NXfcit.jpg)[![freetime](https://i.imgur.com/8IcDLkc.png)](i.imgur.com/8IcDLkc.png)

This micro-framework is a fork of Libunit [a 42 project] - a C Programming Language Micro-framework dedicated to unit testings. The framework is able to execute series of tests on C functions - one after the other - without interruption. It has been made for testing Ft_printf [a 42 project].

The framework is linked to a script building test tree and all .c, .o, .h, repositories and makefile needed to perform the test of the "rendu" project - necessarily a version of ft_printf/printf like function source code.

---

### Demo

[![ftprintfunitestdemo](https://i.imgur.com/)](i.imgur.com)

---

## Description

- The framework tests the return value and the output of any given printf like function - prototype containing a format string and an ellipse.

- The framework uses `stdio.h` functions instead of the libft for better performances. It includes the following headers:

```shell=
stdlib.h
strings.h
unistd.h
sys/wait.h
stdio.h
wchar.h
```

- The symbolic link `start.sh` launch the script `set_tests.sh` in the `./test_to_be_added/` repository. The script builds the tests and its tree based on the input in file './test_to_be_added/test_to_be_added`. After building files and repositories, the script launch the `test` makefile dependency and launches the tests.

- `clean` argument can be given to `start.sh` to execute script with a clean option. the clean option deleted all routines and its root repository. It also put all files in `./test_to_be_added/` to their default value.

- The symbolic link `write_your_tests.txt` allows acces to the `tests.txt` file in in the `./test_to_be_added/` repository. It contqins all tests applied to the "rendu" project. It follow the syntax:

| Folder      | Type  | Name      | Arguments   |
| ----------- | ----- | --------- | ----------- |
| conversions |  int  | inifinity | "%ls", L'∞' |

- `Arguments` is what will be placed inside the printf(HERE); e.g. printf("%ls", L'∞');

- Input example:

```shell=
unicode;chr;infinity;"%ls", L'∞'
```

- Some characters are not compatible with the framework: `/` and `\`. It is due to sed substitues not properly secured in `set_tests.sh`.

- Tests can be added to tests.txt folling the above-mentionned format, e.g.

```shell=
vim write_your_tests.txt
```

- The framework stores tests in a list with a specific name which is written to the standard output.

- Each test is executed in a separate process.

- Each process is closed at the end of the test and gives the hand back to the parent process.

- It catches the result of the child process and the type of interruption if it crashes (e.g. SegFault or BusError).

- The compiled library is named libunit.a and is stored in `./framework/` repository.

- The library is linked to the given code in `./rendu/` repository - should be the ft_printf source code containing a makefile.

- The project must contain a Makefile with usual rules `make`, `clean`, `fclean` and `re`.

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

- each routine is placed in a folder tests/[function_to_test]

- tests does not write on standard output

- for each function, the corresponding tests are grouped in the same folder, with a specific source file called "Launcher"

- the Launcher is used to load and run all the test to the choosen function

- only one function per file

- each name of test file begins with a number followed by an underscore. It defines the run order

Example:
```shell=
04_float_precfour.c
```

- file with a name starting by ```00_xxx``` is always considered as the "Launcher"

- the main containing the tests is located in the root folder

- the main calls all the Launchers

- the Makefile associated with the program contains an additional dependency called ```test```

- the ```test``` dependency compiles the program with the test files and run its binary file

- the source code of the micro-framework in located in the folder named "framework"

- source code of the `./test_to_be_added/XX_TYPE_NAME.c` file must be modified line 13 `#include "../rendu/include/ft_printf.h" // to change with correct path` with appropriate ft_printf header file path.

---

## Usage

- Clone repository

```shell=
git clone https://github.com/Ant0wan/Ft_printf-unitest.git && cd ./Ft_printf-unitest.git/
```

- Copy your printf like function soucre code in the repository

```shell=
cp -f [Makefile+auteur+*.c+*.h+...] Ft_printf-unitest.git/rendu/
```

- Add your tests following the specific format above-mentionned

```shell=
vim write_your_tests.txt
```

- Once tests has been added, launch the script to build the tests tree and launch tests

```shell=
./start.sh
```

- Check output !
