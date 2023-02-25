/* project4_Ikenna-Obi_nzi0007.cpp 
 * Nnamdi Kelvin Ikenna-Obi
 */

#include <iostream>
#include <cmath>
#include <cstring>
using namespace std;

//Structure for creating a linked list that holds a trivia question,answer and point amount.
struct TriviaNode {
    string question;
    string answer;
    int points;
    TriviaNode* next;
};

int questionCount;

//Prototypes
void initializeQuestion(TriviaNode *head);
void askQuestion(TriviaNode *n, int total);
bool checkAnswer(string a, TriviaNode *n);
void addQuestion(TriviaNode *s);
void Unit_Test(TriviaNode *head);
//Initialize boolean variables
bool cont = false;
bool correctAnswer = true;

//main function
int main() {

//version for unit testing 
//#define UNIT_TEST
#ifdef UNIT_TEST
    TriviaNode *nodeList = new TriviaNode;
    initializeQuestion(nodeList);
    Unit_Test(nodeList);
}
//Product Code 
#else
//creates new trivia node
    TriviaNode *nodeList = new TriviaNode;
    //initialize list of prebuilt questions
    initializeQuestion(nodeList);
    //Print Welcome Message
    cout << "*** Welcome to Nnamdi's trivia quiz game ***" << endl;
    
    do {
        //call addQuestion function which allows users to add their own questions to the linked list
        addQuestion(nodeList);
        //user is given option to continue adding questions or stop after adding first question 
    } while (cont);
    //clear input buffer
    cin.ignore(1);
    //calls function ask all questions 
    askQuestion(nodeList, questionCount);
    //print ending message
    cout << "\n*** Thank you for playing the trivia quiz game. Goodbye! ***";
}
#endif

//initialize list of prebuilt questions into the linked list
void initializeQuestion(TriviaNode *s) {
    TriviaNode *Q1 = s;
    TriviaNode *Q2 = new TriviaNode;
    TriviaNode *Q3 = new TriviaNode;
    questionCount = 3;

    //Question 1
    Q1->question = "How long was the shortest war on record? (Hint: how many minutes)";
    Q1->answer = "38";
    Q1->points = 100;
    Q1->next = Q2;
    //Question 2
    Q2->question = "What was Bank of America's original name? (Hint: Bank of Italy or Bank of Germany)";
    Q2->answer = "Bank of Italy";
    Q2->points = 50;
    Q2->next = Q3;
    //Question 3
    Q3->question = "What is the best-selling video game of all time? (Hint: Call of Duty or Wii Sports)";
    Q3->answer = "Wii Sports";
    Q3->points = 20;
    Q3->next = NULL;
    //Variable to keep track of total numbe of questions in list 
}

//function to check users answer against the correct answer 
bool checkAnswer(string correctAnswer, TriviaNode *n) {
    if (n->answer.compare(correctAnswer) == 0) {
        return true;
    }
    return false;
}

//ASK QUESTION FUNCTION 
void askQuestion(TriviaNode *n, int total) {
    int totalPoints = 0;
    string userAnswer;
    //ensure that list is not empty
    if(total < 1) {
        cout << "Warning - The number of trivia to be asked must equal to or larger than 1." << endl;
    }
    //if only one question 
    else if (total == 1) {
        cout << "\nQuestion: " << n->question;
        cout << "\nAnswer: ";
        getline(cin, userAnswer);

        if (checkAnswer(userAnswer, n)) {
            correctAnswer = true;
        } else {
            correctAnswer = false;
        }
        n = n->next;
        cout << endl;
    }
    else if (total == 3) {
        while (n->next != NULL) {
            n = n->next;
        }
        cout << "\nQuestion: " << n->question;
        cout << "\nAnswer: ";
        getline(cin, userAnswer);
    }
    else if (total > questionCount) {
        cout << "Warning - There are only three trivia in the list." << endl;
    }

    else {
        //begin game
        //iterate through each question until end using 'for' loop
        for (int x = 0; x < total; x++) {
            cout << " " << endl;
            cout << "Question: " << n->question << endl;
            cout << "Answer: ";
            getline(cin, userAnswer);

            if (checkAnswer(userAnswer, n)) {
                cout << "Your answer is correct. You receive " << n->points << " points." << endl;
                totalPoints += n->points;
                cout << "Your total points: " << totalPoints;
            } else {
                cout << "Your answer is wrong.  The correct answer is " << n->answer << endl;
                cout << "Your total points: " << totalPoints;
            }
            n = n->next;
            cout << endl;
        }
    }

}

//ADD QUESTION FUNCTION
void addQuestion(TriviaNode *s) {
    string addAnother;

    //gets to the end of the list
    while(s->next!=NULL) {
        s = s->next;
    }
    //create pointer variable to new question added by user
    TriviaNode *newQ = new TriviaNode();

    cout << "Enter a question: ";
    cin >> newQ->question;

    cout << "Enter an answer: ";
    cin >> newQ->answer;

    cout << "Enter award points: ";
    cin >> newQ->points;

    s->next = newQ;

    cout << "Continue? (Yes/No): ";
    questionCount++;
    cin >> addAnother;

    //if user enter no, the do-while loop in the main function will break
    //otherwise, user gets to add another question to the linked list  
    if (addAnother.compare("no") == 0 || addAnother.compare("No") == 0 || addAnother.compare("NO") == 0) {
        cont = false;
    }
    else {
        cont = true;
    }
}

void Unit_Test(TriviaNode *head) {

    cout << "*** This is a debug version ***" << endl;
    cout << "Unit Test Case 1: Ask no questions. The program should give a warning message." << endl;
    askQuestion(head, 0);
    cout << " " << endl;
    cout << "Unit Test Case 2.1: Ask 1 question in the linked list. The tester enters an incorrect answer.";
    askQuestion(head, 1);
    if (!correctAnswer) {
        cout << "Case 2.1 passed..." << endl;
    }

    cout << " " << endl;
    cout << "Unit Test Case 2.2: Ask 1 question in the linked list. The tester enters a correct answer.";
    askQuestion(head, 1);
    if (correctAnswer) {
        cout << "Case 2.2 passed..." << endl;
    }

    cout << " " << endl;
    cout << "Unit Test Case 3: Ask the last trivia in the linked list.";
    askQuestion(head, 3);

    cout << " " << endl;
    cout << "Unit Test Case 4: Ask 5 questions in the linked list." << endl;
    askQuestion(head, 5);

    cout << " " << endl;
    cout << "*** End of the Debug Version ***";
}
