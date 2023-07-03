# phomnemonic

> Create all possible alphanumeric equivalents of a telephone number

This is a *phone mnemonics* program that generates all possible alphanumeric equivalents of a telephone number, based on the letters on the phone keypad. For example, the number 1004654329 can be represented as 100HOLIDAY.

## Motivation

This programme was developed during my college days in 2005 using **Turbo C++** as part of my third year project. The motivation behind this project was to remember important telephone or mobile numbers in case of emergency. The program can help users to find easy and memorable mnemonics for their numbers.

## Working

It takes a string variable `tn` that represents a phone number, and two arrays `a` and `y` that store some information about each digit of the phone number. The code loops over the digits of `tn` from right to left, and assigns a value to `a[i]` and `y[i]` based on the digit. 

For example, if the digit is '2', then `a[i]` is set to 65, which is the ASCII code for 'A', and `y[i]` is set to 3, which might indicate the number of possible letters for that digit on a phone keypad. 

Similarly, if the digit is '7', then `a[i]` is set to 80, which is the ASCII code for 'P', and `y[i]` is set to 4, which might indicate the number of possible letters for that digit on a phone keypad. If the digit is '0' or '1', then `a[i]` and `y[i]` are set to the same digit, and `y[i]` is set to 1, which might indicate that there are no possible letters for that digit on a phone keypad. 

For any other digit, the code does the same as for '0' or '1'. The variable `i` is calculated as 15 minus the length of `tn` plus the current index `z`, so that the rightmost digit of `tn` corresponds to the last element of `a` and `y`. 

The code assumes that `tn` has at most 15 digits, and that `a` and `y` have at least 16 elements each. 

Later, it takes the arrays `a` and `y` that were modified by previously, and an output stream variable `out` that might be a file or the console. The code loops over all possible combinations of letters for each digit of the phone number, and prints them to the output stream. 

For example, if the phone number is "23", then the code will print "AD", "AE", "AF", "BD", "BE", "BF", "CD", "CE", and "CF". 

The code uses nested for loops to increment and decrement the values of `a` according to the values of `y`, which indicate how many possible letters there are for each digit. 

The variable `ctr` keeps track of how many combinations have been printed, and adds a newline after every 6 combinations, or a tab otherwise. 

The variable `ltn` is the length of the phone number, and is used to determine which elements of `a` to print. The code assumes that `ltn` is at most 15, and that `a` and `y` have at least 16 elements each. 

## Install

This program is revised using GNU C++ compiler on Windows 11 to run it on modern systems. You can install the GNU C++ via this command,

```
scoop install gcc
```

You may need to install [Scoop](https://scoop.sh/) before it.

## Build

To compile a program using GNU C++, you can use the command line utility **g++**. For example, if your program is named **phomnemonic.cpp**, you can type **g++ phomnemonic.cpp -o phomnemonic.exe** in the command prompt to compile it. 

You may need to set up some environment variables to find header files and libraries. 

If the compilation is successful, you will find an executable file with the same name as your program, such as **phomnemonic.exe**. You can run it using command-prompt or powershell.

## Usage

Create **input.txt** file for the program read a telephone number and then generate all possible mnemonics for it. Then, execute the program via running the command,

```
.\phomnemonic.exe
```

The output will be saved in a file named **output.txt**. 

## License

This program is free and open source and licensed under [GNU GPL](.\LICENSE). You can use it for any purpose, but please give credit to the original author.
