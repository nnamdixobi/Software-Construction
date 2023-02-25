/* project3_Ikenna-Obi_nzi0007.cpp 
 * Nnamdi Kelvin Ikenna-Obi
 * Consulted Gabe Fonatella on how to make the sorted list numbers output on a row and not on a column
 * Got help with my toString functions from a friend
 */
 
#include <fstream> 
#include <iostream> 
#include <vector> 
using namespace std; 
 
/* declare your user-defined functions */ 
bool check_file(string); 
 
 
 
/* do not forget to describe each function */ 
vector<int> read_file(string); 
 
 
 
 
void write_file(string, vector<int>); 
 
 
 
 
 
vector<int> merge(vector<int>, vector<int>); 
 
 
 
 
/* 
* Display the values of a given vector. 
* 
* Param: file Name of file to display. (string) 
* Param: v Vector containing values to display. (vector<int>) 
*/ 
void to_string(string, vector<int>); 
 
 
 
/* 
* Merge the numbers in two specified files and write all the numbers 
* to a specified third file sorted in ascending order. 
* 
* Return: 1 Program completed successfully. (int) 
*/ 
int main() { 
 /* declare your variables */ 
 string file1;
 string file2;
 string file3;
 vector<int> numbers1;
 vector<int> numbers2;
 vector<int> numbers3;
 
 /* Get name of file one. */ 
 do { 
  /* user friendly interfaces */ 
  //prompts user to enter first txt file 
  cout << "Enter the name of the first text file containing values" << endl;
  //retrieves file from user 
  cin >> file1;
  cout << "\n" << endl;

 } while (cin.fail() || !check_file(file1)); 
 
 /* Get and display numbers from file one. */ 
 numbers1 = read_file(file1); 
 //prints contents from file1
 to_string(file1, numbers1);
 
 /* Get name of file two. */ 
 do { 
  /* user friendly interfaces */ 
  //prompts the user to enter the second txt file
  cout << "Enter the name of the second text file containing values" << endl;
  //retrieves the file from user 
  cin >> file2;
  cout << "\n" << endl; 
 } while (cin.fail() || !check_file(file2)); 
 
 /* Get and display numbers from file two. */ 
 numbers2 = read_file(file2); 
 //prints contents from file 
 to_string(file2, numbers2);
 
 /* Combine vectors and display the sorted result. */ 
 numbers3 = merge(numbers1, numbers2); 

  //printed output
 cout << "The sorted list of " << numbers3.size() << " numbers is: ";
//loop through the final combined vector
      for (int i = 0; i < numbers3.size(); i++) {
            //print each individual value
            cout << numbers3.at(i) << " ";
            //cout << "The sorted list of " << numbers3.size() << " numbers is: " << numbers3.at(i) << endl;
      } 
 
 
  
 /* Get name of output file. */ 
 do { 
  //prompts user for name of output txt file
  cout <<"\nEnter the output file name: " << endl;
  //asks user what they would like to name the output file of sorted values
  cin >> file3;
  cout << "\n" << endl;
 } while (cin.fail()); 
 /* Write combined vector to output file. */ 
 //calls writefile function (defined below)
 write_file(file3, numbers3);
 //after write, print success output
 cout <<  "*** Please check the new file - " << file3 << " ***\n";
 cout << "*** Goodbye. ***\n";
      //upon success
      return 1;
} 
 
 
 
bool check_file(string file) { 
 /* Input file stream. (ifstream) */ 
 ifstream stream; 
 
 /* Check whether file exists. */ 
 stream.open(file.c_str()); 
 if (stream.fail()) { 
  cout << "File not found!" << endl;
 } 
 stream.close(); 
 
 return true; 
} 
 
vector<int> read_file(string file) { 
 /* Input file stream. (ifstream) */ 
 ifstream stream; 
 
 /* Vector containing numbers from file. (vector<int>) */ 
 vector<int> v; 
 
 /* Integer read from file. (int) */ 
 int i; 
 
 /* Add each number in the file to a vector. */ 
 stream.open(file.c_str()); 
 while (stream.good()) { 
  //inputs stream data from int i
  stream >> i;
  //adds i to the end of the vector using 'push_back' predefined function
     v.push_back(i);
 } 
 //reduces the vector to last int
 v.pop_back();
 stream.close();
 return v;
  
} 
 
void write_file(string file, vector<int> v) { 
 /* Output file stream. (ofstream) */ 
 ofstream ostream; 
 unsigned short i;
 ostream.open(file.c_str());

 for (i = 0; i < v.size() - 1; i++) {
    ostream << v.at(i) << "\n";
 }
 ostream << v.at(v.size() - 1);
 ostream.close();
} 
 
vector<int> merge(vector<int> v1, vector<int> v2) { 
  
vector<int> v3;
 
 /* Compare both vectors. */ 
 while (v1.size() > 0 && v2.size() > 0) { 
  if (v1.at(0) < v2.at(0)) { 
    //adds current element of v1 to v3
   v3.push_back(v1.at(0));
   //erases the original vector
   v1.erase(v1.begin()); 
  } else { 
   v3.push_back(v2.at(0));
   //erase original vector
   v2.erase(v2.begin()); 
  } 
 } 
 
 /* Add any remaining numbers from vector one. */ 
 if (v1.size() > 0) { 
  for (int i = 0; i , v1.size(); i++) {
    v3.push_back(v1.at(0));
    v1.erase(v1.begin());
  } 
 } 
 
 /* Add any remaining numbers from vector two. */ 
 if (v2.size() > 0) { 
  for (int i = 0; i < v2.size(); i++) {
    v3.push_back(v2.at(0));
    v2.erase(v2.begin());
  } 
 } 
    
 return v3; 
} 
 
void to_string(string file, vector<int> vec) { 
 /* Vector iterator number. (unsigned short) */ 
 unsigned short x; 
 /* Display the numbers contained in a vector. */ 
    cout << "The list of " << vec.size() << " numbers "
    << "in file " << file << " is:\n" ;
    //print
    for (x = 0; x < vec.size(); x++) {
        cout << vec.at(x) << "\n";
    }
    cout << "\n";
  
} 
 
 "C:\Users\nnamd\OneDrive\Desktop\SoftwareConstruction\project4_Ikenna-Obi_nzi0007.cpp"
