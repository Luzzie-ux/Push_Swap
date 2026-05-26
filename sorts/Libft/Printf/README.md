*This project has been created as part of the 42 curriculum by rodrpere*

# Introduction

In this project I have coded a custom printf function to use in my later projects on the 42 school. In order to better understand what I have done, head over to the [Description](#description) or if you want to see what exactly was implemented go to [Instructions](#instructions).

I made use of three .c files:

	* utils.c (where most of my functions live)
	* ptr.c (where ft_putptr and its helper live)
	* ft-printf (where the main ft_printf and its format handler are)

I also have a custom header called ft_printf.h where each functions prototype used to make printf possible can be found, as well as a Makefile for easier compilation, head over to [How to compile it](#how-to-compile-it), to see for yourself

# Description

In this project, I tackled the making of a custom function that will be taking the place of the C standard library Printf function in my posteriour projects. 

The printf (the short form of print formatted) is used in order to write to our standard output (or terminal in this case), whenever the function is called.  

The function receives two parameters, one identified as a const char ptr format and the other one being unspecified. In order to do this we need to include the stdarg.h in the top of our file, so that way we have access to the variadic functions. 

## What are variadic functions?

Variadic functions are a type of functions that when included can receive an undertermined number of arguments. This feature is useful when the number of parameters needed for a function to work is not established. Because of this, it has its usefulness when certain functions like our ft-printf or scanf, are needed. It only needs one fixed argument in order to be used (like our cosnt char ptr format), and we call it, using the ellipses (...).    

# Resources

In order to make this project possible I requeried the use of the following: [W3Schools](https://www.w3schools.com/), [StackOverflow](https://www.stackoverflow.com/), [GeeksforGeeks](https://www.geeksforgeeks.org/), [PortfolioCourses](https://www.youtube.com/@PortfolioCourses) and the help of my peers to better understand how to start, debug and learn how the original C Library Printf function works.

# Instructions

```bash
# 1. First git clone this repository by using:
git clone https://github.com/Luzzie-ux/Printf.git your_dir_name

# 2. Run this command while on the root of the repo:
make

# 3. Compile everything (if you arent in the root of the repo) by using:
gcc your_file.c -L../ft_printf -lft

# IF you are in the root, use this command to compile:

gcc your_file.c libftprintf.a

# 4. If you want to remove the .o run: 
make clean

# or if you want to remove both .o and .a, try:
make fclean

#to recompile every .c inside the repo and remove the old .o and .a files, use:
make re
```

# What was implemented?

## Functions

To make ft_printf work, I made use of the following functions:

``` c
//will write to stdout one character
int		ft_putchar(char c);

//will write to stdout the whole string
int		ft_putstr(char *s);

//will receive a long var and write to stdout the number given
int		ft_putnbr(long nbr);

//will receive a void pointer and write its address in hexadecimal form
int		ft_putptr(void *ptr);

//will receive a unsigned long var and write to stdout the number given
int		ft_putnbr_un(unsigned int nbr); 

//will receive a unsigned int var and the its format specifier, then
//write to stdout the number given in its hexadecimal form
int		ft_puthex(unsigned int nbr, char format); 
```
all of these functions can be found in utils.c and ptr.c

## Formatting

As it was asked in the subject, the following conversions where done:

```c

"%c" Prints a single character.

"%s" Prints a string (as defined by the common C convention).

"%p" The void * pointer argument has to be printed in hexadecimal format.

"%d" Prints a decimal (base 10) number.

"%i" Prints an integer in base 10.

"%u" Prints an unsigned decimal (base 10) number.

"%x" Prints a number in hexadecimal (base 16) lowercase format.

"%X" Prints a number in hexadecimal (base 16) uppercase format.

"%%" Prints the percent sign.

```
