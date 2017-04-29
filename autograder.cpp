#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main(int argc, char* argv[])
{
    //test case number will be arg[1]
    
    string solutionFile = "output";
    solutionFile += argv[1];
    solutionFile += ".txt";
    string studentFile = "student";
    studentFile += argv[1];
    studentFile += ".txt";
    
    ifstream solution(solutionFile);
    ifstream student(studentFile);
    
    string cSolution, cStudent;
    
    unsigned int lineNumber = 1;
    
    while ( (getline(solution, cSolution)) && (getline(student, cStudent)) )
    {
        if (cSolution != cStudent)
        {
            cout << "Test Case " << argv[1] << " Failed at line number " << lineNumber << endl;
            cout << endl;
            
            cout << "Correct Output:" << endl;
            cout << cSolution << endl;
            cout << endl;
            cout << "Student Output:" << endl;
            cout << cStudent << endl;
            exit(1);
        }
        ++lineNumber;
    }
    
    while (getline(solution, cSolution))
    {
        cout << "Test Case " << argv[1] << " Failed" << endl;
        cout << "Student output ended early" << endl;
        cout << endl;
        
        cout << "Correct Output:" << endl;
        cout << cSolution << endl;
        cout << endl;
        exit(1);
    }
    
    while (getline(student, cStudent))
    {
        cout << "Test Case " << argv[1] << " Failed" << endl;
        cout << "Student output more" << endl;
        cout << endl;
        
        cout << "Student Output:" << endl;
        cout << cStudent << endl;
        cout << endl;
        exit(1);
    }
    
    cout << "Test Case " << argv[1] << " Passed" << endl;
    
    return 0;
}
