#include<stdio.h>
#include<stdlib.h>

//Debugging Macro
#define debug() printf("Line number is %d\n",__LINE__);

// Array ADT
#include"array.h"

// Initialising the array with total size 
void init(array *A1,int tsize){
    //Intialising the total and used size
    A1->used_size = 0;
    A1->total_size = tsize;
    //Allocating required memory for array using malloc
    A1->start = (infi*) malloc(sizeof(infi)*(A1->total_size));
}

//Appending the Array
void append(array *A1, infi data){
    //Handling Filled Array
    if(A1->used_size == A1->total_size){
        printf("IndexError: Array Overflow Detected\n");
        return;
    }
    //Appending to the Array
    A1->start[A1->used_size] = data;
    A1->used_size++;
    return;
}

//Displaying the array as a list
void display(array A1){
    printf("[");
    //Printing the array
    if(A1.used_size){
        //NOTE: PLEASE CHANGE THE FORMAT SPECIFIER FOR DIFFERENT DATA TYPES
        for(int i = 0; i <= (A1.used_size); i++){
            printf("%d,",A1.start[i]);
        }
        printf("\b");
    }
    printf("]\n");
    return;
}

//Inserting at a position
void insert(array *A1,INT position,infi data){
    //Handling Index out of Bounds
    if(position > A1->total_size){
        printf("IndexError: Index out of bounds\n");
        return;
    }
    //Inserting array element
    A1->start[position] = data;
    //If position is greater than used size,then we have to reinitialise used size as position
    if(position>A1->used_size){
        A1->used_size = position;
    }
    return;
}
