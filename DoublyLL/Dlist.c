#include<stdio.h>
#include<stdlib.h>

//Debugging Macro
#define debug() printf("Line number is %d\n",__LINE__);

// Doubly Linked List ADT 
#include"Dlist.h"


//Initialises the linked list with NULL
void init(dlist *L1){
    *L1 = NULL;
}

// Inserts a newnode at end of list 
void append(dlist *L1,infi data){
    node* newnode = (node*) malloc(sizeof(node));
    //If malloc succeeds
    if(newnode){
        //Initialising newnode with data and null
        newnode->data = data;
        newnode->next = NULL;
    }
    else{
        printf("MemoryError: Cannot Allocate Memory\n");
    }
    //Handling empty list
    if(!*L1){
        *L1 = newnode;
        newnode->prev = NULL;
        return;
    }
    //Travelling to end of list
    node* traveller = *L1;
    while(traveller->next){
        traveller = traveller->next;
    }
    //Linking the newnode
    traveller->next = newnode;
    newnode->prev = traveller;
    return;
}

//Inserts a node at beginning of a list
void prepend(dlist *L1,infi data){
    node* newnode = (node*) malloc(sizeof(node));
    //If malloc succeeds
    if(newnode){
        //Intialising newnode with data and pointer
        newnode->data = data;
        newnode->prev = NULL;
    }
    else{
        printf("MemoryError: Cannot Allocate Memory\n");
    }
    //Handling empty list
    if(!*L1){
        *L1 = newnode;
        newnode->prev = NULL;
    }
    //Linking the newnode
    (*L1)->prev = newnode;
    newnode->next = *L1;
    (*L1) = newnode;
    return;
}

//Displays the entire list
void display(dlist L1){
    //Travelling Pointer
    node* traveller = L1;
    printf("[");
    if(traveller){
        while(traveller){
            //Change the format specifier when you change the typedef
            printf("%d,",traveller->data);
            traveller = traveller->next;
        }
        printf("\b");
    }
    printf("]\n");
    return;
}

//Deleting a node with a certain data
void delete(dlist *L1,infi data){
    //Travelling pointers (leader and follower)
    node* leader = (*L1);
    node* follower;
    //Traversing the linked list to find the element to be deleted
    while(leader->data != data && leader->next != NULL){
        follower = leader;
        leader = leader->next;
    }
    //Handling the condition when node to be deleted is first node
    if(leader == *L1){
        (*L1)->next->prev = NULL;
        *L1  = (*L1)->next;
        free(leader);
        return;
    }
    //Handling the condition when node to be deleted is last node
    else if(leader->next == NULL && (leader->data==data)){
        follower->next = NULL;
        free(leader);
        return;
    }
    //Deleting the node when it is at intermediate positiion
    else if(leader->data == data){     
        leader->next->prev = follower;
        follower->next = leader->next;
        free(leader);
        return;
    }
    else{
        printf("Not Found\n");
        return;
    }
}

void destroy(dlist* L1){
    //Travelling pointers
    node* leader = (*L1);
    node* follower;
    //Traversing and destroying the whole list
    while(leader){
        follower = leader;
        leader = leader->next;
        free(follower);
    }
    //Preventing Dangling Pointer
    (*L1) = NULL;
    return;
}