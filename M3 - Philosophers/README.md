_This project has been created as part of the 42 curriculum by cboucher._

# Philosophers

## Description

### Fundamental Concepts

## Instructions

### Compilation

Use `make` or `make re` to compile the program. To clean generated files use `make clean` or `make fclean`.

### Usage

To use the mandatory philo program, run philo with at least 4 numbers.
number_of_philosophers time_to_die time_to_eat time_to_sleep

Example : `./philo 5 800 200 200`

You can also use a 5th optional argument for the number of times each philosopher must eat.

## Technical Choices

## Improvement Suggestions

## Resources

1.	[CodeVault's Youtube playlist](https://www.youtube.com/playlist?list=PLfqABt5AS4FmuQf70psXrsMLEDQXNkLq2)
2.	Peer-to-peer learning.
3.	man
4.	Web research and AI chat for some notions.


# TODO

2h de boulot + 3h30 + (18h30)

1) revoir rules de mickael et mettre le waitingrules dans le thinking

2 ) si impair mickael dit quil fait un 3seme groupe avec un seul philo

si nb philo est pair et que cest la premiere boucle
	usleep de timeeat pour le 2eme groupe (impair)

si nb philo est impair :
		if timetoeat >= timetosleep : > seulement plutot que >= !!?
			if philo est impair
					usleep eat*1000
			if philo = dernier	
				usleep eat 1000 (+1 utile ou pas??)
			if	boucle nest pas la premiere et que philo est  pair
				usleep eat 1000
		else	
			if boucle est la premiere et philo est impair
				usleep eat 1000

test quand timetoeat = 2x timetoslep
3 610 200 100
