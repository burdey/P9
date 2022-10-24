#include <iostream>
#include <string>
#include "PolishPrefix.h"
using namespace std;

int main() {
    string prefix;

// take the prefix expression in one line
    cout << "Sample input: ";
    getline(cin, prefix);

// create an instance for PolishNotation class
    PolishPrefix polish(prefix);

// call the convertPrefixToInfix function of PolishNotation class
// to get the equivalent infix expression
    string print = polish.PrintPrefix();

// print the infix expression
    cout << "Sample output: " << print;

// verify whether the infix expression is valid
    if (print.compare("Error") != 0)
    {
// call the computePrefixExpression function
        int Notation = polish.PrefixNotation();

// print the postfix expression result
        cout << " = " << Notation;
    }
    cout << endl << endl;

    return 0;
}
