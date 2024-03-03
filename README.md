## Brief

The core functionality of this system is to accept user input in the form of commands and manage key-value pairs accordingly. It aims to provide a simple yet effective way to handle data in memory, making it an ideal choice for applications requiring rapid access to stored information.

## Project Structure

The project is organized into a clean and modular file structure for ease of navigation and development:

- **`/src` Directory**: Contains all the source files (.c) necessary for the project's functionality.
- **`/src/includes` Folder**: Houses all the custom header files, segregating the declarations and macros needed across the source files.
- **`/demo` Folder**: A demonstration of a simple implementation of the project to help users understand its basic usage.
- **`/bin` Folder**: Intended for storing the binaries after compilation. This folder should be created at the root of the project directory.

## Build Instructions

To compile and build the project, follow these steps:

1. Create a `bin` directory at the root of the project folder if it does not already exist.
2. Navigate to the `src` directory.
3. Compile the source files using GCC with the following command:
     gcc [files to compile/*.c] -g -o ../bin/[executable name]

**Note**: It is recommended to automate this process with a Makefile for convenience.

## Code Design

The design of the codebase is intentionally kept simple for ease of understanding and modification:

- **Constants and Macros**: Defined in header files using `#define` for easy adjustments.
- **Modular Source Files**: Each source file has a corresponding header file declaring exported functions and constants.

### Workflow

Input >> | main.c | -> | controller.c | -> | handler.c | -> [ | *_api.c | ]
                              |
                            Output <<


- **`main.c`**: The entry point of the program that initializes the system and handles input.
- **`controller.c`**: Parses the input into commands and arguments, also validates them before further processing.
- **`handler.c`**: Acts as a bridge between the user commands and the specific operations/APIs that need to be executed.
- **`*_api.c` Files**: Represents the API source files for different types of storage, such as key-value pairs, sorted sets, etc. (Currently, only key-value pairs are implemented).

## To-Do List

- [ ] Implement a Makefile for easier build processes.
- [ ] Extend API functionalities for the SET data type.
- [ ] Add support for network connections and handling concurrent requests.
- [ ] Introduce multiple APIs for various data structures:
  - Lists
  - Hashed sets
  - Sorted lists
