# printf

This is a custom implementation of the C standard library function `printf`.

## Project Description
The `_printf` function produces output according to a format string.
For Task 0, it handles a subset of the standard conversion specifiers.

## Supported (Task 0)
- `%c` : character
- `%s` : string
- `%%` : percent sign
## Compilation
```bash
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c
