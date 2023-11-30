
#include <iostream>
#include "Employee.h"
#include "File.h"
using namespace std;
namespace sdds {

   int noOfEmployees;
   Employee* employees;


   void sort() {
      int i, j;
      Employee temp;
      for (i = noOfEmployees - 1; i > 0; i--) {
         for (j = 0; j < i; j++) {
            if (employees[j].m_empNo > employees[j + 1].m_empNo) {
               temp = employees[j];
               employees[j] = employees[j + 1];
               employees[j + 1] = temp;
            }
         }
      }
   }

   // TODO: Finish the implementation of the 1 arg load function which
   // reads one employee record from the file and loads it into the employee reference
   // argument
   bool load(Employee& employee) {
      bool ok = false;
      // return the combined success result of the three read functions. These read 
      // functions should set the properties of the reference argument of the load function
      bool okName, okEmpNo, okSalary;

      okEmpNo = read(employee.m_empNo);

      okSalary = read(employee.m_salary);

      okName = read(employee.m_name);

      if (okName && okEmpNo && okSalary) {

          ok = true;
      }
      else {
          
          ok = false;
      }
        
      return ok;
   }
   // TODO: Finish the implementation of the 0 arg load function 
   bool load() {
      
       bool ok = false;

       if (openFile(DATAFILE)) {

           int flag = 0;
           bool okLoad = true;

           noOfEmployees = noOfRecords();

           employees = new Employee[noOfEmployees];

           for (int i = 0; i < noOfEmployees; i++) {

               okLoad = load(employees[i]);

               if (!okLoad) {
                    
                   flag = 1;
                   break;
               }
           }

           if (flag == 1) {

               cout << "Could not open data file: data_file_name" << endl;
           }

           else {

               ok = true;
           }
       }

       else {

           cout << "Could not open data file: data_file_name" << endl;
       }

       closeFile();
 
      return ok;
   }

   // TODO: Implementation for the display functions go here
   void display(const Employee& employee) {

       cout << employee.m_empNo << ": " << employee.m_name << ", $" << (int)employee.m_salary << endl;
   }

   // TODO: Implementation for the deallocateMemory function goes here
   void display() {

       cout << "Employee Salary report, sorted by employee number" << endl;
       cout << "no- Empno, Name, Salary" << endl;
       cout << "------------------------------------------------" << endl;

       sort();

       for (int i = 0; i < noOfEmployees; i++) {

           cout << i + 1 << "- "; 
           display(employees[i]);
       }
   }

   void deallocateMemory() {

       for (int i = 0; i < noOfEmployees; i++) {

           delete[] employees[i].m_name;
       }

       delete[] employees;
   }
}