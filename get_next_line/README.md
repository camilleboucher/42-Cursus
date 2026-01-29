_This project has been created as part of the 42 curriculum by cboucher._

# Get Next Line

## Description

This project is already a greater obstacle to overcome. Here, we learn to use files through system calls using file descriptors (POSIX API). The difficulty stemmed from the limited number of lines and functions imposed by 42. Debugging was laborious but allowed us to understand certain dynamic memory allocation errors, such as use after free. That is why it is often important to set a pointer to NULL after freeing it.
We also learn about using static variables.

## Instructions

### Compilation

Use `make` or `make re` to compile the program. For cleaning the generated files use `make clean` or `make fclean`.

### Usage example

To use this function, we must first open the file descriptor with the system call `open`. We can then iterate in a loop calling `get_next_line(fd)`, which will return the next line from the file or `NULL` if it has reached the end of the file. Don’t forget to call `free(line)` at each iteration and to `close` the fd at the end of the iterations.

## Resources
1.	Strong peer-to-peer learning.
2.	[Tech Fairy's video](https://www.youtube.com/watch?v=saMebwRO-Q8)
2.	Web research, YouTube videos and AI chat for some notions.
