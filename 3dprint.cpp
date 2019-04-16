#include <iostream>
using namespace std;
int maxdays(int stats);
int main() {
   int printdays;
   int stat;
   
   cin>>stat;
   if((stat >=1) && (stat <= 10000)) {
      cout<<maxdays(stat);
      cout<<endl;}
   else
   
      return 0;}

int maxdays( int stats) {
   int prt = 0;
   int days;
   for(int i = 0; i < stats; i++) { 
      prt += 1;
    
   }

   if (!(prt < stats)) {
      days = stats - 1;
   }
   else 
      days = stats;
   return days;
   
}
