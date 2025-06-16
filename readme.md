
# Simple To-Do List in C

A simple terminal based to-do list written entirely in C



## Features

- Adding Tasks
- Removing Tasks
- Viewing Tasks

## Differences
Unlike a Javascript To-Do list written on the web, this one is compiled by you, in your terminal compatiable with any operating system (as long as it can compile C)

This To Do list does not save and fully removes all data when exitted.

## Editing
If you want to edit the source code feel free to do so, the code is very simple and easy to understand.
However, if you do not want to edit the code, I would suggest editing the values in the `config.h` file, which contains 2 values:
MAX_TASKS
BUFFER_SIZE

Max tasks is the maximum number of tasks you can have in your to-do list, and buffer size is the maximum length of a task (in characters).
You can change these values to suit your needs, lowering them will increase performance, but also limit the number of tasks you can have and the length of each task.

## Requirements
- A C compiler (GCC, Clang, etc.)
- A terminal (Linux, Windows, Mac)


## Installation

Install the To Do list

Linux:
```bash
  git clone https://github.com/connorakey/todo-list-c
  cd todo-list-c
  make
```

Windows:
```powershell
  git clone https://github.com/connorakey/todo-list-c
  cd todo-list-c
  gcc -o main main.c
```

Mac:
```zsh
  git clone https://github.com/connorakey/todo-list-c
  cd todo-list-c
  clang -o main main.c
```

It is recommmened you install with Linux since the make file has some tiny optimizations, that likely won't matter at all on a code base of ~150 lines



### Created on June 15th, 2025
## By Connor Akey, Year 8
