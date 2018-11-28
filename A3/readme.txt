/*****************************
Name: Eli-Henry Dykhne
ID: 0996524
Date 5/11/2018
Assigment name: Assigment 3
******************************/
q1: This program takes 1 command line argument. Please deliver this argument either with backslashes in front
of all brackets, or within quotations. (prefer quotations because it is harder to make mistakes that way). 


When using option 1(display), the tree will be displayed sideways with the root at the very left. No excplicit
connections are visible, but can be infered from the position of each symbol. children are always one level
down and to the imidiate right and left. Only as much space as is nescesary is taken leading to trees with 
large right and small left sides (or vice versa) to look unbalanced. 

Divide by zero errors are caught. The rest (such as invalid input may cause crashes). When updating a variable,
it must be searched for with its full name. (ex: x1). Its value is changed but it is still there and is still 
printed the same way, so its value may be further updated.


START SAMPLE OUTPUT
____________________________________________________________________________


cent@cent-ThinkPad-E570:~/Documents/CIS2520/A3$ ./q1 "(((7+x1)-8)/x2)"
Name: x1, Val: 0.00
Name: x2, Val: 0.00


1. Display
2. Preorder
3. Inorder
4. Postorder
5. Update
6. Calculate
7. Exit.
Input the number corresponding to the desired action: 1


Tree Display (root starts at left side):


     x2

/

          8

     -

               x1

          +

               7


1. Display
2. Preorder
3. Inorder
4. Postorder
5. Update
6. Calculate
7. Exit.
Input the number corresponding to the desired action: 2
/-+7x18x2

1. Display
2. Preorder
3. Inorder
4. Postorder
5. Update
6. Calculate
7. Exit.
Input the number corresponding to the desired action: 3
(((7+x1)-8)/x2)

1. Display
2. Preorder
3. Inorder
4. Postorder
5. Update
6. Calculate
7. Exit.
Input the number corresponding to the desired action: 4
7x1+8-x2/

1. Display
2. Preorder
3. Inorder
4. Postorder
5. Update
6. Calculate
7. Exit.
Input the number corresponding to the desired action: 5
Name: x1, Val: 0.00
Name: x2, Val: 0.00
Enter the variable you would like to modify: (ex: x1): x2
x2Enter the value you would like input: 7.5
Name: x1, Val: 0.00
Name: x2, Val: 7.50


1. Display
2. Preorder
3. Inorder
4. Postorder
5. Update
6. Calculate
7. Exit.
Input the number corresponding to the desired action: 6
(((7+x1)-8)/x2)= -0.13


1. Display
2. Preorder
3. Inorder
4. Postorder
5. Update
6. Calculate
7. Exit.
Input the number corresponding to the desired action: 7
Quitting


____________________________________________________________________________

END SAMPLE OUTPUT




q2: q2 reads from a file f.dat that must be stored in the same folder. The sample file given to us will be 
supplied but if you wish to use your own file, please be sure to name it f.dat. The program takes no command
line arguments. It may be run with ./q1


START SAMPLE OUTPUT
____________________________________________________________________________

cent@cent-ThinkPad-E570:~/Documents/CIS2520/A3$ ./q2
Downheap with 20
Downheap with 19
Downheap with 18
Downheap with 17
Downheap with 16
Downheap with 15
Downheap with 14
Downheap with 13
Downheap with 12
Downheap with 11
Downheap with 10
Downheap with 9
Downheap with 8
Downheap with 7
Downheap with 6
Downheap with 5
Downheap with 4
Downheap with 3
Downheap with 2
Downheap with 1
01 07 00 99 37 50 93 57 06 29 
03 04 03 60 76 23 14 81 82 00 
09 08 08 03 44 27 68 96 70 98 
09 09 05 09 09 88 56 59 88 39 
09 08 04 02 09 00 81 30 16 65 
28 50 09 06 44 59 87 32 36 36 
46 08 03 02 03 01 01 04 08 07 
09 06 09 05 00 03 04 04 00 00 
38 04 09 83 22 90 74 56 64 75 
43 27 20 59 04 84 10 42 43 02 
04 41 62 82 46 69 42 74 68 79 
91 92 39 25 41 11 88 15 39 88 
69 31 49 00 03 07 07 03 06 04 
81 14 42 21 09 69 05 30 20 91 
85 13 25 47 51 90 37 86 42 44 
48 64 41 01 01 06 04 07 09 09 
25 12 17 82 52 53 05 03 68 64 
30 44 59 49 72 49 17 44 32 33 
54 60 33 51 87 01 02 00 08 08 
67 55 04 01 02 03 00 09 04 04 


______________________________________________________________________

END SAMPLE OUTPUT