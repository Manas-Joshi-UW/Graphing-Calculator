#include <iostream>
#include <string>
#include <map>
#include <algorithm>
#include "parser.h"
#include "constants.h"
using namespace std;

bool Process_Expression(string expression);

int main()
{
    string expression;
    cout << "Hello word"<<endl;
    getline(cin, expression);
    cout << "expr length: " <<expression.length()<< endl;
    if(Process_Expression(expression)){
        expression.erase(remove_if(expression.begin(), expression.end(), ::isspace), expression.end());
    }

    cout << Parse_Expression(expression, expression.length()) << "\n";
    return 0;
}

bool Process_Expression(string expression){
    try {
        int length = expression.length();

        for(int count = 0; count < length; count++){
            if(count == 0 && expression[count] == DECIMAL){
                throw "Please enter decimals with the 0";
            }
            if(count == 0 && IsOperator(expression[count])){
                throw "Expressions cannot start with an operator";
            }
            if(count == 0 && (expression[count] == O_BRACKET || IsNumber(expression[count]))){
                continue;
            }
            if(expression[count] == DECIMAL && (expression[count-1] == 32 || expression[count+1] == 32)){
                throw "Please re-enter the expression with appropriate spacing.";
            }
            if(IsNumber(expression[count])){
                for(int i = count+1; i < length; i++){
                    if(expression[i] == DECIMAL || IsOperator(expression[i] || IsNumber(expression[i]))){
                        break;
                    }
                    else if(expression[i] == 32 && IsNumber( expression[i+1])){
                        throw "please enter the expression with appropriate spacing";
                    }
                }
            }
        }
        return true;
    }
    catch(string msg){
        cout << msg << endl;
    }
    catch (...) {

    }
    return "";
}
