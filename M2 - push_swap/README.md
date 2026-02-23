_This project has been created as part of the 42 curriculum by cboucher._

# Push_swap

https://github.com/user-attachments/assets/921d40f8-5f49-4754-8cdc-cd3f9220cc25

## Description

In this project we have to sort a stack of numbers with a small set of instructions and with the least amount of moves. We also have another empty stack where we can put numbers temporarily.

This project is quite complex because it requires many functions and an efficient algorithm. I chose to use a doubly linked list, which allowed me to understand this new concept better and to gain a clearer grasp of linked lists, which I thought I already understood. It was also a great project for me to better assimilate pointers and structures (struct).

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

## Technical Choices

I used a doubly linked list because it seemed obvious for me at first glance for optimizing a complex algorithm in terms of the number of moves to display. Since I anticipated many rotations, it felt more relevant for me to be able to modify a few nodes without needing to change all the others, as I would have to do if I had chosen an array, for example.

## Instructions

### Compilation

Use `make` or `make re` to compile the program. For cleaning the generated files use `make clean` or `make fclean`.

### Usage
To use the push_swap program, run push_swap with a series of numbers as arguments, separated by spaces. The minimum and maximum values for a number are the range of an INT.

Example : `./push_swap 9 -33 21 6 7 4`

## Resources
1.	Explication of an optimized algorithm for 3 numbers : [Article from Jamie Dawson](https://medium.com/@jamierobertdawson/push-swap-the-least-amount-of-moves-with-two-stacks-d1e76a71789a)
2.	Explication of an algorithm for less than 7 numbers : [Adrian Roque](https://github.com/AdrianWR/push_swap)
3.	Some inspirations for a complex algorithm (not in the final project) : [Video from Fred 1000orion](https://www.youtube.com/watch?v=2aMrmWOgLvU)
4.	Peer-to-peer interactions for the use of the butterfly algorithm (efficient and easy algorithm).
5.	Very good push_swap [visualizer](https://github.com/o-reo/push_swap_visualizer).
5.	Web research and AI chat for some notions about double linked list.
