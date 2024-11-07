# Push Swap (42 School)

🇬🇧🇺🇸

Push Swap is designed to develop algorithmic thinking and data structure manipulation skills. 
The goal of the project is to sort a stack of numbers using only a limited set of operations, emphasizing efficiency in terms of both time and space complexity. 
This project serves as an introduction to sorting algorithms and requires you to implement your own sorting logic to achieve the minimum number of operations.

🇮🇹

Push Swap ha l’obiettivo di sviluppare il pensiero algoritmico e la gestione delle strutture dati. 
L’obiettivo è ordinare una pila di numeri utilizzando solo un set limitato di operazioni, ottimizzando la complessità temporale e spaziale. 
Questo progetto serve come introduzione agli algoritmi di ordinamento e richiede di implementare una logica di ordinamento per ridurre al minimo il numero di operazioni.

### Execution:
```bash
./push_swap <list_of_integers>

Example:
./push_swap 3 2 5 1 4
```
This will output the sequence of operations needed to sort the stack.

Operations
The project restricts you to a set of operations to manipulate the stack, which include:

sa: Swap the first two elements of stack A.
sb: Swap the first two elements of stack B.
ss: Perform sa and sb at the same time.
pa: Push the top element from stack B to stack A.
pb: Push the top element from stack A to stack B.
ra: Rotate all elements in stack A up by one.
rb: Rotate all elements in stack B up by one.
rr: Perform ra and rb at the same time.
rra: Reverse rotate all elements in stack A down by one.
rrb: Reverse rotate all elements in stack B down by one.
rrr: Perform rra and rrb at the same time.
