# Compiler

#Start git Repo

#in cmd:

#find the folder on your PC where you want to initialize the repository

#use git init

#use git clone with the path of this repo


#have flex for windows installed
#change the working directory of flex to your repository


#use lex with yacc
Goto to Command Prompt(cmd)

- Goto the directory where you have saved the program

- Type in command :-  flex Compiler.l
- Type in command : yacc -d Parser.y

- Type in command :- gcc lex.yy.c Parser.tab.c

- Execute/Run for windows command promt :-     a.exe    
- Some kind of "type something in should appear"
- At the moment the first input will always make a syntax error, but the second should work
