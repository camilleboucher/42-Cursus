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

## Instructions

### Compilation

Use `make` or `make re` to compile the program. For cleaning the generated files use `make clean` or `make fclean`.


## Resources
1.	[GNU Make Manual](https://www.gnu.org/software/make/manual/) for make.
2.	`man` for the original functions of glibc and for the ASCII table.
2.	Peer-to-peer learning.
2.	Web research and AI chat for some notions.
