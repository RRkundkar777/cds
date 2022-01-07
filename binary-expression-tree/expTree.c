#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

// Stack of Tree Nodes (Include Guard to Handle recursive Inclusion)
#ifndef TREESTACK_H
#define TREESTACK_H
#include "treeStack.h"
#endif

// Stack of Character Nodes (Include Guard to Handle recursive Inclusion)
#ifndef CHARSTACK_H
#define CHARSTACK_H
#include "charStack.h"
#endif

// Binary Expression Tree ADT (Include Guard to Handle recursive Inclusion)
#ifndef EXPTREE_H
#define EXPTREE_H
#include "expTree.h"
#endif

//Debugging Macro
#define debug() printf("Line number is %d\n", __LINE__);

// Boolean Enum
enum
{
    true = 1,
    false = 0
};

// Utility Function to check if character is an operator
int isOperator(char chr)
{
    if (chr == '+' || chr == '-' || chr == '*' || chr == '/' || chr == '^')
    {
        return true;
    }
    return false;
}

// Utility function to create a new node with data initialised to a character
Tnode *createNode(infi data)
{
    Tnode *newnode = (Tnode *)malloc(sizeof(Tnode));
    newnode->left = newnode->right = NULL;
    newnode->data = data;
    return newnode;
};

int prec(char operator)
{
    switch (operator)
    {
    case '^':
        return 3;
        break;
    case '*':
        return 2;
        break;
    case '/':
        return 2;
    case '+':
        return 1;
        break;
    case ')':
        return 0;
        break;
    default:
        return -1;
        break;
    }
}

int length(char *exp)
{
    int i = 0;
    while (*(exp + i) != '\0')
    {
        i++;
    }
    return i;
}

Tnode *build(char *exp)
{
    stack Nstack;
    initStack(&Nstack);

    charStack Cstack;
    initCharStack(&Cstack);

    Tnode *t, *t1, *t2;
    int expSize = length(exp);

    for (int i = 0; i < expSize; i++)
    {
        if (exp[i] == '(')
        {

            // Push '(' in char stack
            pushChar(&Cstack, exp[i]);
        }

        // Push the operands in node stack
        else if (isalnum(exp[i]))
        {
            t = createNode(exp[i]);
            push(&Nstack, t);
        }

        else if (prec(exp[i]) > 0)
        {
            // If an operator with lower or
            // same associativity appears
            while (
                !isEmpty(Cstack) && CstackTop(Cstack) != '(' && ((exp[i] != '^' && prec(CstackTop(Cstack)) >= prec(exp[i])) || (exp[i] == '^' && prec(CstackTop(Cstack)) > prec(exp[i]))))
            {

                // Get and remove the top element
                // from the character stack
                t = createNode(CstackTop(Cstack));
                popChar(&Cstack);

                // Get and remove the top element
                // from the node stack
                t1 = stackTop(Nstack);
                pop(&Nstack);

                // Get and remove the currently top
                // element from the node stack
                t2 = stackTop(Nstack);
                pop(&Nstack);

                // Update the tree
                t->left = t2;
                t->right = t1;

                // Push the node to the node stack
                push(&Nstack, t);
            }

            // Push s[i] to char stack
            pushChar(&Cstack, exp[i]);
        }

        else if (exp[i] == ')')
        {
            while (!isEmpty(Cstack) && CstackTop(Cstack) != '(')
            {
                t = createNode(CstackTop(Cstack));
                popChar(&Cstack);
                t1 = stackTop(Nstack);
                pop(&Nstack);
                t2 = stackTop(Nstack);
                pop(&Nstack);
                t->left = t2;
                t->right = t1;
                push(&Nstack, t);
            }
            popChar(&Cstack);
        }
    }
    t = stackTop(Nstack);
    return t;
}

// Recursive Function for InOrder Traversal
void inOrder(expTree T1)
{
    if (T1 == NULL)
    {
        return;
    }
    else
    {
        // Go To the Left Subtree
        inOrder(T1->left);
        // Change the format for multiple data types
        printf("%c ", T1->data);
        // Go To the Right Subtree
        inOrder(T1->right);
    }
}

void postorder(expTree root)
{
    if (root) 
    {
        postorder(root->left);
        postorder(root->right);
        printf("%c ",root->data);
    }
}

int main(int argc, char const *argv[])
{
    char *exp = "1+2*3";
    Tnode* t1 = build(exp);
    postorder(t1);
   

    return 0;
}
