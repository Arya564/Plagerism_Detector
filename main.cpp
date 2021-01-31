#include "helper.h"
int arraySize;

int getdir (string dir, vector<string> &files) {
  DIR *dp;
  struct dirent *dirp;
  if((dp  = opendir(dir.c_str())) == NULL) {
    cout << "Error(" << errno << ") opening " << dir << endl;
    return errno;
  }
  
  while ((dirp = readdir(dp)) != NULL) {
    files.push_back(string(dirp->d_name));
  }
  closedir(dp);
  return 0;
}

//NO CLASSES, OBJECTS NECESSARY THATS A BET
//JUST MAKE HELLA FUNCTIONS

//*******************************************************************************************************
//*******************************************************************************************************
/*  ALGORITHM:
 *
 *  GO THROUGH EACH TEXT FILE AND THEN CLEAN THEM IN THE VECTORS
 *  PUT EACH SEQUENCE THROUGH A HASH FUNCTION
 *  ONCE HASH TABLE HAS BEEN CREATED WITH THE VALUES, PUT NUMBER OF COLLISIONS into 2D array (25 by 25)
 *  AND THEN JUST SORT AND STUFF
 *  THIS SHOULD BE A DUB LETS GET IT
 *
 */
//*******************************************************************************************************
//*******************************************************************************************************


int main(int argc, char *argv[]) {
  
  if (argc < 2) {
    cout << "ERROR: enter directory name as an argument" << endl;
    return (0);
  }

  if(argc < 4){
      cout << "ERROR: not enough arguments" << endl;
      return (0);
  }

  string dir = argv[1]; //argv[1] was sm_doc_set
  vector<string> files = vector<string>();
  string str;

  getdir(dir,files);    //this puts all of the text files in the VECTOR


  //THIS IS JUST FOR PRINTING PURPOSES
  //ALSO INDEX 0 AND 1 ARE IRRELEVANT, START AT INDEX 2
//  for (unsigned int i = 2; i < files.size(); i++) {
//    // ignore . and ..
//    cout << files[i] << endl;
//  }

  //FOR THE P VALUE, JUST FOR TESTING THO
  //MAKE SURE TO PUT ON COMMAND LINE LATER
  //int words = 6;
  //int limit = 200;

  int words = atoi(argv[2]);
  int limit = atoi(argv[3]);

  storeEssays(files);

  //READS ALL OF THE FILES AND PUTS SEQUENCES INTO HASH TABLE
  readFiles(files, dir, words);

  cout << endl;
  cout << "RESULTS: " << endl;
  cout << endl;
  checkCollisions(files, limit);
  cout << endl;

  return 0;
}
