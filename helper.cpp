//
// Created by mongo on 11/24/2020.
//


#include "helper.h"

const int hashSize = 50021;


//MAKE A VECTOR OF VECTORS
vector<vector<int>> storeArray;


//ARRAY OF VECTORS for my hash table
vector<string> hashArray[50021];

//STORES THE ESSAYS AT A PROPER INDEX
//MAKES IT EASIER FOR PUTTING STUFF IN THE ARRAYS

map<string, int> testMap;
map<int, string> essayKey;


//THESE ARE FOR THE SORTING PROCESS
vector<int> collisionStorage;   //we will sort the integers in here
map<int, string> rowStorage;
map<int, string> columnStorage;


void readFiles(vector<string> &vec, string dir, int words){



    //PROBABLY WILL HAVE TO CLEAR ALL OF THE VALUES WITHIN THE VECTORS FOR EVERY ITERATION
    //make a vector of strings for CLEANING
    vector<string> clean;
    int wordCount = 0;

    string sequence = "";


    for(unsigned int i = 2; i < vec.size(); i++){

        ifstream input("./" + dir + "/" + vec[i]);
        //char data;
        if(input.is_open()){

              //THIS GETS EVERY WORD IN THE TEXT FILE
              while(input >> sequence){
                  if(wordCount == words){
                      cleanSequence(clean, vec, i);
                      wordCount--;
                  }
                  clean.push_back(sequence);    //pushing back every string until we have P-WORD sequences
                  wordCount++;
              }

            cleanSequence(clean, vec, i);   //do this one for the last clean

            clean.clear();  //make sure we clear the vector so its ready for NEXT FILE
            wordCount = 0;  //set back to zero
            input.close();
        }
    }
}


void cleanSequence(vector<string> &vec, vector<string> &textFile, int location){

    string unique;  //CLEAN EACH STRING USING THIS VARIABLE
    string result = "";  //append and store the sequences in the RESULT
    int flag = 0;   //turn flag on if the text file is already in the VECTOR

    for(unsigned int i = 0; i < vec.size(); i++){
        unique = vec[i];
        transform(unique.begin(), unique.end(), unique.begin(), ::tolower); //makes every string lowercase

        //REMOVES ALL SPECIAL CHARACTERS, NUMBERS, EXCEPT FOR APOSTROPHE
        for(unsigned int j = 0; j < unique.size(); j++) {

            if ((unique[j] != 39) && (unique[j] < 'a' || unique[j] > 'z') && (unique[j] < '0' || unique[j] > '9')) {
                unique.erase(j, 1);
                j--;
            }
        }

        vec[i] = unique;
        result += unique;   //HAVE FULLY APPENDED THE SEQUENCES
    }

    //HASH FUNCTION FOR STRINGS
    hash<string> hasher;
    auto hashed = hasher(result);
    hashed = hashed % hashSize;    //to find the key

    //YOU WANT TO CHECK IF THE TEXT FILE IS IN THERE ALREADY IF IT IS, DONT PUSH AND JUST IGNORE ITS CHILL
    for(string essayString : hashArray[hashed]){
        if(essayString == textFile[location]){
            flag = 1;
            break;
        }
    }

    //IF FILE IS NOT IN VECTOR
    if(flag == 0){
        hashArray[hashed].push_back(textFile[location]);
    }

    //remove the first string and add a new one to the sequence
    auto remove = vec.begin();
    vec.erase(remove);
}


void storeEssays(vector<string> &vec){

    //FOR INITIALIZING THE MAP
    int count = 0;
    for (unsigned int i = 2; i < vec.size(); i++) {
        testMap.insert(pair<string, int>(vec[i], count));   //string is the key
        essayKey.insert(pair<int, string>(count, vec[i]));  //integer is the key
        count++;
    }

    //MIGHT AS WELL INITIALIZE THE 2D VECTOR HERE
    for(int x = 0; x < count; x++){
        vector<int> v1;

        for(int y = 0; y < count; y++){
            v1.push_back(0);
        }
        storeArray.push_back(v1);
    }

}


void checkCollisions(vector<string> &vec, int limit){

    int temp;

    for(auto i = 0; i < hashSize; i++){

        //if empty just go to next iteration
        if(hashArray[i].empty()){
            continue;
        }


        for(auto j = hashArray[i].begin(); j != hashArray[i].end(); j++){
            for(auto k = j + 1; k != hashArray[i].end(); k++){

                //we have to associate the essays with an integer value right??

                int row = testMap.at(*j);
                int column = testMap.at(*k);

                //JUST IN CASE ROW IS GREATER THAN COLUMN, WE DONT WANT THAT!!!!
                if(row > column){
                    temp = row;
                    row = column;
                    column = temp;
                }

                //INCREMENT THE COLLISIONS BETWEEN THE
                int count = storeArray[row][column];
                count++;
                storeArray[row][column] = count;

            }
        }
    }


    //THIS THE FINAL PART
    //ITERATE THROUGH HASH TABLE, TAKE OUT PAIRS ABOVE 200

    for(unsigned int x = 0; x < storeArray.size(); x++){
        for(unsigned int y = x + 1; y < storeArray.size(); y++){

            if(storeArray[x][y] > limit){
                collisionStorage.push_back(storeArray[x][y]);   //push the number back

                //TO GET THE NAMES OF THE STRINGS
                string roww = essayKey.at(x);
                string columnn = essayKey.at(y);

                rowStorage.insert(pair<int, string>(storeArray[x][y], roww));
                columnStorage.insert(pair<int, string>(storeArray[x][y], columnn));

            }
        }
    }

    //SORTS IN DESCENDING ORDER
    sort(collisionStorage.begin(), collisionStorage.end(), greater<int>()); //sorts the vector full of collisions



    //THE PROBLEM STARTS HERE FOR SOME REASON
    for(unsigned int z = 0; z < collisionStorage.size(); z++){
        cout << collisionStorage[z] << ": " << rowStorage.at(collisionStorage[z]) << " ";
        cout << columnStorage.at(collisionStorage[z]) << endl;
    }

    cout << endl;
}
