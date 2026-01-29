_This project has been created as part of the 42 curriculum by cboucher._

# ft_printf

## Description

In this project, we have to recreate the essential parts of the `printf` function. This will allow us to display customized strings, which will be very useful throughout the common core. Variadic functions and va macros will be among the new concepts covered.

## Instructions

### Compilation

Use `make` or `make re` to compile the program. For cleaning the generated files use `make clean` or `make fclean`.

### Usage example

This call `ft_printf("Hello! My name is %s. I have %d years old.", "Jassira", 42);` will write in the standard output : `Hello! My name is Jassira. I have 42 years old.`.

## Technical Choices

### Array of funtion pointers

I used an array of function pointers to achieve an O(1) optimization. Instead of iterating through each special character after a %, I directly send the value of that character into the array corresponding to the pointer of the appropriate function.

### Improvement suggestions

I started this project before implementing get_next_line (which allows reading a file line by line). In its current state, I am making system calls for almost every character I process. I later realized that this is not the most optimal approach!
Therefore, if I wish to improve this project in the future, I will use buffers and reduce the number of system calls.

## Resources
1.	`man` for the original function and va macros.
2.	Peer-to-peer learning.
3.	Web research, YouTube videos and AI chat for some notions.
