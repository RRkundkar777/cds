#include<iostream>
#include<bits/stdc++.h>

using namespace std;

void SieveOfEratosthenes(int number) 
{ 
    // Create a boolean array "prime[0..n]" and initialize 
    // all entries it as true. A value in prime[i] will 
    // finally be false if i is Not a prime, else true. 
    bool primearray[number+1]; 
    memset(primearray, true, sizeof(primearray)); 
    
    //Marking the multiples of Prime numbers as composites
    for (int num=2; num*num<=number; num++) 
    { 
        // If prime[p] is not changed, then it is a prime 
        if (primearray[num] == true) 
        { 
            // Updating all multiples of p greater than or  
            // equal to the square of it 
            // numbers which are multiple of p and are 
            // less than p^2 are already been marked.  
            for (int i=num*num; i<=number; i += num) 
                primearray[i] = false; 
        } 
    } 
  
    // Printing all prime numbers 
    for (int num=2; num<=number; num++) 
       if (primearray[num]) 
          cout << num << " "; 
} 
