# *This project has been created as part of the 42 curriculum by diferrei*

---

# **Description**
The `ft_printf` requires one to recode the standard C library function: `printf()`. The goal is to create a versatile library (`libftprintf.a`) that handles various format specifiers and mimics the behavior of the original function.

This project allows you to learn more about **variadic functions** in C (using `<stdarg.h>`) aswell as reinforcing the understanding of data types, memory representation, and hexadecimal/numerical conversions.

--- 

## **Algorithm Explanation**
The core of `ft_printf` is a conversion function designed to parse a format string and handle data on the fly..

### **1. The Variadic Engine**
Since `printf` takes an unknown number of arguments, we use `va_list`, `va_start`, `va_arg`, and `va_end`. These macros allow the function to "step through" the stack to retrieve data based on the specifier found in the format string.

### **2. Ft_conversion**
As the function iterates through the string, it looks for the `%` symbol. Once found, it evaluates the next character:
- It maps the character (e.g., `s`, `d`, `x`) to a specific helper function.
- It pulls the correct data type from the variadic list (e.g., `char *` for `%s`, `int` for `%d`).

### **3. Numerical and Hexadecimal Conversions**
To handle numbers, the algorithm uses an iterative approach:
- **Base 10:** For `%d`, `%i`, and `%u`, it uses modulo and division by 10 to extract digits, stores them in a buffer, and prints them in reverse order.
- **Base 16:** For `%x`, `%X`, and `%p`, it uses a similar modulo/division logic with a base-16 string (`0123456789abcdef`).
- **Pointers:** The `%p` specifier is treated as an `unsigned long` to ensure it can hold 64-bit memory addresses, prefixing the output with `0x`.

---

# **Instructions**

## **Compilation**
To compile the library, run the following command in the terminal:
```bash
make
```
This will generate the libftprintf.a file. The Makefile includes the requested rules: all, clean, fclean, and re.

## **Usage in a Project**
To use `ft_printf` in your own C projects, include the header and link the library during compilation:

```c

#include "ft_printf.h"

int main()
{
    ft_printf("Hello %s, the answer is %d.\n", "World", 42);
    return (0);
}
```

Compile with:
```bash
cc main.c libftprintf.a -o my_program
```
---

# **Technical Choices**
Temp Buffer: Instead of malloc, small local arrays were used for numerical conversions to reduce the risk of memory leaks.

Data Types: Used unsigned long for hexadecimal conversions to ensure portability of pointer addresses on 64-bit systems.

Structure: The project is split into multiple files (chars, numbers, hex) to comply with the 42 Norm (5 functions per file).

# **Resources**
[Variadic Functions in C](https://pubs.opengroup.org/onlinepubs/009695399/basedefs/stdarg.h.html)- Official documentation on handling the stdarg.h library.

[Breakdown on printf functionality](https://pubs.opengroup.org/onlinepubs/009695399/functions/printf.html) - Understanding the printf function.

# **AI Usages**
AI was used in this project for the following tasks:

- **Conceptual Clarification:** Explaining the behavior of `va_arg` and how type promotion works (e.g., why char is promoted to int in variadic functions aswell as how to use `va_arg` in function calls).

- **Debugging:** Identifying logic errors in the hexadecimal length calculation and fixing Valgrind "uninitialized value" errors during francinette tests.

- **Formatting:** Structuring the README documentation.
