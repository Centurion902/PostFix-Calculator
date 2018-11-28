/*****************************
Name: Eli-Henry Dykhne
ID: 0996524
Date 15/10/2018
Assigment name: Assigment 2
Program: q2
******************************/

#ifndef Q2_H
#define Q2_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stddef.h>

/*
Function: returns the key of the row by summing the first three values
*/
int getKey(int *arr);

/*
Function: recursively preforms downheap by swapping larger parents with smallest children
*/
void downHeap(int **heap, int index, int heapSize);

#endif
