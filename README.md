## Simple_Shell

## Synopsis
This is a simple and basic implementation of a UNIX command line interpreter.

## Description
Simple_shell can interpret and execute command line arguments read from the standard input. It reads line by line from a file or the terminal line. It then interprets the lines and executes it if the line is a valid command.

## Usage
All the files are to be compiled on an Ubuntu 14.04 LTS machine with:    
```
gcc -Wall -Werror -Wextra -pedantic *.c -o sish
```  
Once compiled, to start the program, run:    
```./sish```  
To exit the program, use the ```exit``` command
  
