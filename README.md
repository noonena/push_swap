# push_swap

Project: Stack Sorting with Operations
## Overview

The primary goal of this project is to sort numbers in ascending order in stack a using a defined set of operations. Initially, stack a contains a set of random, non-duplicate integers, and stack b starts empty.

```
Stacks and Initial Conditions
Stack a: Contains a random number of non-duplicate integers, both negative and positive. <br />
Stack b: Starts empty.
```

## Operations
You can use the following operations to manipulate the stacks:

```
sa (swap a): Swap the top two elements of stack a. No action is taken if there is only one or no elements.
sb (swap b): Swap the top two elements of stack b. No action is taken if there is only one or no elements.
ss: Perform sa and sb simultaneously.
pa (push a): Move the top element from stack b to stack a. No action is taken if stack b is empty.
pb (push b): Move the top element from stack a to stack b. No action is taken if stack a is empty.
ra (rotate a): Rotate all elements of stack a upward; the top element moves to the bottom.
rb (rotate b): Rotate all elements of stack b upward; the top element moves to the bottom.
rr: Perform ra and rb simultaneously.
rra (reverse rotate a): Rotate all elements of stack a downward; the bottom element moves to the top.
rrb (reverse rotate b): Rotate all elements of stack b downward; the bottom element moves to the top.
rrr: Perform rra and rrb simultaneously.
```

## Project Rules

A Makefile must be included to compile your source files without relinking.
Use of global variables is forbidden.

The program, named push_swap, should take integers as arguments, with the first argument representing the top of stack a.
The program must output the smallest list of instructions possible to sort stack a with the smallest number at the top.

Instructions must be separated by a newline ('\n'), and nothing else.
Your solution will be evaluated based on the efficiency of the operation list compared to a maximum allowable number of operations.
If the sorting or operation count criteria aren't met, the grade will be 0.
If no parameters are specified, the program should exit without any output.
The program must handle errors, such as non-integer arguments or duplicates, by displaying "Error\n" on the standard error.


## Error Handling
The program should display an error message "Error" followed by a newline if:

- Any arguments are not integers.
- Any integers are repeated.
- Any arguments exceed typical integer values.
