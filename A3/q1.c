/*****************************
Name: Eli-Henry Dykhne
ID: 0996524
Date 5/11/2018
Assigment name: Assigment 3
Program: q1
******************************/

#include "q1.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stddef.h>

int varListSize;

int main(int argc, char *argv[]){
  var *varList = NULL;
	int command, numVars = 0; 
  varListSize = 0;

	if (argc != 2) {/*makes sure number of arguments is correct*/
    	printf("Error, usage: wrong number of arguments. Expected 1.\n");
    	exit(-1);
  	}
    for(int i = 0; argv[1][i] != '\0';i++){
      if(argv[1][i] == 'x'){
        numVars++;
      }
    }
    varList = malloc(sizeof(var)*numVars);

    node *root = NULL;

  	root = construct(argv[1], varList);

    for(int i = 0; i<numVars;i++){
      printf("Name: %s, Val: %.2f\n",varList[i].name, varList[i].val);
    }
  	do{
  		printf("\n\n1. Display\n"//prompt
		"2. Preorder\n"
		"3. Inorder\n"
		"4. Postorder\n"
		"5. Update\n"
		"6. Calculate\n"
		"7. Exit.\n"
		"Input the number corresponding to the desired action: ");
		scanf("%d[^\n]", &command);//gets user input while protecting program from infinite loops in case of bad user input
		getchar();
  		
  		switch (command){

  			case 1:
          printf("\n\nTree Display (root starts at left side):\n\n");
  				display(root, 0);
  				break;

  			case 2:
  				preorder(root);
  				break;

  			case 3:
  				inorder(root);
  				break;

  			case 4:
  				postorder(root);
  				break;

  			case 5:
          for(int i = 0; i<numVars;i++){
            printf("Name: %s, Val: %.2lf\n",varList[i].name, varList[i].val);
          }

          printf("Enter the variable you would like to modify: (ex: x1): ");
          char sym[10];;
          scanf(" %s", sym);
          printf("%s", sym);

          if(findVar(sym, varList, varListSize)){
            double val;
            printf("Enter the value you would like input: ");
            scanf("%lf", &val);
            findVar(sym, varList, varListSize)->val = val;
          }else{
            printf("This variable does not exist.\n");
          }

  				for(int i = 0; i<numVars;i++){
            printf("Name: %s, Val: %.2lf\n",varList[i].name, varList[i].val);
          }
  				break;
  			case 6:
          inorder(root);
  				printf("= %.2f\n", calculate(root, varList));
  				break;

  			case 7:
  				printf("Quitting\n");
  				break;

  			default:
  				printf("Please enter a valid command.\n");
  				break;
  		}
  	}while(command != 7);

    freeAll(root, varList);
}

void freeAll(node* root, var *varList){
  freeTree(root);
  for(int i = 0; i<varListSize; i++){
    free(varList[i].name);
  }
  free(varList);
}

void freeTree(node *root){
  if(root){
    freeTree(root->right);
    freeTree(root->left);
    free(root->symbol);
    free(root);
  }
}

node * construct(char *input, var *varList){
  int bracketNum = 0,numOps = 0,middleOp = 0;
	node *root = malloc(sizeof(node));
  
  //cycle through to count number of vars to allocate for
  for(int i = 0; input[i] != '\0';i++){

    if(input[i]=='('){
      bracketNum++;
    }else if(input[i]==')'){
      bracketNum--;
    }

    if(input[i]=='+' || input[i]=='-' || input[i]=='*' || input[i]=='/'){
      numOps++;
      if(bracketNum == 1){
        middleOp = i;
      }
    }

    
    //use this loop to cycle through to check for middle operation 
  }

  char sub1[middleOp-1];
  char sub2[strlen(input)-middleOp-2];
  
  if(numOps == 0){//this bit only runs if there are no operations. thus there must be a value
    root->symbol = malloc(sizeof(input));
    strcpy(root->symbol, input);//base case
    root->left = NULL;
    root->right = NULL;
    if(input[0] == 'x'){
      varList[varListSize].name = malloc(sizeof(input));
      strcpy(varList[varListSize].name, input);//base case
      varList[varListSize].val = 0.00;
      varListSize++;
    }
    
  }else{
    char str[2];
    str[0] = input[middleOp];
    str[1] = '\0';
   
    root->symbol = malloc(sizeof(str));
    strcpy(root->symbol, str);//base case
    root->left = NULL;
    root->right = NULL;

    strncpy(sub1, input+1, middleOp);//filling left node
    sub1[middleOp-1] = '\0';
    
    root->left = construct(sub1,varList);
    

    strncpy(sub2, input+1+middleOp, strlen(input)-middleOp-1);//filling right node
    sub2[strlen(input)-middleOp-2] = '\0';
    
    root->right = construct(sub2,varList);

  }
  
  
  
	return root;
}

void preorder(node * root){
	if(root){
		printf("%s", root->symbol);
		preorder(root->left);
		preorder(root->right);
	}
}

void postorder(node * root){
	if(root){
		postorder(root->left);
		postorder(root->right);
		printf("%s", root->symbol);
	}
}

void inorder(node * root){
	if(root->left){
		printf("(");
		inorder(root->left);
	}
	printf("%s", root->symbol);
  if(root->right){
		inorder(root->right);
		printf(")");
	}
}



double add(double first, double second){
  return first+second;
}

double sub(double first, double second){
  return first-second;
}

double muls(double first, double second){
  return first*second;
}

double divs(double first, double second){
  if(second != 0){
    return first/second;
  }else{
    printf("\n!!Divide by zero error. Replaced with 0.00!!\n");
    return 0.00;
  }
}

double findVal(char *sym, var *varList){//loops through to find variable
  
  double item;
  if(sym[0] == 'x'){
    int i = 0;
    while(strcmp(varList[i].name,sym)){
      i++;
    }
    item = varList[i].val;
  }else{
    item = atof(sym);
  }
  
  return item;

}

var * findVar(char *sym, var *varList, int size){
  for(int i = 0; i<size; i++){//loops through to find variable structure

    if(!strcmp(varList[i].name,sym)){

      return &(varList[i]);
    }
  }

  return NULL;

}

double calculate(node *root, var *varList){
  if(!strcmp(root->symbol,"+")){
    return add(calculate(root->left, varList), calculate(root->right, varList));//if addition instruction do addition
  }else if(!strcmp(root->symbol,"-")){
    return sub(calculate(root->left, varList), calculate(root->right, varList));
  }else if(!strcmp(root->symbol,"*")){
    return muls(calculate(root->left, varList), calculate(root->right, varList));
  }else if(!strcmp(root->symbol,"/")){
    return divs(calculate(root->left, varList), calculate(root->right, varList));
  }else if((root->symbol)[0] == 'x'){//if variable, return value of variable
    return findVal(root->symbol, varList);
  }else{
    return atof(root->symbol);//if value, return value
  }

}

void display(node *root, int spacing){
  if(root){
    
    display(root->right, spacing+5);//recursive call with push to move lower nodes right

    printf("\n");
    for(int i = 0; i < spacing; i++){//prints horizontal spacing and pushes lower nodes right
      printf(" ");
    }
    printf("%s\n", root->symbol);

    display(root->left, spacing+5);
  }
}