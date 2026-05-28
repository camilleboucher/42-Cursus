_This project has been created as part of the 42 curriculum by cboucher and lifranco._

# minishell

## Description

minishell is a project which the main goal is to make a simple terminal shell. It takes `bash` has an inspiration but this is not a clone of it.

A shell is basically a prompt that can execute commands and make redirections. Examples of shells are `zsh`, `fish`, or what we use as a reference for ours, `bash`.

In this project we also created built-ins. They act like separate commands or programs but are fully integrated into minishell and can perform different actions (see the section dedicated to built-ins).

### Main features

minishell displays a prompt when waiting for a new command. It launches the right executable, whether you input a **relative**, **absolute** or a **PATH inside an environment variable**.

It **handles redirections**, which are:
- `< input_file`: which redirect the input of the command with the content of the specified file.
- `> output_file`: which redirect the output of the command in the specified file by replacing his content.
- `<< EOF`: which should be given a delimiter, then read the user's input until a line containing the delimiter is seen then redirect all the inputs of the command.
- `>> output_file`: which redirect the output of the command in the specified file in **append mode**.

It also **implement pipes**: `|`. The **output** of each command in the pipeline is connected to the **input** of the next command via a pipe. Except if there are redirections to handle for the corresponding direction.

### Built-ins

All our built-ins except echo do not handle options.

- `echo`: displays a line of text. The `-n` option erase the newline at the end of the text written. (ex: `echo Bonjour $USER` donne `Bonjour USER\n`)
- `cd`: changes the working directory. (ex: `cd Downloads`)
- `pwd`: prints the name of the current/working directory.
- `export`: set the export attribute for variables. Also prints every environment variables, including hidden ones. (ex: `export foe=bar`, `export foe+=42`)
- `unset`: unset values and attributes of variables. (ex: `unset foe`)
- `env`: prints environment variables except hidden ones.
- `exit`: cause the shell to exit, except if inside a pipe.

### Other behaviors

minishell have a <ins>**working history**</ins> during his execution.

It handles single quotes, which prevents the shell from interpreting special characters (`$` for example). It handles double quotes, which prevent the shell from interpreting special characters ***except*** `$`. It also not process unclosed quotes or special characters.

It also handles expands, which are environment variables (`$HOME` for example, expand to `/home/user`). Although, `$?` expand the exit status of the most recently executed foreground pipeline.

minishell handles signals of SIGINT (CTRL + C) and SIGQUIT (CTRL + \ ):
- CTRL + C displays a new prompt on a newline.
- CTRL + \ is absolutely fucking useless.

CTRL+D is not a signal. It puts an EOF (End‑Of‑File) character in the prompt. It exits the shell if the line is empty.

## Instructions

### Usage

To use our Minishell, you should clone our project with

`git clone`

then, use `make` or `make re` to compile the program. To clean generated files use `make clean` or `make fclean`.

finally, simply run our Minishell by using 

`./minishell`

It will wait for a prompt and you can uses it like bash.

## Technical Choices

### Parsing (by Liam François)

The parsing of Minishell is the equivalent of stubbing your toe while stepping on a lego while having a testicular torsion. <ins>**It's one of the most MISERABLE THING I'VE EVER DONE IN MY ENTIRE LIFE**</ins>.

*ahem*, after this justified crashout, here's how the Parsing handles everything.

The parsing handles redirections and pipes that are not separated by a space. how ? by simply adding spaces to them.

The parsing also checks for syntax errors in the limiters. There is a seperate parsing for syntax error (Quotes or unhandled chars) that is done before anything.

After checking everything is right, it divides everything written by whitespaces, except if inside quotes, and it gets tokenized (redirections characters are assigned the right type, filenames are checked, pipes creates new command and the rests are words.)

Then it puts everything back in place, putting commands in their right pipe, in the right redir etc.

Finally, it sends it to the Execution part, after cleaning the tokenizer.

### Handling Signals (by Camille Boucher)

When handling signal management in C, it’s important to use async-signal-safe functions. To avoid undefined behavior when code is interrupted by a signal, the POSIX standard defines a list of usable functions (see `man 7 signal-safety`). Therefore, it is strongly discouraged to use stdio functions such as printf, to name just one example.

- `man 7 signal` and `sigaction`, `sigemptyset`, `sigaddset`, `kill`: manual and functions to help understand the use of signals.

### Execution part (by Camille Boucher)

During execution, I used the stat function to handle non‑executable files, files not found, or files without sufficient permissions. This allowed me to better understand the Linux paradigm "Everything is a file" and to begin exploring the inode structure of files (`man 7 inode`). I was also able to see concepts such as sockets, FIFO (pipes for example : First In First Out) and the macros used to handle file types, for example.

## Other Concepts Covered

- `strace` can be use to inspect bash behaviors in detail.

### Authorized and interesting functions

- `getenv`: retrieve an environment variable (we coded ft_getenv for our custom env).
- `access`: determine whether a file is accessible and its permissions (using the path and an amode RWXF).
- `stat`: returns a struct with info about a file/directory via its path; macros usable to know if it is a file, directory, etc. `fstat` is the same thing but via its fd, `lstat` is the same as stat but does not follow symbolic links.
- `isatty`: to avoid launching minishell through a pipe for example.
- `getcwd`: get the current working directory corresponding to the running binary.
- `chdir`: change the current working directory for the running binary.
- `opendir`, `readdir`, `closedir`: open a directory, read files one by one on each call returning a structure (DO NOT FREE), close the directory.
- `unlink`: delete a file
- `wait3` and `wait4`: variants of wait and waitpid with a struct that provides more info.
- `ioctl`: allows getting the terminal size for example and configuring/managing other things with requests and macros related to the device/terminal. Can be used for example to inject a \n into a readline to terminate it. But not recommended in a signal because the function is not async-signal-safe

### Other niche functions about the terminal

- `tcgetattr`: read the current terminal configuration.
- `tcsetattr`: change the terminal configuration.
- `tgetent`: load terminal info from the database.
- `tgetflag`: check a boolean capability (does it support X?).
- `tgetnum`: retrieve a numeric value (number of columns).
- `tgetstr`: get an escape sequence (color code, movement).
- `tgoto`: convert coordinates into an escape sequence.
- `tputs`: send a sequence to the terminal.

## Resources

1.	[Article by Roslyn Michelle](https://www.rozmichelle.com/pipes-forks-dups/)
2.	[CodeVault's Youtube playlist](https://www.youtube.com/playlist?list=PLfqABt5AS4FkW5mOn2Tn9ZZLLDwA3kZUY)
3.	[Mes conseils si je devais recommencer minishell by Mostafa Omrane](https://medium.com/@mostafa.omrane/mes-conseils-si-je-devais-recommencer-minishell-a9783c51ba1b)
4.	[GNU Readline Library](https://tiswww.cwru.edu/php/chet/readline/readline.html#index-rl_005fredisplay)
5.	[GNU History Library](https://tiswww.case.edu/php/chet/readline/history.html)
6.	[Conventional Commits](https://www.conventionalcommits.org/en/v1.0.0/)
7.	[Minishell testing](https://docs.google.com/document/d/1r0yE7gK12J6lW79mzY8ELyKJEiDqkOeRfXZ6DWSKZVE/) Because 42’s subject isn’t precise enough.
8.	Peer-to-peer learning.
9.	man RTFM
10.	Web research and AI chat for some notions.

## The End

- Well, what did you think of this project Camille?

- The project is very cool. I loved working on the part about system calls with signals, using pipes, and making children, etc... I think the topic could have been more precise because a lot of things are open to interpretation, but that's also what's interesting; it stimulates discussion and different viewpoints.

- Good ! Well, i thought it was awesome, although very unexplained...

So, to finish in style, here's a Liam/Dearan fun fact!

Did you know? The group is named after the book of the same name! This book, written by Mark Z. Danielewski, inspired the whole Backrooms mythology and also was the biggest inspiration of the best Doom II Mod ever made : MyHouse.pk3!
