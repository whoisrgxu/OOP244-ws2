
#ifndef SDDS_FILE_H_
#define SDDS_FILE_H_

namespace sdds {
   bool openFile(const char filename[]);
   void closeFile();
   int noOfRecords();
   // read name of each employee
   bool read(char*& name);

   // read employee numbers
   bool read(int& empNo);

   // read employee salaries
   bool read(double& salary);

}

#endif // !SDDS_FILE_H_