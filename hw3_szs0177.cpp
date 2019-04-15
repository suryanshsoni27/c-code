#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cassert>
#include <stdio.h>
#include <unistd.h>
#include <ctype.h>
using namespace std;
/**
* @suryansh soni
* @szs0177@auburn.edu
* @3/26/2019
* hw3.cpp
*
* Compiled using emacs and g++ compiler on Linux machine in Engineering lab via putty from Windows.
* (syllabus method).
*/

bool fshot = true;
bool Aaron, Bob, Charlie = true;
const double aaw = 33;
const double bw = 50;
const double numduel = 10000;
const double per = 100; 

bool at_least_two_alive(bool A_alive, bool B_alive, bool C_alive) {
   return A_alive && B_alive || A_alive && C_alive || B_alive && C_alive; 
}

/*  strategy 1: Use call by reference
 *   Input: B_alive indicates whether Bob is alive or dead
 *         C_alive indicates whether Charlie is alive or dead
 *  Return: Change B_alive into false if Bob is killed.
 *         Change C_alive into false if Charlie is killed.
*/
void Aaron_shoots1(bool& B_alive, bool& C_alive) {
   double shoot;
   shoot = rand() % 100;
   if (shoot <= aaw) {
      if (C_alive) {
         C_alive = false;
      } 
      else {
         B_alive = false;  
      }
   }
   
} 

/*  Call by reference
 *   Input: A_alive indicates whether Aaron is alive or dead
 *         C_alive indicates whether Charlie is alive or dead
 *  Return: Change A_alive into false if Aaron is killed.
 *         Change C_alive into false if Charlie is killed.
*/
void Bob_shoots(bool& A_alive, bool& C_alive) {
   double shoot;
   shoot = rand() % 100;
   if (shoot <= bw) {
      if (C_alive) {
         C_alive = false;
      }
      else {
         A_alive = false;
      }
   }
  
}

void Charlie_shoots(bool& A_alive, bool& B_alive) {
   if (B_alive) {
      B_alive = false;
   }
   else {
      A_alive = false;
   }
}

/*  strategy 2:*/
void Aaron_shoots2(bool& B_alive, bool& C_alive) {
   int shoot;
   if(fshot) {
      fshot = false;
      return;
   }
   shoot = rand() % 100;
   if (shoot <= aaw) {
      if (C_alive) {
         C_alive = false;
      } 
      else {
         B_alive = false; 
      }
   }
}

void press(void);
void press(void) {
   char ch;
   cout << "Press Enter to continue...";
   ch = cin.get();
   if (ch == 0 || ch == 224) {
   cin.get();
}
}
  

void test_at_least_two_alive(void) {
   cout << "Unit Testing 1: Function – at_least_two_alive()\n";
   cout << "\tCase 1: Aaron alive, Bob alive, Charlie alive\n";
   assert(true == at_least_two_alive(true, true, true));
   cout << "\tCase passed ...\n";
   cout << "\tCase 2: Aaron dead, Bob alive, Charlie alive\n";
   assert(true == at_least_two_alive(false, true, true));
   cout << "\tCase passed ...\n";
   cout << "\tCase 3: Aaron alive, Bob dead, Charlie alive\n";
   assert(true == at_least_two_alive(true, false, true));
   cout << "\tCase passed ...\n";
   cout << "\tCase 4: Aaron alive, Bob alive, Charlie dead\n";
   assert(true == at_least_two_alive(true, true, false));
   cout <<"\tCase passed ...\n";
   cout << "\tCase 5: Aaron dead, Bob dead, Charlie alive\n";
   assert(false == at_least_two_alive(false, false, true));
   cout << "\tCase passed ...\n";
   cout << "\tCase 6: Aaron dead, Bob alive, Charlie dead\n";
   assert(false == at_least_two_alive(false, true, false));
   cout << "\tCase passed ...\n";
   cout << "\tCase 7: Aaron alive, Bob dead, Charlie dead\n";
   assert(false == at_least_two_alive(true, false, false));
   cout << "\tCase passed ...\n";
   cout << "\tCase 8: Aaron dead, Bob dead, Charlie dead\n";
   assert(false == at_least_two_alive(false, false, false));
   cout << "\tCase passed ...\n";
}

//main 
int main() {
   int awon = 0, bwon = 0, cwon = 0;
   srand(time(0)); 
    
   cout << "*** Welcome to Duel Simulator ***\n";
   test_at_least_two_alive();
   press(); //Press Any Key To Continue

   cout << "Ready to test strategy 1 (run 10000 times):\n";
   press(); //Press Any Key To Continue
       
   for (int i = 0; i < numduel; i++) {
      while (at_least_two_alive(Aaron, Bob, Charlie)) {
         if (Aaron) {
            Aaron_shoots1(Bob, Charlie);
         }
         if (Bob) {
            Bob_shoots(Aaron, Charlie);
         }
         if (Charlie) {
            Charlie_shoots(Aaron, Bob);  
         } 
      } 
      if (Aaron) {
         awon++;
      }
      if (Bob) {
         bwon++;
      } 
      if (Charlie) {
         cwon++;
      }
      Aaron = true;
      Bob = true;
      Charlie = true;
   }
   cout << "\nAaron won " 
        << awon 
        << " / 10000 duels or " 
        << (awon / numduel) * per 
        << "%";
   cout << "\nBob won " 
        << bwon 
        << " / 10000 duels or " 
        << (bwon / numduel) * per 
        << "%";
   cout << "\nCharlie won " 
        << cwon 
        << " / 10000 duels or " 
        << (cwon / numduel) * per 
        << "%" << endl;
    
   cout << "\nReady to test strategy 2 (run 10000 times):\n";
   press();

  double awon2 = 0;
  double bwon2 = 0; 
  double cwon2 = 0;

   for (int j = 0; j < numduel; j++) {
      while (at_least_two_alive(Aaron, Bob, Charlie)) {
         if (Aaron) {
            Aaron_shoots2(Bob, Charlie);
         }
         if (Bob) {
            Bob_shoots(Aaron, Charlie);
         }
         if (Charlie) {
            Charlie_shoots(Aaron, Bob);  
         } 
      }
      if (Aaron) {
         awon2++;
                
      }
      if (Bob) {
         bwon2++;
      } 
      if (Charlie) {
         cwon2++;
      }
      Aaron = true;
      Bob = true;
      Charlie = true;
   }        
   cout << "\nAaron won " 
        << awon2 
        << " / 10000 duels or " 
        << (awon2 / numduel) * per 
        << "%\n";
   cout << "Bob won " 
        << bwon2 
        << " / 10000 duels or " 
        << (bwon2 / numduel) * per 
        << "%\n";
   cout << "Charlie won " 
        << cwon2 
        << " / 10000 duels or " 
        << (cwon2 / numduel) * per 
        << "%" 
        << endl;

   if (awon > awon2) {
      cout << "\nStrategy 1 is better than strategy 2.\n";
   }
   if (awon2 > awon) {
      cout << "\nStrategy 2 is better than strategy 1.\n";
   }
   return 0;
}
