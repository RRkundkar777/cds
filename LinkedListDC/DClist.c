#include<stdio.h>
#include<stdlib.h>

//Debugging Macro
#define debug() printf("Line number is %d\n",__LINE__);

//Doubly Circular Linked List ADT
#include"DClist.h"


//Initialising the linked list
void init(dclist *L1){
    *L1 = NULL;
    return;
}

// Inserts an element at end of List
void append(dclist* L1,infi data){
    // Creating a newnode 
    node* newnode = (node*) malloc(sizeof(node));
    // Handling Malloc Failure 
    if(newnode){
        // Intialising newnode with data
        newnode->data = data;
    }
    else{
        fprintf(stderr,"MemoryError: Memory Full\n");
        return;
    }
    // Handling Empty List
    if(!*L1){
        *L1 = newnode;
        newnode->prev = newnode;
        newnode->next = newnode;
        return;

    }
    // Linking the newnode 
    (*L1)->prev->next = newnode;
    newnode->prev = (*L1)->prev;
    newnode->next = *L1;
    (*L1)->prev = newnode;
    return;
}

// Inserts an element at beginning of list
void prepend(dclist *L1,infi data){
    // Creating a newnode
    node* newnode = (node*) malloc(sizeof(node));
    // Handling Malloc failure
    if(newnode){
        // Initialising newnode with data
        newnode->data = data;
    }
    else{
        fprintf(stderr,"MemoryError: Memory Full\n");
        return;
    }
    // Handling empty list
    if(!*L1){
        *L1 = newnode;
        newnode->next = newnode->prev = newnode;
        return;
    }
    // Linking the newnode
    (*L1)->prev->next = newnode;
    newnode->prev = (*L1)->prev;
    newnode->next = *L1;
    (*L1)->prev = newnode;
    *L1 = newnode;
    return;
}

// Displays the entire list
void display(dclist L1){
    // Travelling Pointer
    node* traveller = L1;
    printf("[");
    //If list is empty the code will print empty square brackets
    if(traveller){
        do{
            // Change the format specifier when you change the typedef
            printf("%d,",traveller->data);
            traveller = traveller->next;
        }while(traveller!=L1);
        printf("\b");
    }
    printf("]\n");
    return;
}

// Deletes a Specific element from list
void delete(dclist *L1,infi data){
    // Travelling Pointer
    node* traveller = *L1;
    // Travelling to Target Node
    while(traveller->next!= *L1 && traveller->data!=data)
    {
        traveller = traveller->next;
    }
    // When node to be removed is head node
    if(traveller == *L1){
        traveller->next->prev = traveller->prev;
        traveller->prev->next = traveller->next;
        *L1 = (*L1)->next;
        free(traveller);
        return;
    }
    // Handling Element at any other Position
    else if(traveller->data == data){
        traveller->next->prev = traveller->prev;
        traveller->prev->next = traveller->next;
        free(traveller);
        return;
    }
    else{
        fprintf(stderr,"Not Found");
    }
    return;
}

// Destroys the entire list
void destroy(dclist *L1){
    // Travelling Pointers
    node* leader = *L1;
    node* follower;
    // Freeing the nodes one by one
    do{
        follower = leader;
        leader = leader->next;
        free(follower);
    }while(leader!=*L1);
    // Setting L1 to NULL in order to avoid dangling 
    *L1 = NULL;
    return;
}
