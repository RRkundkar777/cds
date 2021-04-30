# Data Structures and Algorithms
My Repository containing the Data Structures and Algorithms I learnt.

## Why algorithms?

- A computer is a dumb piece of hardware that needs to be instructed by the programmer.
- This set of instructions is called a program.
- An algorithm is a finite set of well defined steps, designed to perform a specific task.
- A computer program contains one or more than one algorithm implemented in it.

## Data Structures

- Data Structure is a way of organising data in computer for efficient access and management

## Why Data Structures?
- Data Structures are the essential ingredients of an efficient algorithm.
- An algorithm may work faster or slower depending upon the organisation of data in computer.

## Memory Layout of a C program
<img src="https://open4tech.com/wp-content/uploads/2017/04/Memory_Layout.jpg">

## Space Complexity of an Algorithm
### Auxiliary Space
```
Auxiliary Space is the extra space or temporary space used by an algorithm.
For Example, swapping of two variables requires an extra 'temp' variable.
```
```
Space Complexity of an algorithm is total space taken by the algorithm with respect to the
input size. 
It includes both Auxiliary space and the space used by input. 
```
Space complexity is the study of efficiency of algorithms.

In present world, having a terrabyte disk space is very common. Therefore space complexity is
of little significance.


## Time Complexity of an algorithm
Like space complexity, the time complexity is also a study of efficiency of algorithms.
```
Time complexity is the study of growth of execution time of algorithm with respect to
the size of input.
As most the algorithms are of the format Input --> Process --> Output, the Time complexity
measures the time of Process as a function of Input.
```

## Asymtotic Analysis
```
In Asymptotic Analysis, we evaluate the performance of an algorithm in terms of input size .
We calculate, how the time or space taken by an algorithm increases with the input size.
```

## Why Asymtotic analysis?
```
Comparing two algorithms isnt easy. Because the execution speed of an algorithm does not depend
only on the input size. It also depends on the processor speed, memory access speed and lots
of other factors.
Therefore comparing two algorithms by directly executing them on machine does not provide an
unambigous information on which algorithm is faster.
Asymptotic Analysis is not perfect, but that’s the best way available for analyzing algorithms.
```

## Best, Average and Worst case complexities
### Worst Case Complexity
```
In the worst case analysis, we calculate upper bound on running time of an algorithm. 
We must know the case that causes maximum number of operations to be executed.
For Example, in Linear Search, the worst case happens when the element to be searched 
is not present in the array. When this happens, the algorithm compares all the elements of
the array one by one.Therefore, the worst case time complexity of linear search would be Θ(n).
```
### Best Case Complexity
```
In the best case analysis, we calculate lower bound on running time of an algorithm. 
We must know the case that causes minimum number of operations to be executed. 
For Example, in the linear search, the best case occurs when element to be searched is present at the first location. The number of operations in the best case is constant (not dependent on n).
So time complexity in the best case would be Θ(1) 
```
### Average Case Complexity
```
In average case analysis, we take all possible inputs and calculate computing time for all of the inputs. Sum all the calculated values and divide the sum by total number of inputs. We must know (or predict) distribution of cases. For the linear search problem, let us assume that all cases are uniformly distributed (including the case of x not being present in array). So we sum all the cases and divide the sum by (n+1). Following is the value of average case time complexity. 
```
