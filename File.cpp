
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstring>
#include "File.h"

namespace sdds {
   FILE* fptr;
   bool openFile(const char filename[]) {
      fptr = fopen(filename, "r");
      return fptr != NULL;
   }
   int noOfRecords() {
      int noOfRecs = 0;
      char ch;
      while (fscanf(fptr, "%c", &ch) == 1) {
         noOfRecs += (ch == '\n');
      }
      rewind(fptr);
      return noOfRecs;
   }
   void closeFile() {
      if (fptr) fclose(fptr);
   }
   // read name of each employee
   bool read(char*& name) {
       
       char tempName[128];

       if (fscanf(fptr, "%127[^\n]\n", tempName) == 1) {

            int length = strlen(tempName);

            name = new char[length + 1];

            strcpy(name, tempName);
               
            return true;
       }
       return false;

   }

   // read employee numbers
   bool read(int& empNo) {

        if (fscanf(fptr, "%d,", &empNo) == 1) {

            return true;
        }

        return false;

   }

   // read employee salaries
   bool read(double& salary) {

        if (fscanf(fptr, "%lf,", &salary) == 1) {

            return true;
        }
        return false;

   }
}