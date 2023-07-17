/*
Question 1 :
typedef struct Node
{
TypeTag type;
} Node;
typedef enum TypeTag {
...
}
Using this structure, please write a function that returns fibonacci sequence based on the following arithmetic operations (+, -, *, /) and conditions.
The fibonacci function should be implemented using Dynamic Programming.

Author :Namsi Lydia
*/


#include <stdio.h>

typedef enum TypeTag
{
  ADD,
  MUL,
  SUB,
  FIBO
} TypeTag;


typedef struct Node
{
  enum TypeTag type;
} Node;


int
fibonacci (int n)
{
  int fib[n + 1];
  fib[0] = 0;
  fib[1] = 1;

  for (int i = 2; i <= n; i++)
    {
      fib[i] = fib[i - 1] + fib[i - 2];
    }

  return fib[n];
}

int
operationPerformed (TypeTag operation, int a, int b)
{
  switch (operation)
    {
    case ADD:
      return a + b;
    case MUL:
      return a * b;
    case SUB:
      return a - b;
    case FIBO:
      return fibonacci (a);
    default:
      printf ("Invalid operation\n");
      return 0;
    }
}

int
main ()
{
  int add_result = operationPerformed (ADD, 7, 8);
  int mul_result = operationPerformed (MUL, 9, 4);
  int sub_result = operationPerformed (SUB, 8, 14);
  int fibo_result = operationPerformed (FIBO, 4, 0);

  printf ("add : %d\n", add_result);
  printf ("mul : %d\n", mul_result);
  printf ("sub : %d\n", sub_result);
  printf ("fibo : %d\n", fibo_result);

  return 0;
}
