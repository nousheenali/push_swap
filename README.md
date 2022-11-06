# push_swap

Goal of the project:

To sort data on a stack with a limited set of instructions using the lowest possible number of actions.

To do so we have the following operations at our disposal:
- sa (swap a): Swap the first 2 elements at the top of stack a. Do nothing if there is only one or no elements.
- sb (swap b): Swap the first 2 elements at the top of stack b. Do nothing if there is only one or no elements.
- ss : sa and sb at the same time.
- pa (push a): Take the first element at the top of b and put it at the top of a. Do nothing if b is empty.
- pb (push b): Take the first element at the top of a and put it at the top of b. Do nothing if a is empty.
- ra (rotate a): Shift up all elements of stack a by 1. The first element becomes the last one.
- rb (rotate b): Shift up all elements of stack b by 1. The first element becomes the last one.
- rr : ra and rb at the same time.
- rra (reverse rotate a): Shift down all elements of stack a by 1. The last element becomes the first one.
- rrb (reverse rotate b): Shift down all elements of stack b by 1. The last element becomes the first one.
- rrr : rra and rrb at the same time.

## Example:
$>./push_swap 2 1 3 6 5 8

sa
pb 
pb
pb 
sa
pa 
pa
pa

$>./push_swap 0 one 2 3

Error 


<img width="73" alt="image" src="https://user-images.githubusercontent.com/66158938/200159318-b11bcb1c-7674-44f9-a484-c9a60c9ca8d3.png">


Reference :

https://medium.com/@jamierobertdawson/push-swap-the-least-amount-of-moves-with-two-stacks-d1e76a71789a
