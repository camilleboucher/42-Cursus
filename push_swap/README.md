_This project has been created as part of the 42 curriculum by cboucher._

# push_swap

## Description
In this project we have to sort a stack of numbers with a small set of instructions and with the least amount of moves. We also have another empty stack where we can put numbers temporarily.

### Move set

1.	**sa (swap a):** Swap the first 2 elements at the top of stack a. Do nothing if there is only one element or none.
2.	**sb (swap b):** Swap the first 2 elements at the top of stack b. Do nothing if there is only one element or none.
3.	**ss :** sa and sb at the same time.
4.	**pa (push a):** Take the first element at the top of b and put it at the top of a. Do nothing if b is empty.
5.	**pb (push b):** Take the first element at the top of a and put it at the top of b. Do nothing if a is empty.
6.	**ra (rotate a):** Shift up all elements of stack a by 1. The first element becomes the last one.
7.	**rb (rotate b):** Shift up all elements of stack b by 1. The first element becomes the last one.
8.	**rr :** ra and rb at the same time.
9.	**rra (reverse rotate a):** Shift down all elements of stack a by 1. The last element becomes the first one.
10.	**rrb (reverse rotate b):** Shift down all elements of stack b by 1. The last element becomes the first one.
11.	**rrr :** rra and rrb at the same time.

## Instructions

### Compilation

Use `make` or `make re` to compile the program. For cleaning the generated files use `make clean` or `make fclean`.

### Usage
To use the push_swap program, run push_swap with a series of numbers as arguments, separated by spaces. The minimum and maximum values for a number are the range of an INT.

Example : `./push_swap 9 -33 21 6 7 4`

## Resources
1.	Explication of an optimized algorithm for 3 numbers : https://medium.com/@jamierobertdawson/push-swap-the-least-amount-of-moves-with-two-stacks-d1e76a71789a
2.	Explication of an algorithm for less than 7 numbers : https://github.com/AdrianWR/push_swap
3.	Some inspirations for a complex algorithm (not in the final project) : https://www.youtube.com/watch?v=2aMrmWOgLvU
4.	Peer-to-peer interactions for the use of the butterfly algorithm (efficient and easy algorithm).
5.	Web research and AI chat for some notions about double linked list.
