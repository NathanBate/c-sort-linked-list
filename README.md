# Linked List Sort

A C program that reads names from a file and sorts them using a linked list data structure.

## Features

- Reads names from a specified input file
- Stores names in a linked list
- Sorts the list alphabetically using bubble sort
- Displays both unsorted and sorted lists
- Command-line argument parsing with help option
- Proper memory management

## Project Structure

```
linked-list-sort/
├── README.md           # This file
├── main.c             # Main program entry point
├── Makefile           # Build configuration
├── .gitignore         # Git ignore rules
├── include/           # Header files
│   ├── linked_list.h  # Linked list data structure and functions
│   └── args.h         # Command-line argument parsing
├── src/               # Source files
│   ├── linked_list.c  # Linked list implementation
│   └── args.c         # Argument parsing implementation
├── build/             # Compiled object files and binary (ignored by git)
└── names.txt          # Sample input file
```

## Building

### Using Make (Recommended)

```bash
# Build the project
make

# Build with debug symbols
make debug

# Build with optimizations
make release

# Clean build artifacts
make clean
```

### Manual Compilation

```bash
gcc -Wall -Wextra -std=c99 -Iinclude -c main.c -o build/main.o
gcc -Wall -Wextra -std=c99 -Iinclude -c src/linked_list.c -o build/linked_list.o
gcc -Wall -Wextra -std=c99 -Iinclude -c src/args.c -o build/args.o
gcc build/main.o build/linked_list.o build/args.o -o build/linked_list_sort
```

## Usage

```bash
# Basic usage
./build/linked_list_sort -f names.txt
./build/linked_list_sort --file data.txt

# Show help
./build/linked_list_sort -h
./build/linked_list_sort --help

# Using make to run
make run
```

### Command-line Options

- `-f, --file <filename>`: Specify the input file containing names
- `-h, --help`: Show help message and exit

## Input File Format

The input file should contain one name per line:

```
Alice
Bob
Charlie
Diana
```

## Example Output

```
Unsorted list:
Alice
Charlie
Bob
Diana

Sorted list:
Alice
Bob
Charlie
Diana
```

## Algorithm

The program uses a bubble sort algorithm to sort the linked list. While not the most efficient sorting algorithm, it's simple to understand and implement for educational purposes.

## Memory Management

The program properly manages memory by:
- Allocating memory for each linked list node
- Freeing all allocated memory before program exit
- Handling memory allocation failures gracefully

## Error Handling

The program handles various error conditions:
- Missing command-line arguments
- Invalid command-line options
- File not found or cannot be opened
- Memory allocation failures

## Version Control

The project includes a `.gitignore` file that excludes:
- Build artifacts (`build/` directory, `*.o`, `*.exe`, etc.)
- IDE/editor temporary files
- OS-generated files (`.DS_Store`, `Thumbs.db`, etc.)

This follows standard C project conventions where only source code and configuration files are tracked in version control.

## Contributing

Feel free to submit issues or pull requests to improve the program.

## License

This project is available under the MIT License.
