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
> scoop install gcc
```

You may need to install [Scoop](https://scoop.sh/) before it.

## Build

To compile a program using GNU C++, you can use the command line utility **g++**. For example, if your program is named `phomnemonic.cpp`, you can type this command prompt to compile the program. 

```
> g++ phomnemonic.cpp -o phomnemonic.exe
```

You may need to set up some environment variables to find header files and libraries. 

If the compilation is successful, you will find an executable file with the same name as your program, such as **phomnemonic.exe**. You can run it using command-prompt or powershell.

## Usage

The `phomnemonic.exe` is a program that generates all possible mnemonics for a given telephone number. To run the program, you need to provide the telephone number as a command-line argument. You can also specify an output filename to save the mnemonics in a tab-separated format. 

To view the help menu, use the `-h` or `--help` option, as shown below:

```
> .\phomnemonic.exe -h

Usage:
 phomnemonic <phone_number>
 phomnemonic <phone_number> --output <output_filename>

Options:
-h, --help       Show this help message and exit
-v, --version    Show the program version and exit
-o, --output     Filename to save the output.
```

To view the version details, use the `-v` or `--version` option, as shown below:

```
> .\phomnemonic.exe -v

Phomnemonic (v1.0.0)
It creates all the possible alphanumeric mnemonics that correspond to a phone number.
Copyright (c) 2005 Abhishek Kumar. This work is licensed under the GNU GPL v3 or later.
```

To generate and save the mnemonics, use the `-o` or `--output` option, followed by the output filename, as shown below:

```
> .\phomnemonic.exe <phone_number> -o <output.tsv>
```

Note: If you do not provide an output filename, the mnemonics will be saved in a file named **output.txt** by default.

## WebAssembly

WebAssembly (Wasm) is a **low-level assembly-like language** that can run in modern web browsers with **near-native performance**. It is a **portable compilation target** for programming languages such as C/C++, C#, and Rust, enabling them to run on the web for client and server applications. WebAssembly is also designed to work alongside JavaScript, allowing both languages to share functionality and access web APIs.

WebAssembly has a **compact binary format** that can be loaded and executed efficiently by web browsers. It also has a **textual format** that can be used for debugging, testing, and writing programs by hand. WebAssembly is a **memory-safe** and **sandboxed** execution environment that follows the same-origin and permissions policies of the web.

WebAssembly is developed as an open standard by the W3C WebAssembly Working Group and Community Group, with active participation from all major browser vendors. You can find developer reference documentation for WebAssembly on MDN's WebAssembly pages.

### Prerequisite

To run this project, you need to install the [WASI SDK](https://github.com/WebAssembly/wasi-sdk) and [wasmtime](https://wasmtime.dev/).

- The WASI SDK provides a C/C++ compiler toolchain for WebAssembly. 
  - Make sure it does not conflict with the [GNU GCC](https://gcc.gnu.org/) compiler on your system. One way to avoid this is to make the GNU GCC binaries global and wrap the WASI SDK binaries under a `wasi` command using this gist [wasi.cmd](https://gist.github.com/isurfer21/7199f72346f6cddf83773a9457c716fa). This way, you can use both compilers on the same system without conflict.
- Wasmtime is a runtime for running WASI-based wasm files.

### Build 

To compile the code and generate a wasm file, use this command:

```
> wasi clang++ .\phomnemonic.cpp -o .\phomnemonic.wasm
```

### Usage

To view the help menu, use this command:

```
> wasmtime .\phomnemonic.wasm -- -h
```

To view the version details, use this command:

```
> wasmtime .\phomnemonic.exe -- -v
```

To generate and save the mnemonics for a phone number, use this command:

```
> wasmtime .\phomnemonic.wasm -- <phone_number> -o <output.tsv>
```

## License

This program is free and open source and licensed under [GNU GPL](.\LICENSE). You can use it for any purpose, but please give credit to the original author.
