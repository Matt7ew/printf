# ft_printf

A custom implementation of the C standard library `printf` function, built as a static library.

## Overview

`ft_printf` replicates the core functionality of `printf`, handling the most common format specifiers. It is written in C and compiled into a static library (`libftprintf.a`).

## Supported Specifiers

| Specifier | Description                        |
|-----------|------------------------------------|
| `%c`      | Print a single character           |
| `%s`      | Print a string                     |
| `%p`      | Print a pointer address            |
| `%d`      | Print a decimal integer            |
| `%i`      | Print an integer                   |
| `%u`      | Print an unsigned decimal integer  |
| `%x`      | Print a hexadecimal number (lowercase) |
| `%X`      | Print a hexadecimal number (uppercase) |
| `%%`      | Print a literal percent sign       |

## Building

```bash
make        # Build the library (libftprintf.a)
make clean  # Remove object files
make fclean # Remove object files and the library
make re     # Rebuild from scratch
```

## Usage

Include the header and link against the library:

```c
#include "ft_printf.h"

int main(void)
{
    ft_printf("Hello, %s! The answer is %d.\n", "world", 42);
    return (0);
}
```

Compile with:

```bash
cc -Wall -Wextra -Werror main.c -L. -lftprintf -Iincludes -o my_program
```

## Project Structure

```
.
├── includes/
│   └── ft_printf.h       # Header file
├── srcs/
│   ├── ft_printf.c       # Core ft_printf logic
│   ├── handlers/         # Specifier handler functions
│   │   ├── handle_char.c
│   │   ├── handle_str.c
│   │   ├── handle_ptr.c
│   │   ├── handle_nbr.c
│   │   ├── handle_hex.c
│   │   └── handle_unsigned.c
│   └── utils/            # Utility functions
│       ├── ft_itoa.c
│       ├── ft_strlen.c
│       └── ft_strbase.c
└── makefile
```
