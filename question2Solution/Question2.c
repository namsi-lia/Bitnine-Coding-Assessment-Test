/*

Question 2:
▪ Implement the following piecewise recurrence relation in the 3 different ways.
▪ Explain the differences (advantages, disadvantages) between the 3.
▪ Must be written in C
The problem
F(n) = F(n-3) + F(n -2) where F(0) = 0, F(1) = 1, and F(2) = 2.
Assume that n will be less than or equal to the maximum integer value and non-negative. You only need to
write the function(s).
*/

/*Author: Namsi Lydia*/

#include <stdio.h>

/*Dynamic Approach*/

int dynamicfibApproach (int n , int*fib)
{
  if (n == 0)
    return 0;
  else if (n == 1)
    return 1;
  else if (n == 2)
    return 2;
  else{
   if (fib[n] != -1)
    return fib[n];
    else{

    fib[n] = dynamicfibApproach (n - 3,fib) + dynamicfibApproach (n - 2 ,fib);
    return fib[n];

    }
  }
}


/*Iterative Approach*/

int iterativefibApproach (int n)
{
  int a = 0, b = 1, c = 2;

  if (n == 0)
    return a;
  else if (n == 1)
    return b;
  else if (n == 2)
    return c;

  for (int i = 3; i <= n; i++)
    {
      int temp = c;
      c = b + a;
      a = b;
      b = temp;
    }

  return c;
}


/**
 * Recursive Approach
*/

int recursivefibApproach (int n)
{
  if (n == 0)
    return 0;
  else if (n == 1)
    return 1;
  else if (n == 2)
    return 2;
  else
    return recursivefibApproach (n - 3) + recursivefibApproach (n - 2);
}


int
main ()
{
  int n = 10;		

// Dynamic Approach
  int fib[n+1];
  for (int i = 0; i < n; i++)
    fib[i] = -1;

  int result = dynamicfibApproach (n,fib);
  printf ("F(%d) = %d\n", n, result);

// iterative Approach
  printf ("Enter the value of n: ");
  scanf ("%d", &n);
  printf ("F(%d) = %d\n", n, iterativefibApproach (n));


// Recursive Approach
   printf ("Enter the value of n: ");
  scanf ("%d", &n);
  printf ("F(%d) = %d\n", n, recursivefibApproach (n));

  return 0;
}



/**
 Dynamic programming
 
 * Advantages of dynamic programming approach
 1. avoids redundant calculations by storing previously computed results in an array.
 2. It has a linear time complexity, making it efficient for large values of n.

 * Disadvantages of dynamic programming approach
 1. It requires additional memory to store the memo array, which can be a limitation for very large values of n. It adds some overhead due to the array accesses and function calls.
*/


/**
 Iterative Approach
 
 * Advantages of the iterative approach:
   1. This approach avoids redundant calculations and repetitive function calls, making it more efficient than the recursive approach.
   2. It has a linear time complexity, making it suitable for calculating large values of n.

 *Disadvantages of iterative approach
  1.This approach requires additional variables to store intermediate results, increasing the space complexity compared to the recursive approach.
*/

/**
Recursive Approach:

* Advantages of the recursive approach:
1. Simplicity: The recursive approach directly follows the definition of the recurrence relation, making it easier to understand and implement.
2. It allows for a straightforward translation of the mathematical relation into code.

* Disadvantages of recursive approach:
1. Inefficiency: The recursive approach suffers from potential exponential time complexity due to redundant computations. It recalculates the same Fibonacci values multiple times, leading to performance issues as n grows larger.

*/
