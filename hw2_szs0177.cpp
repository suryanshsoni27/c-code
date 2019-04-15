//hwassignment2
//szs0177@auburn.edu
//903941997


#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
   double lnam,
       inter, 
       mnp,
       interest,
       prin, 
       totint, rate;

   cout.setf(ios::showpoint);
   cout.setf(ios::fixed);
   cout.precision(2);

   cout<<"Loan Amount: ";
   cin>> lnam;
   cout<<"Interest Rate (% per year): ";
   cin>>inter;
   cout<<"Monthly payments: ";
   cin>>mnp;

   if (mnp <= ((inter / 12)* lnam) / 100 ) {
      cout<<"\nREGULAR INSTALLEMENT MUST BE LARGER THEN THE INTEREST PER MONTH\n";
      return 0;
   }

   cout<<"******************************************************";
   cout<<"\n\tAmortization Table ";
   cout<<"\n******************************************************";

   double bal = lnam;
   int month = 0;

   cout<<"\nMonth\tBalance Payment\tRate\tInterest Principal";
   cout<< "\n"
      <<month
      << "\t$" 
      << bal 
      << " N/A\tN/A\tN/A  N/A";

   while (bal > 0) {
      month = month + 1;
      rate = inter/12;
      interest = (bal*rate) / 100;
      prin = mnp - interest;
      bal = bal - prin;
      totint = totint + interest;
   
      if(bal <= 0 ) {
         prin = bal + prin;
         mnp = prin + interest;
         bal = 0;
      }
   
      cout<< "\n" 
         <<month
         << "\t$" 
         <<bal
         << " $" 
         <<mnp
         << "\t" 
         <<rate
         << "\t$" 
         << interest
         << "\t$" 
         << prin;
   }

   cout<< "\n******************************************************";
   cout<< "\n\nIt takes " 
      <<month 
      << " months to pay off the loan.";
   cout<< "\nTotal interest paid is: $" 
      << totint 
      << "\n";

   return 0;
}

