#include<stdio.h>
#include<stdlib.h>

//Debugging Macro
#define debug() printf("Line number is %d\n",__LINE__);

//Circular Linked List ADT
#include"Clist.h"


//Initialising the linked list
void init(clist *L1){
    *L1 = NULL;
    return;
}

//Inserts a node at end of list
void append(clist *L1,infi data){
    node* newnode = (node*) malloc(sizeof(node));
    //If malloc succeeds
    if(newnode){
        //Initialising the newnode with data
        newnode->data = data;
    }
    else
    {
        printf("MemoryError: Cannot Allocate Memory\n");
        return;
    }
    //Handling Empty List
    if(!(*L1)){
        *L1 = newnode;
        newnode->next = *L1;
        return;
    }
    //Travelling Pointer
    node* traveller = *L1;
    while(traveller->next != *L1){
        //Travelling to the end of list
        traveller = traveller->next;
    }
    //Linking the newnode to list
    traveller->next = newnode;
    newnode->next = *L1;
    return;
}

//Inserts node at beginning of list
void prepend(clist *L1,infi data){
    node* newnode = (node*) malloc(sizeof(node));
    //If malloc succeeds
    if(newnode){
        newnode->data = data;
    }
    else
    {
        printf("MemoryError: Cannot Allocate Memory\n");
        return;
    }
    //Handling empty list
    if(!(*L1)){
        *L1 = newnode;
        newnode->next = *L1;
        return;
    }
    //Travelling pointer
    node* traveller  = *L1;
    //Travelling the entire list
    while(traveller->next != *L1){
        traveller = traveller->next;
    }
    //Linking the node to list
    newnode->next = traveller->next;
    traveller->next = newnode;
    *L1 = newnode;
    return;
}

//Displays the entire list
void display(clist L1){
    node* traveller  = L1;
    printf("[");
    if(traveller){
        //Travelling the whole list
        do{
            //Change the format specifier when you change the typedef
            printf("%d,",traveller->data);
            traveller = traveller->next;
        }while(traveller != L1);
        printf("\b");
    }
    printf("]\n");
}

//Deleting a node in list having certain data
void delete(clist *L1,infi data){
    //Travelling pointers
    node* leader  = *L1;
    node* follower;
    //Searching for the node
    while(leader->data != data && leader->next != *L1){
            follower = leader;
            leader = leader->next;
    }
    // Handling condition when first node is the node to be deleted
    if(leader == *L1){
        follower = *L1;
        while(follower->next != *L1){
            follower = follower->next;
        }
        follower->next = leader->next;
        *L1 = (*L1)->next;
        free(leader);
        return;
    }
    // Normal Deletion 
    else if(leader->data == data){
        follower->next = leader->next;
        free(leader);
        return;
    }
    else{
        printf("Not Found\n");
    }
    return;
}

//Destroying the entire list
void destroy(clist *L1){
    //Travelling pointers
    node* leader  = *L1;
    node* follower;
    //Emptying the entire list
    do{
        follower = leader;
        leader = leader->next;
        free(follower);
    }while(leader !=* L1);
    //Intialising L1 to NULL to avoid dangling
    *L1 = NULL;
    return;
}