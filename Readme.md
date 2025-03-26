# Secured Project: `libhashtable.a`

## Overview
This project implements a secure and efficient hashtable library, `libhashtable.a`. The library provides functionality for creating, managing, and manipulating hashtables, including operations such as insertion, deletion, searching, and dumping the contents of the hashtable.

The project is written in C and adheres to modular programming principles, ensuring maintainability and scalability.

---

## Features
- **Hashtable Operations**:
  - Create a new hashtable (`new_hashtable`).
  - Insert key-value pairs (`ht_insert`).
  - Search for a value by key (`ht_search`).
  - Replace an existing value (`ht_replace`).
  - Delete a key-value pair (`ht_delete`).
  - Dump the contents of the hashtable (`ht_dump`).
  - Delete the entire hashtable (`delete_hashtable`).

- **Utility Functions**:
  - Custom implementations of common functions like `my_strlen`, `my_putstr`, `my_putchar`, and more.
  - A lightweight `mini_printf` function for formatted output.

- **Error Handling**:
  - Comprehensive error handling for invalid inputs and edge cases.
  - Error messages are printed to `stderr` using `my_stderr`.

- **Unit Testing**:
  - Extensive unit tests using the Criterion framework to ensure correctness and reliability.

---

## File Structure
```
/home/nexlein/B-CPE-110-MPL-1-1-secured/
├── include/
│   ├── hashtable.h       # Hashtable structure and function prototypes
│   ├── my.h              # General utility function prototypes
├── tests/
│   ├── unit_tests.c      # Unit tests for the library
├── *.c                   # Source files for various functionalities
├── Makefile              # Build system for compiling the library and tests
└── Readme.md             # Project documentation
```

---

## Compilation
To compile the project, use the provided `Makefile`.

### Build the Library
```bash
make
```
This will generate the `libhashtable.a` static library.

### Run Unit Tests
```bash
make tests_run
```
This will compile and execute the unit tests, providing coverage reports.

### Clean Build Files
```bash
make clean
```
Removes object files.

```bash
make fclean
```
Removes object files, the library, and test binaries.

---

## Usage
### Include the Library
To use the library in your project, include the `hashtable.h` header:
```c
#include "include/hashtable.h"
```

### Example: Creating and Using a Hashtable
```c
#include "include/hashtable.h"
#include "include/my.h"

int main() {
    hashtable_t *ht = new_hashtable(hash, 10);
    if (ht == NULL) {
        my_stderr("Failed to create hashtable.\n");
        return 1;
    }

    ht_insert(ht, "key1", "value1");
    char *value = ht_search(ht, "key1");
    if (value != NULL) {
        mini_printf("Found: %s\n", value);
    }

    ht_delete(ht, "key1");
    delete_hashtable(ht);
    return 0;
}
```

---

## Testing
The project uses the Criterion testing framework for unit tests. Tests are located in `tests/unit_tests.c` and cover all major functionalities of the library.

Run the tests using:
```bash
make tests_run
```

---

## Authors
- **EPITECH PROJECT, 2025**

---

## License
This project is licensed under the EPITECH standard license. Refer to the EPITECH guidelines for more details.
