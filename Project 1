/* project1_Ikenna-Obi_nzi0007.cpp 
 * Nnamdi Kelvin Ikenna-Obi
 * Past student helped me with the void clearCin method 
 */ 
 
#include <iostream>
#include <limits> 
using namespace std; 

void clearCin() {
  cin.clear();
  //sets streamsize to clear MAX amount of invalid input characters
  cin.ignore(numeric_limits<streamsize>::max(), '\n');
}
 
int main() { 
 // VARIABLE INITIALIZATION 
 double loan;
 double rate;
 double rateC;
 double interest_total;
 double monthly_payments;
 double principle;
 int current_month = 0;

  
 // CURRENCY FORMATTING 
 cout.setf(ios::fixed); 
 cout.setf(ios::showpoint); 
 cout.precision(2); 
  
 // USER INPUT 
 // NOTE: For valid input, the loan, interest, and monthly payment must 
 // be positive. The monthly payment must also be large enough to 
 // terminate the loan. 
 cout << "\nLoan Amount: "; 
 cin >> loan; 
 
 while (cin.fail() || (loan < 0)) {
      cout << "ERROR: Please enter a postive integer!" <<endl;
      cout << "Loan amount must be a positive number";
      clearCin(); //calls clearCin method
      //remprompt for user input
      cin >> loan;
    } 
 
 
 
 cout << "Interest Rate (% per year): "; 
 cin >> rate; 
  
        while (cin.fail() || (rate < 0)) {
      cout << "ERROR: Please enter a postive integer!" <<endl;
      cout << "Interest Rate must be a postive percentage!";
      clearCin(); //calls clearCin method 
      //reprompt for user input
      cin >> loan;
    }  
 
 
 
 // GET PROPER INTEREST RATES FOR CALCULATIONS 
 rate /= 12; 
 rateC = rate / 100;
 
 cout << "Monthly Payments: "; 
 cin >> monthly_payments; 
 
 while (cin.fail() || (monthly_payments < 0)) {
        cout << "ERROR: Please enter a postive integer!";
        cout << "Monthly Payment must be a positive number" <<endl;
          clearCin(); //call clearCin method 
        cin >> monthly_payments;
      }
       cout << endl; 
  
 // AMORTIZATION TABLE 
 cout << "*****************************************************************\n" 
      << "\tAmortization Table\n" 
      << "*****************************************************************\n" 
      << "Month\tBalance\t\tPayment\tRate\tInterest\tPrincipal\n"; 
 
 // LOOP TO FILL TABLE 
 
 while (loan > 0) { 
 double payment = loan * rateC;
  if (current_month == 0) { 
   cout << current_month++ << "\t$" << loan; 
  if (loan < 1000) cout << "\t"; // Formatting MAGIC 
   cout << "\t" << "N/A\tN/A\tN/A\t\tN/A\n"; 
  } 
  else {  
    interest_total += payment; 
              if  (loan * (1 + rateC) < monthly_payments) {
                monthly_payments = loan + payment;
                principle = monthly_payments - payment;
                loan -= principle;
              } 
              else if (loan * (1 + rateC) >= monthly_payments) {
                principle = monthly_payments - payment;
                loan -= principle;
              }

   
  cout << current_month++ << "\t$" << loan;
  if (loan < 1000) cout << "\t";
    cout << "\t$" << monthly_payments << "\t$" << rate << "\t$" << payment << "\t\t" << principle << "\n";
  }
}
    
 cout << "****************************************************************\n"; 
 cout << "\nIt takes " << --current_month << " months to pay off " 
      << "the loan.\n" 
      << "Total interest paid is: $" << interest_total; 
 cout << endl << endl;  
 return 0; 
}
