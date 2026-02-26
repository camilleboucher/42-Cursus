_This project has been created as part of the 42 curriculum by cboucher._

# Libft

## Description
This first project is the spiritual successor to the famous C piscine at 42. We must recreate parts of the C standard library (glibc). We gain an initial understanding of UNIX/POSIX system calls, memory management, and fundamental basic concepts in C programming.

Data structures are fundamental concepts in programming. Here, we have an initial overview of using structures to create a linked list and the functions that allow us to manipulate it.

The ultimate goal of this project is to be able to reuse it in other projects and to implement new functionalities throughout the core curriculum, such as an equivalent to `printf`, for example.

### A small example of important functions :

1.	`ft_strlcat`: This function appends a specified number of characters from one string to the end of another, ensuring that the resulting string is null-terminated and does not exceed a given size, allowing safe concatenation.
2.	`ft_strncmp`: This function compares up to a specified number of characters from two strings and returns an integer indicating their lexical difference, allowing for case-sensitive comparison.
3.	`ft_atoi`: This function converts a string representation of an integer to its integer value, ignoring any leading whitespace and stopping at the first non-numeric character.
4.	`ft_strdup`: This function creates a duplicate of a given string by allocating sufficient memory and copying the contents, returning a pointer to the newly created string.
5.	`ft_split`: This function divides a given string into an array of substrings based on specified delimiter characters, returning a pointer to the first element of the array.
6.	`ft_putnbr`: This function outputs an integer value as a string to a specified output, typically handling negative numbers and formatting the output correctly.

## Important Concepts

### Memory Management (Reading & Writing)

In C, as with low-level languages, we must manage memory to avoid reading from or writing to inappropriate locations. Therefore, it is important to properly initialize each variable after its declaration. We should also ensure that character strings are terminated by a null byte `'\0'` to indicate the end of the string. For an array of integers, the end is indicated by a variable containing the number of elements (`size`). Lastly, for a linked list, it will be a `next` pointer that points to `NULL` (no address).

### Stack and Heap

When allocating memory by creating variables, we can request the compiler to store them in the stack or in the heap.

The stack is limited, but allocation within it is faster. It also allows us to take advantage of locality (avoiding fragmentation) to optimize CPU cache usage and thus gain performance (cache hit). However, we must be careful with recursion in return values to avoid a stack overflow. For dynamic sizes, we need to allocate memory in the heap.

The heap is a little bit slower but larger and more flexible. Since allocation in the heap is dynamic, we must ensure to free it to avoid saturating memory. Unlike many other high-level languages, C does not have a garbage collector, which allows for performance gains compared to languages that do. However, we must be even more vigilant about memory leaks or security flaws, such as use-after-free, for example.

It's worth noting that the stack operates in a single thread. For multi-threading, it's better to use the heap.

## Instructions

### Compilation

Use `make` or `make re` to compile the program. For cleaning the generated files use `make clean` or `make fclean`.

## Technical Choices

I used bitwise operators in this project to gain an understanding of their uses and to envision certain computational optimizations by employing them. In the end, the compiler already optimizes some operations on its own. However, I still found the challenge and the reflection interesting. We will necessarily have to use bitwise operators for the first exam, as well as for certain projects like minitalk (bit-by-bit signal transmission).

## Resources
1.	[GNU Make Manual](https://www.gnu.org/software/make/manual/) for make.
2.	`man` for the original functions of glibc and for the ASCII table.
3.	Peer-to-peer learning.
4.	[Excellent video about the Stack from Core Dumped](https://www.youtube.com/watch?v=N3o5yHYLviQ)
5.	Web research, YouTube videos and AI chat for some notions.
