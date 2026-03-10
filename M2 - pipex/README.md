_This project has been created as part of the 42 curriculum by cboucher._

# pipex

## Description

Discovering native support for base octale
certains tests peuvent etre fait en limitant le nombre de processus dans une session bash avec ulimit -u 547 par exemple
echo $? dans bash pour recuperer le code de sortie de la derniere commande
2> error_log.txt pour demander a bash de redirigier la sortie derreur par exemple
dossier /proc pour les processus et fds associés

## Technical Choices

decider de gerer mieux que bash les messages derreurs en les mettant dans des pipes puis je me rendu compte que je suis limité par les
1024 de fd ouvert
Du coup j'ai refais des tests avec bash et je me suis rendu compte de l'ordre suivant :
il test le infile et outfile en premier et affiche derreurs
il fork toutes les commandes (en ignorant celles des infiles et outfiles qui marchent pas)
puis il access toutes les commandes (en ignorant celles des infiles et outfiles qui marchent pas)

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
3h20
-  tester " cat -e" par exemple avec des espaces avant nom de cmd
- creer fonction close fd pipe parent 
- faire fonctions erreurs + faire les TODOs 
- tester NULL aux malloc ET -fsanitize=address avec le cas des chaines vides
- tester le 42 pipex tester dont le sleep : https://github.com/michmos/42_pipex_tester et https://github.com/bastienkody/pipex_tester
- faire norme + readme



lexer = parser + executer en meme tmp
cat /dev/urandom pour des generations aleatoire
echo -e "\a" pour une alerte sonore
pgrep pipex
comment generer de la doc auto sur lazyvim lazyvim (plugin ?)
