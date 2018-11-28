/*****************************
Name: Eli-Henry Dykhne
ID: 0996524
Date 5/11/2018
Assigment name: Assigment 3
Program: q2
******************************/

#include "q2.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stddef.h>

int main(){
	FILE *file = fopen("f.dat", "r+");/*opens file to read*/
	char transfer[3];
	int **heap;
	heap = malloc(sizeof(int*)*21);//allocating space for the matrix. this structure lets me more easaly manipulate the rows
	for(int i = 1; i<21; i++){//leaving first space empty for heap construction to work
		heap[i] = malloc(sizeof(int)*10);
		for(int j = 0; j<10; j++){
			fread(transfer, sizeof(char), 3, file);
			heap[i][j] = atoi(transfer);//parsing and loading string into heap
		}
	}

	for(int i = 20; i>0; i--){//downheap
		printf("Downheap with %d\n", i);
		downHeap(heap, i, 20);
	}

	for(int i = 1; i<21; i++){//leaving first space empty for heap construction to work
		//printing out
		for(int j = 0; j<10; j++){
			
			printf("%02d ", heap[i][j]);
		}
		free(heap[i]);
		printf("\n");
	}
	free(heap);
	fclose(file);
}

/*
Function: returns the key of the row by summing the first three values
*/
int getKey(int *arr){
	return arr[0]+arr[1]+arr[2];
}

/*
Function: recursively preforms downheap by swapping larger parents with smallest children
*/
void downHeap(int **heap, int index, int heapSize){
	int *temp;
	if(index*2>heapSize||index == 0){
		//not great structure but im too scared to touch working code for fear it may break
		return;
	}else if(index*2+1>heapSize){//no need to check both if one is out of range

		if(getKey(heap[index])>getKey(heap[index*2])){
			temp = heap[index];//swap
			heap[index] = heap[index*2];
			heap[index*2] = temp;
			downHeap(heap, index*2, heapSize);
		}
		return;
	}else{
		if(getKey(heap[index])>getKey(heap[index*2])&&getKey(heap[index*2])<=getKey(heap[index*2+1])){//makes sure switch is happening with the lowest key

			temp = heap[index];
			heap[index] = heap[index*2];
			heap[index*2] = temp;
			downHeap(heap, index*2, heapSize);
		}else if(getKey(heap[index])>getKey(heap[index*2+1])&&getKey(heap[index*2+1])<=getKey(heap[index*2])){

			temp = heap[index];
			heap[index] = heap[index*2+1];
			heap[index*2+1] = temp;
			downHeap(heap, index*2+1, heapSize);
		}
		return;
	}
}

