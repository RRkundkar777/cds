#include<stdio.h>
#include<stdlib.h>

//Debugging Macro
#define debug() printf("Line number is %d\n",__LINE__);

//Linked List ADT
#include"Slist.h"

//Initialising the list
void init(slist *L1){
    *L1 = NULL;
}

//Inserts a newnode at the end of list
void append(slist *L1,infi data){
    //Allocating a newnode
    node* newnode = (node*) malloc(sizeof(node));
    //Handling malloc failure
    if(!newnode){
        printf("MemoryError: Failed to allocate memory\n");
        // return;
    }
    //Initialising the newnode with data and next pointer
    newnode->data = data;
    newnode->next = NULL;
    //Handling empty list
    if(!(*L1)){
        (*L1) = newnode;
        return;
    }
    else{
        //Linking the newnode to linked list
        node* traveller = (*L1);
        while(traveller->next){
            traveller = traveller->next;
        }
        traveller->next = newnode;
    }
    return;
}

//Inserts a node at beginning of list
void prepend(slist * L1,infi data){
    //Allocating a newnode
    node* newnode = (node*) malloc(sizeof(node));
    //Handling Malloc failure
    if(newnode){
        //Initialising the newnode with data
        newnode->data = data;
        //Linking the newnode with list
        newnode->next = *L1;
        // Making the newnode as head
        *L1 = newnode;
        return;
    }
    printf("MemoryError: Failed to allocate memory\n");
    return;
}

//Displays the entire list while traversing it
void display(slist L1){
    // Travelling pointer
    node* traveller = L1;
    printf("[");
    if(traveller){
        // Traversing the linked slist
        while(traveller){
            // Change the format specifier for multiple data types
            printf("%d,",traveller->data);
            traveller = traveller->next;
        }
        printf("\b");
    }
    printf("]\n");
}

//Deletes a node in a linked list
void delete(slist *L1,infi data){
    //Travelling pointers (leader and follower)
    node* leader = (*L1);
    node* follower;
    //Traversing the linked list to find the element
    while(leader->data != data && leader->next != NULL){
        follower = leader;
        leader = leader->next;
    }
    //Handling the condition when node to be deleted is first node
    if(leader == (*L1)){
        (*L1) = (*L1)->next;
        free(leader);
        return;
    }
    // Handling the condtion when data does not matches the node
    if(leader->next == NULL && leader->data != data)
    {
        printf("Not Found\n");
        return;
    }
    //If node to be deleted is other than first node
    follower->next  = leader->next;
    free(leader);
    return;
}

void destroy(slist* L1){
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