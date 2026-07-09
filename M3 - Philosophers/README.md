_This project has been created as part of the 42 curriculum by cboucher._

# Philosophers

## Description

In this C project, we need to implement the Dining Philosophers problem using multithreading and mutexes. It is a problem introduced by Edsger Dijkstra in 1965. It depicts a table of philosophers who share forks to eat spaghetti. Its purpose is to illustrate the phenomenon of deadlock that can occur in a computer system when resources are shared, here represented by forks. It helps illustrate the conditions for deadlock, then find solutions to prevent it.

This problem is mainly used in the study of process scheduling and resource allocation.

Here, to represent this problem, the philo program will display in the terminal each change in a philosopher’s state, accompanied by a timestamp.

### Fundamental Concepts

Through the functions provided by the pthread library, we learn how to manage thread synchronization to minimize concurrency issues and take advantage of parallelism. We also use resource management techniques via mutexes that help protect us against data races and deadlocks.
It also requires careful handling of thread lifecycle, timing, and monitoring to ensure the simulation runs correctly and stops when needed.

### Basic rules

- Each philosopher is a thread.
- Each philosopher has one fork protected by a mutex.
- A philosopher can only take the forks to their left and right.

## Instructions

### Compilation

Use `make` or `make re` to compile the program. To clean generated files use `make clean` or `make fclean`.

### Usage

To use the mandatory philo program, run philo with at least 4 numbers :
number_of_philosophers time_to_die time_to_eat time_to_sleep

Example : `./philo 5 800 200 200`

You can also use a 5th optional argument for the number of times each philosopher must eat.

## Technical Choices

I chose to use a state machine for this project because I found it well suited to the task. Indeed, philosophers change states regularly, and this makes it possible to check their death quickly.

I set a numerical limit of 120,000 for all program launch parameters because it represents 2 minutes and far exceeds the number of threads available on the system.

To avoid congestion, I used a waiting system and an even/odd parity logic. In fact, odd philosophers eat first, then even philosophers.

## Resources

1.	[CodeVault's Youtube playlist](https://www.youtube.com/playlist?list=PLfqABt5AS4FmuQf70psXrsMLEDQXNkLq2)
2.	Peer-to-peer learning.
3.	man
4.	Web research and AI chat for some notions.
