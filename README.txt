Name: Arya Amin
UT EID: aa82356
Class ID: #16010
Date: 12/3/2020

********************
PROGRAM DESCRIPTION:
********************

For this project, the program will take in a directory (folder of essays), a p-value, and an m-value as the command
line arguments from the user. The p-value is an integer that determines how many words will be in each sequence when
parsing through the essays, and the m-value is the threshold that determines which pairs of essays will get outputted
in the end. When reading each essay, the goal is to take in every p-word sequence from every essay, and then compare
the number of similarities in p-word sequences between the essays. These comparisons are done in pairs and the output
of the program will be the number of similarities between certain pairs that are greater than the m-value. Also,
these p-word sequences are put through a hashing function that helps in finding these similarities. To conclude,
the pairs will be sorted in descending order so that the pair with the most similarities in p-word sequences will
be at the top.


*************
Source Files:
*************

main.cpp
helper.h
helper.cpp

****************************
WHEN TYPING ON COMMAND LINE:
****************************
MAKE SURE TO TYPE IN THE FORM OF ./plagiarismCatcher sm_doc_set 6 200
WHERE 6 WOULD BE THE p-value and 200 WOULD BE THE m-value

***********************************
Instructions on how to run program:
***********************************

1) Unzip the file
2) Type in make
3) Run ./plagiarismCatcher
4) Once the program starts, it will output a specific set of results describing the similarities between
pairs of text files depending on the inputs of 'p' and 'm'.