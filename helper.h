//
// Created by mongo on 11/24/2020.
//


#ifndef CHEATERS_HELPER_H
#define CHEATERS_HELPER_H



#include <sys/types.h>
#include <dirent.h>
#include <errno.h>

#include <sstream>
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <stdio.h>
#include <cstdlib>
#include "string.h"
#include <algorithm>
#include <utility>
#include <iterator>
#include <map>
#include <functional>

using namespace std;



/*READS THE FILES, TAKES OUT P WORDS AT A TIME

Function: Reads each file, creates the p-word sequences, cleans them through helper function
and then puts each sequence into hash table.
Preconditions: Text files have been placed into a vector and p-value has been determined by the user.
Postconditions: Every file has been read and the p-word sequences have been cleaned
and placed into a hash table.

 */
void readFiles(vector<string> &vec, string dir, int words);

//CLEANS THE FILES, MAKES LOWERCASE, ETC.

/*

Function: Cleans the sequences by making them lowercase, keeping numbers, letters, and apostrophes.
Preconditions: A p-word sequence has to have been created to then be passed in
Postconditions: The p-word sequences will be cleaned and placed into a a hash table

 */
void cleanSequence(vector<string> &vec, vector<string> &textFile, int location);

/*

Function: Initializes vector of vector of type int (equivalent to 2D array) and a map that associates a value
with each text file.
Preconditions: The text files should be in a vector to be passed in.
Postconditions: The vector of vector will be initialzied with the appropriate amount of rows/columns based on
amount of text files, and the map will also store the text files with a specific value.

 */
void storeEssays(vector<string> &vec);

/*

Function: Iterates through the entire hash table and counts the number of similarities between each
pair of text files (with 25 essays there will be 300 pairs).
Preconditions: The m-value needs to be set by user and the hash table should have all collisions filled up
from every sequence from every text file.
Postconditions: Prints out a sorted list of similarities between certain text files that are above
the threshold (m- value) that was passed in.

 */
void checkCollisions(vector<string> &vec, int limit);

#endif //CHEATERS_HELPER_H