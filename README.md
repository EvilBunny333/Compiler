# Compiler

#DEVELOPMENT



#Start git Repo

#in cmd:

#find the folder on your PC where you want to initialize the repository

#use git init

#use git clone with the path of this repo


#have flex for windows installed
#change the working directory of flex to your repository


#use lex with yacc
- Go to to Command Prompt(cmd)

- Go to the directory where you have saved the program

- Type in command :  flex Compiler.l
- Type in command : yacc -d Parser.y

- Type in command : gcc lex.yy.c Parser.tab.c
=======

- Execute/Run for windows command promt :-     a.exe    
- Some kind of "type something in" should appear


#USAGE

Type in a.exe

Some allowed Input types:

3+5*6 returns the result
int a = 7 declares int variable
a = b+c changes the value of existing variable
if(5==7){3+4}else{6} returns the value from if or else
a<=b returns true or false
float a = 1.0 declare float variable
string a = hello declare string variable
bool a = 1 declare bool variable
print  Will show all variables

Some not allowed inputs:
int a = 1+2 cant use math in declaration
redeclarations

Some not implemented things:
Calculation with float propably not possible
While loop can be input but not functioning
If Else output might be buggy, as in it understands the condition but still calculates the path that should not be used

