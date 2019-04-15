# include <fstream>
# include <iostream>
# include <cstdlib> 
# include <string>
# include <cassert>
# include <stdio.h>
# include <unistd.h>
# include <ctype.h>
using namespace std; 

/**
 * Author: Suryansh soni 
 * email: szs0177@auburn.edu
 * 04/05/2019
 * 
 * hw4.cpp
 * 
 */


const int MAX_SIZE = 100;


int readFile(int inputArray[], ifstream& instream);
int sort(int inputArray1[], int inputArray1_size, int inputArray2[], int inputArray2_size, int outputArray[]);
void writefile(int outputArray[], int outputArray_size, string name);

int readfile(int inputArray[], ifstream& instream) {
   if (instream.fail()) {
      cout << "Input file opening failed." << endl;
      return -1;
   }
   int ii = 0;
   instream >> inputArray[ii];
   while (! instream.eof()) {
     
      ii++;
      instream >> inputArray[ii];
   }
   return ii;
}

int sort(int inputArray1[], int inputArray1_size, int inputArray2[], int inputArray2_size, int outputArray[]) {
   int ii = 0;

   int p = 0;

   int l = 0;

   int n = 0;
   
   while (ii < inputArray1_size && p < inputArray2_size) {
      if (inputArray1[ii] <= inputArray2[p]) {
         outputArray[l] = inputArray1[ii];
         ii++;
      }
      else {
         outputArray[l] = inputArray2[p];
         p++;
      }
      l++;
   }
   if ( ii < inputArray1_size ) {
      for ( n = ii; n < inputArray1_size; n++) {
         outputArray[l] = inputArray1[n];
         l++;
      }
   }
   else {
      for ( n = p; n < inputArray2_size; n++) {
         outputArray[l] = inputArray2[n];
         l++;
      }
   }
   return l;
}

void writefile(int outputArray[], int outputArray_size, string name) {
   ofstream output;
   output.open(name.c_str());
   for (int ii = 0; ii < outputArray_size; ii++) {
      output << outputArray[ii] << "\n";
   }
   output.close();
}




void test_readfile(void) {
   int test[MAX_SIZE];



   ifstream input;
   input.open("input1.txt");
   int a = readfile(test, input);
   assert((0 <= a));

   input.close();
 
   string z = "input2.txt";
   input.open(z.c_str());
   int b = readfile(test, input);
   assert(0 <= b);
   
   input.close();

   cout << endl;

}

void test_sort(void) {
   int s1[10];
   int s2[] = {0, 1, 2, 6};
   int s3[] = {20, 15,12, 3, 8, 7};
   int s4[] = {7,6,5, 4, 3, 2, -1};
   int s6[MAX_SIZE];
   for (int l = 0; l < MAX_SIZE; l++) {
      s6[l] = rand() % 100;
   }
   int s5[MAX_SIZE];
       assert(4 == sort(s1, 0, s2, 4, s5));
        assert(11 == sort(s3, 6, s4, 5, s5));
        assert(106 == sort(s4, 7, s6, 99, s5));
    
   cout << endl;
}

int main() {

     int iArray1[MAX_SIZE];

     int iArray1_size = 0;
   
 

     int iArray2[MAX_SIZE];
   
     int iArray2_size = 0;
  
   

   int oa[MAX_SIZE];

   string file1, file2, ofile;
   test_readfile();
   test_sort();



   cout << "*** Welcome to Suryansh's sorting program ***\n";
   cout << "Enter the first input file name: ";
   cin >> file1;
   ifstream input1;
   input1.open(file1.c_str());
   iArray1_size = readfile(iArray1, input1);
   if (iArray1_size < 0) {
      exit(1);
   }
   cout << "\nThe list of " << iArray1_size << " numbers in file ";
   cout << file1 << " is: \n";
   for (int ii = 0; ii < iArray1_size; ii++) {
      cout << iArray1[ii] << "\n";
   
   }
   input1.close();
   cout << "\nEnter the second input file name: ";
   cin >> file2;
   ifstream input2;
   input2.open(file2.c_str());
   iArray2_size = readfile(iArray2, input2);
   if (iArray2_size < 0) {
      exit(1);
   }
   cout << "\nThe list of " << iArray2_size << " numbers in file ";
   cout << file2 << " is: \n";
   for (int p = 0; p < iArray2_size; p++) {
      cout << iArray2[p] << "\n";
   }
   input2.close();
   int outSize = sort(iArray1, iArray1_size, iArray2, iArray2_size, oa);
   cout << "\nThe sorted list of " << outSize << " numbers is: ";
   for (int l = 0; l < outSize; l++) {
      cout << oa[l] << " ";
   }
   cout << "\nEnter the output file name: ";
   cin >> ofile;
   writefile(oa, outSize, ofile);
   cout << "\n*** Please check the new file - " << ofile << " ***\n";
   cout << "*** Goodbye. ***" << endl;



   input1.close();
   input2.close();
   return 0;
}
