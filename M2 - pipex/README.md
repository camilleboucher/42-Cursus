_This project has been created as part of the 42 curriculum by cboucher._

# pipex

## Description

Discovering native support for base octale
certains tests peuvent etre fait en limitant le nombre de processus dans une session bash avec ulimit -u 547 par exemple
echo $? dans bash pour recuperer le code de sortie de la derniere commande

## Technical Choices

## Instructions

### Compilation

Use `make` or `make re` to compile the program. For cleaning the generated files use `make clean` or `make fclean`.

### Usage

To use the so_long program, run so_long with a .ber map file.

Example : `./so_long maps/1.ber`

## Resources

1.	[Article by Roslyn Michelle](https://www.rozmichelle.com/pipes-forks-dups/)
2.	[CodeVault's Youtube playlist](https://www.youtube.com/playlist?list=PLfqABt5AS4FkW5mOn2Tn9ZZLLDwA3kZUY)
3.	Peer-to-peer learning.
4.	man (umask, pipe, fork, dup2, execve, wait)
5.	Web research and AI chat for some notions.

TODO:

9h a 11h et 13h20 a 22h20
- faire norme + readme
- TEST ECOLE : voir TODO create_children.c
- TEST CA A LECOLE sqns infile et avec pas de perm outfile : valgrind --trace-children=yes --track-fds=yes ./pipex infile "touch bra" "touch bre" "tougfzfzefch bro" "touch bru" outfile
- TEST CA A LECOLE avec pipex2 sans perm dexec : valgrind --trace-children=yes --track-fds=yes --leak-check=full --show-leak-kinds=all ./pipex infile "touch a" "./pipex2" "touch c" outfile
