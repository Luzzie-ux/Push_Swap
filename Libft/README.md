*This project has been created as part of the 42 curriculum by rodrpere*

## Description

This Repo exists to hold my own Libft library, a custom-writen collection of C functions originally implemented in the Libc library of the C Programming language and other libraries aswell. With the purpose of better learning how to implement these functions on other potential 42 projects, this library includes functions that can manipulate strings, dynamically allocate memory, and manage data structures.

The functions are divided into three parts:

  * [Part 1 - Libc Functions](#Part-1-Libc-Function)
  * [Part 2 - Additional Functions](#part-2--additional-functions)
  * [Part 3 - Linked Lists](#part-3--linked-lists)

Their implementation and a brief explanation of how their work, is on the end of this Readme

## Instructions

To compile the library, type the command `make` in the shell while inside the libft dir, shortly after a `libft.a` and `*.o` files will be created on the root.  

To clean .o files, type `make clean`, to clean all .o and .a type `make fclean`, in the case of needed recompiling, write `make re` to do so.

In order to use this library with any of your `.c` file that might need it, type `gcc your_file.c libft.a` or `cc your_file.c -L. -lft` while inside this directory.

In the case of using this libft outside of its own dir, type `gcc your_file.c -L../Libft -lft` or `cc your_file.c -L../Libft -lft` to do so(`-L` adds the dir to the library search path, `.` means the current directory and `-lft` tells the linker to look for `libft.a`).

The library is accompanied by a header file called `libft.h`, which contains prototypes for all the functions in the library. To use the library in your project, include the header file and link to the library as described above. 

## Resources

In the making of this library, AIs like Claude from Antrophic and Chatgpt from OpenAI were used in order to learn concepts, syntax and rules to rebuild each function, and spot potential edge cases/errors that couldnt be encountered only by me and my peers. 

For testing and debugging, the website [PythonTutor](https://pythontutor.com/) was utilized to better visualization of the code and how everything interacts, the [Francinette](https://github.com/xicodomingues/francinette), a code tester created by a 42 student for other students, helped me learn how to think of potential errors that could come.

> If for example, a dynamic memory allocation made using the function malloc(3) failed. It should then: `return (NULL)`, or if in the case of a function which it has its return type as `void`, then the return statement should look like this: `return `, nested under our if statement.

Alongside those tools, these online spaces: [W3Schools](https://www.w3schools.com/), [StackOverflow](https://www.stackoverflow.com/), [GeeksforGeeks](https://www.geeksforgeeks.org/), [PortfolioCourses](https://www.youtube.com/@PortfolioCourses) and my peers, helped me learn what was needed to better understand C and its inner workings.

## Functions implemented

In the followind lines, each function will be briefly explained in order to give a base understanding of what each of them do, as well as be seperated by their correspondent overall goal.

|Part 1 - Libc Function | Part 2 - Additional functions | Part 3 - Linked Lists |
|-----------------------|-------------------------------|-----------------------|
|   ft_isalpha          |       ft_substr               |   ft_lstnew           |
|   ft_isdigit          |       ft_strjoin              |   ft_lstadd_front     |
|   ft_isalnum          |       ft_strtrim              |   ft_lstsize          |
|   ft_isascii          |       ft_split                |   ft_lstlast          |
|   ft_isprint          |       ft_itoa                 |   ft_lstadd_back      |
|   ft_strlen           |       ft_strmapi              |   ft_lstdelone        |
|   ft_memset           |       ft_striteri             |   ft_lstclear         |
|   ft_bzero            |       ft_putchar_fd           |   ft_lstiter          |
|   ft_memcpy           |       ft_putstr_fd            |   ft_lstmap           |
|   ft_memmove          |       ft_putendl_fd           |                       |
|   ft_strlcpy          |       ft_putnbr_fd            |                       |
|   ft_strlcat          |                               |                       |
|   ft_toupper          |                               |                       |
|   ft_tolower          |                               |                       |
|   ft_strchr           |                               |                       |
|   ft_strrchr          |                               |                       |
|   ft_strncmp          |                               |                       |
|   ft_memchr           |                               |                       |
|   ft_memcmp           |                               |                       |
|   ft_strnstr          |                               |                       |
|   ft_atoi             |                               |                       |
|   ft_calloc           |                               |                       |
|   ft_strdup           |                               |                       |

### Part 1 - Libc Function

#### Character Checks
- **`ft_isalpha`** — Returns true if the character is a letter (a–z, A–Z).
- **`ft_isdigit`** — Returns true if the character is a digit (0–9).
- **`ft_isalnum`** — Returns true if the character is alphanumeric (letter or digit).
- **`ft_isascii`** — Returns true if the character is within the ASCII table (0–127).
- **`ft_isprint`** — Returns true if the character is printable (including space).

#### Character Conversion
- **`ft_toupper`** — Converts a lowercase letter to uppercase.
- **`ft_tolower`** — Converts an uppercase letter to lowercase.

#### String Functions
- **`ft_strlen`** — Returns the length of a string (excluding the null terminator).
- **`ft_strlcpy`** — Copies a string into a buffer with a size limit, always null-terminating.
- **`ft_strlcat`** — Appends a string to a buffer with a size limit, always null-terminating.
- **`ft_strchr`** — Returns a pointer to the first occurrence of a character in a string.
- **`ft_strrchr`** — Returns a pointer to the last occurrence of a character in a string.
- **`ft_strncmp`** — Compares two strings up to n characters.
- **`ft_strnstr`** — Finds the first occurrence of a substring within a string, up to n characters.
- **`ft_strdup`** — Allocates and returns a duplicate of a string.

#### Memory Functions
- **`ft_memset`** — Fills a block of memory with a given byte value.
- **`ft_bzero`** — Sets a block of memory to zero.
- **`ft_memcpy`** — Copies n bytes from one memory area to another (no overlap handling).
- **`ft_memmove`** — Copies n bytes between memory areas, safely handling overlaps.
- **`ft_memchr`** — Searches for the first occurrence of a byte value in a memory block.
- **`ft_memcmp`** — Compares two memory blocks byte by byte.

#### Conversion & Allocation
- **`ft_atoi`** — Converts a string representation of a number to an integer.
- **`ft_calloc`** — Allocates memory for n elements and zeroes it out.

### Part 2 — Additional Functions

#### String Manipulation
- **`ft_substr`** — Extracts a substring from a string given a start index and max length.
- **`ft_strjoin`** — Concatenates two strings into a new allocated string.
- **`ft_strtrim`** — Removes all leading and trailing characters found in a given set.
- **`ft_split`** — Splits a string by a delimiter character and returns an array of substrings.
- **`ft_itoa`** — Converts an integer to its string representation.
- **`ft_strmapi`** — Applies a function to each character of a string, returning a new string.
- **`ft_striteri`** — Applies a function to each character of a string in place (with index).

#### Output Functions
- **`ft_putchar_fd`** — Writes a single character to a given file descriptor.
- **`ft_putstr_fd`** — Writes a string to a given file descriptor.
- **`ft_putendl_fd`** — Writes a string followed by a newline to a given file descriptor.
- **`ft_putnbr_fd`** — Writes an integer as a string to a given file descriptor.

### Part 3 — Linked Lists

#### Data structure manipulation
- **`ft_lstnew`** — Creates and returns a new linked list node with a given content.
- **`ft_lstadd_front`** — Adds a node to the beginning of a linked list.
- **`ft_lstsize`** — Returns the number of nodes in a linked list.
- **`ft_lstlast`** — Returns the last node of a linked list.
- **`ft_lstadd_back`** — Adds a node to the end of a linked list.
- **`ft_lstdelone`** — Deletes a single node using a provided function to free its content.
- **`ft_lstclear`** — Deletes and frees all nodes in a linked list.
- **`ft_lstiter`** — Applies a function to the content of every node in a linked list.
- **`ft_lstmap`** — Applies a function to each node's content and returns a new list with the results.