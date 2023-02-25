/* project2_Ikenna-Obi_nzi0007.cpp 
 * Nnamdi Kelvin Ikenna-Obi
 */ 

#include <iostream>
#include <stdlib.h>
#include <assert.h>
#include <ctime>
using namespace std;

/*
* Input: A_alive indicates Aaron is alive true for alive, false for dead
* B_alive indicates Bob is alive
* C_alive indicates Charlie is alive
* Return: true if at least two are alive otherwise return false
*/
bool at_least_two_alive(bool A_alive, bool B_alive, bool C_alive);
/*
* Call by reference
* Strategy 1: Everyone shoots to kill the highest accuracy player alive
* Input: B_alive indicates Bob is alive or dead
* C_alive indicates Aaron is alive or dead
* Return: Change B_alive into false if Bob is killed
* Change C_alive into false if Charlie is killed
*/
void Aaron_shoots1(bool& B_alive, bool& C_alive);
/*
* Call by reference
* Input: A_alive indicates Aaron is alive or dead
* C_alive indicates Charlie is alive or dead
* Return: Change A_alive into false if Aaron is killed
* Change C_alive into false if Charlie is killed
*/
void Bob_shoots(bool& A_alive, bool& C_alive);
/*
* Call by reference
* Input: A_alive indicates Aaron is alive or dead
* B_alive indicates Bob is alive or dead
* Return: Change A_alive into false if Aaron is killed
* Change B_alive into false if Bob is killed
*/
void Charlie_shoots(bool& A_alive, bool& B_alive);
/*
* Call by reference
* Strategy 2: Aaron intentionally misses if both are alive
* Input: B_alive indicates Bob is alive or dead
* C_alive indicates Aaron is alive or dead
* Return: Change B_alive into false if Bob is killed
* Change C_alive into false if Charlie is killed
*/
void Aaron_shoots2(bool& B_alive, bool& C_alive);
//Simple method to implement pause function in linux
void Press_any_key(void);
//TEST PROTOTYPES
void test_at_least_two_alive(void);
void test_Aaron_shoots1(void);
void test_Bob_shoots(void);
void test_Charlie_shoots(void);
void test_Aaron_shoots2(void);
//VARIABLES
const int aaronAcc = 33;
const int bobAcc = 50;
const int charlieAcc = 100;
const int TOTAL_RUNS = 10000;
bool aaronAlive = true;
bool bobAlive = true;
bool charlieAlive = true;
int aaronWins1 = 0;
int aaronWins2 = 0;
int bobWins = 0;
int charlieWins = 0;


int main() {
//Initializes Random number generator's seed and calls test functions
cout << "*** Welcome to Nnamdi's Duel Simulator ***\n";
srand(time(0));
test_at_least_two_alive();
Press_any_key();
test_Aaron_shoots1();
Press_any_key();
test_Bob_shoots();
Press_any_key();
test_Charlie_shoots();
Press_any_key();
test_Aaron_shoots2();
Press_any_key();
//Starts strategy 1 and runs 10,000 times
cout << "Ready to test strategy 1 (run 10000 times):\n";
Press_any_key();
for (int i = 0; i < TOTAL_RUNS; i++ ){
aaronAlive = true;
bobAlive = true;
charlieAlive = true;
while (at_least_two_alive(aaronAlive, bobAlive, charlieAlive)) {
   if (aaronAlive){
       Aaron_shoots1(bobAlive, charlieAlive);
   }

if (bobAlive){
    Bob_shoots(aaronAlive, charlieAlive);
}
   
if (charlieAlive) {
   Charlie_shoots(aaronAlive, bobAlive);
}
}
if (aaronAlive)
   aaronWins1++;
if (bobAlive)
   bobWins++;
if (charlieAlive)
   charlieWins++;
}
    
cout << "Aaron won " << aaronWins1 << "/10000 duels or " << static_cast<double>(aaronWins1) /
TOTAL_RUNS * 100 << "%\n"
 << "Bob won " << bobWins << "/10000 duels or " << static_cast<double>(bobWins) / TOTAL_RUNS
* 100 << "%\n"
 << "Charlie won " << charlieWins << "/10000 duels or " << static_cast<double>(charlieWins) /
TOTAL_RUNS * 100 << "%\n"
 << endl;
//Reinitializes variables and starts strategy 2 to run 10,000 times
aaronWins2 = 0;
bobWins = 0;
charlieWins = 0;
cout << "Ready to test strategy 2 (run 10000 times):\n";
Press_any_key();
for (int i = 0; i < TOTAL_RUNS; i++ ){
aaronAlive = true;
bobAlive = true;
charlieAlive = true;
while (at_least_two_alive(aaronAlive, bobAlive, charlieAlive)) {
if (aaronAlive) {
        Aaron_shoots2 (bobAlive, charlieAlive);
    }
    if (bobAlive) {
        Bob_shoots(aaronAlive, charlieAlive);
    }
    if (charlieAlive) {
        Charlie_shoots(aaronAlive, bobAlive);
    }
}
if (aaronAlive)
   aaronWins2++;
if (bobAlive)
   bobWins++;
if (charlieAlive)
   charlieWins++;
}

cout << "Aaron won " << aaronWins2 << "/10000 duels or " << static_cast<double>(aaronWins2) /
TOTAL_RUNS * 100 << "%\n"
 << "Bob won " << bobWins << "/10000 duels or " << static_cast<double>(bobWins) / TOTAL_RUNS
* 100 << "%\n"
 << "Charlie won " << charlieWins << "/10000 duels or " << static_cast<double>(charlieWins) /
TOTAL_RUNS * 100 << "%\n"
 << endl;
if (aaronWins1 > aaronWins2) {
cout << "Strategy 1 is better than strategy 2.\n";
}
else {
cout << "Strategy 2 is better than strategy 1.\n";
}
return 0;
}
//Implementation of functions. Look above for documentation of them.
bool at_least_two_alive(bool A_alive, bool B_alive, bool C_alive) {
   if ((A_alive && B_alive) || (A_alive && C_alive) || (B_alive && C_alive))
      return true;
    return false;
}
void test_at_least_two_alive(void) {
cout << "Unit Testing 1: Function - at_least_two_alive()\n";
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
cout << "\tCase passed ...\n";

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
void Aaron_shoots1(bool& B_alive, bool& C_alive) {
assert(B_alive || C_alive);
int shootResult = rand() % 100;
if (C_alive) {
   if (shootResult <= aaronAcc) {
    C_alive = false;
   }
      
}
else {
   if (shootResult <= aaronAcc){
       B_alive = false;
   }
}
}
void test_Aaron_shoots1(void) {
cout << "Unit Testing 2: Function Aaron_shoots1(Bob_alive, Charlie_alive)\n";
   bool bob_a = true;
   bool charlie_a = true;

cout << "\tCase 1: Bob alive, Charlie alive\n"
 << "\t\tAaron is shooting at Charlie\n";
Aaron_shoots1(bob_a, charlie_a);
bob_a = false;
charlie_a = true;
cout << "\tCase 2: Bob dead, Charlie alive\n"
 << "\t\tAaron is shooting at Charlie\n";
Aaron_shoots1(bob_a, charlie_a);
bob_a = true;
charlie_a = false;
cout << "\tCase 3: Bob alive, Charlie dead\n"
 << "\t\tAaron is shooting at Bob\n";
Aaron_shoots1(bob_a, charlie_a);
}
void Bob_shoots(bool& A_alive, bool& C_alive) {
assert(A_alive || C_alive);
int shootResult = rand() % 100;
if (C_alive) {
    if (shootResult <= bobAcc){
        C_alive = false;
    }
}
else{
    if (shootResult <= bobAcc){
        A_alive = false;
    }
}
}
void test_Bob_shoots(void) {
cout << "Unit Testing 3: Function Bob_shoots(Aaron_alive, Charlie_alive)\n";
bool aaron_a = true;
bool charlie_a = true;
cout << "\tCase 1: Aaron alive, Charlie alive\n"
 << "\t\tBob is shooting at Charlie\n";
Bob_shoots(aaron_a, charlie_a);
aaron_a = false;
charlie_a = true;
cout << "\tCase 2: Aaron dead, Charlie alive\n"
 << "\t\tBob is shooting at Charlie\n";
Bob_shoots(aaron_a, charlie_a);
aaron_a = true;
charlie_a = false;
cout << "\tCase 3: Aaron alive, Charlie dead\n"
 << "\t\tBob is shooting at Aaron\n";
Bob_shoots(aaron_a, charlie_a);
}
void Charlie_shoots(bool& A_alive, bool& B_alive) {
assert(A_alive || B_alive);
if (B_alive) {
B_alive = false;
 }
else {
A_alive = false;
}
}
void test_Charlie_shoots(void) {
cout << "Unit Testing 4: Function Charlie_shoots(Aaron_alive, Bob_alive)\n";
    bool aaron_a = true;
    bool bob_a = true;

cout << "\tCase 1: Aaron alive, Bob alive\n"
 << "\t\tCharlie is shooting at Bob\n";
Charlie_shoots(aaron_a, bob_a);
assert(bob_a == false);
    aaron_a = false;
    bob_a = true;

cout << "\tCase 2: Aaron dead, Bob alive\n"
 << "\t\tCharlie is shooting at Bob\n";
Charlie_shoots(aaron_a, bob_a);
assert(bob_a == false);
    aaron_a = true;
    bob_a = false;

cout << "\tCase 3: Aaron alive, Bob dead\n"
 << "\t\tCharlie is shooting at Aaron\n";
Charlie_shoots(aaron_a, bob_a);
assert(aaron_a == false);
}
void Aaron_shoots2(bool& B_alive, bool& C_alive) {
int shootResult = rand() % 100;
if (C_alive && !B_alive) {
 if (shootResult <= bobAcc) {
 C_alive = false;
 }
}
if (B_alive && !C_alive) {
 if (shootResult <= aaronAcc) {
B_alive = false;
 }
}
}
void test_Aaron_shoots2(void) {
cout << "Unit Testing 5: Function Aaron_shoots2(Bob_alive, Charlie_alive)\n";
    bool bob_a = true;
    bool charlie_a = true;

cout << "\tCase 1: Bob alive, Charlie alive\n"
 << "\t\tAaron intentionally misses his first shot\n\t\tBoth Bob and Charlie are alive.\n";

Aaron_shoots2(bob_a, charlie_a);
    bob_a = false;
    charlie_a = true;

cout << "\tCase 2: Bob dead, Charlie alive\n"
 << "\t\tAaron is shooting at Charlie\n";
Aaron_shoots2(bob_a, charlie_a);
    bob_a = true;
    charlie_a = false;

cout << "\tCase 3: Bob alive, Charlie dead\n"
 << "\t\tAaron is shooting at Bob\n";
Aaron_shoots2(bob_a, charlie_a);
}

void Press_any_key(void) {
cout << "Press any key to continue...\n";
cin.get();
}
