#include <string>
#include <map>
using namespace std;
const char MINUS = '-';
const char PLUS = '+';
const char MULTIPLY = '*';
const char DIVIDE = '/';
const char EXPONENT = '^';
const char DECIMAL = '.';
const char O_BRACKET = '(';
const char C_BRACKET = ')';


map<char,int> precedences;
precedences[MINUS] = 5;
precedences[PLUS] = 5;
precedences[MULTIPLY] = 3;
precedences[DIVIDE] = 3;
precedences[EXPONENT] = 2;

// #Done:0 Make a dictionary for the precedences of the operations.
