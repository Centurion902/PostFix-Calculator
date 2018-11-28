/*****************************
Name: Eli-Henry Dykhne
ID: 0996524
Date 5/11/2018
Assigment name: Assigment 3
Program: q1
******************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stddef.h>

#ifndef Q1_H
#define Q1_H

typedef struct node{
    char *symbol;
    struct node *left;
    struct node *right;
} node;

typedef struct var{
    char *name;
    double val;
} var;

/*
Function: recursively constructs the binary tree representing the equation and fills the varlist with variables
*/
node * construct(char *input, var *varList);

/*
Function: prints the equation in preorder notation
*/
void preorder(node * root);

/*
Function: prints the equation in postorder notation
*/
void postorder(node * root);

/*
Function: prints the equation in inorder notation (with brackets)
*/
void inorder(node * root);

/*
Function: returns the pointer to the specific variable struct
*/
var * findVar(char *sym, var *varList, int size);

/*
Function: gets value of specific variable struct
*/
double findVal(char *sym, var *varList);

/*
Function: adds two values
*/
double add(double first, double second);

/*
Function: subtract two values
*/
double sub(double first, double second);

/*
Function: multiplies two values
*/
double muls(double first, double second);

/*
Function: divides two values if possible, else returns 0;
*/
double divs(double first, double second);

/*
Function: recursively calculates value of function
*/
double calculate(node *root, var *varList);

/*
Function: prints tree
*/
void display(node *root, int spacing);

/*
Function: frees tree and variableList
*/
void freeAll(node* root, var *varList);

/*
Function: frees tree recursively
*/
void freeTree(node *root);


#endif
