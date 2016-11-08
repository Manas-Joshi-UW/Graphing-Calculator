#include <iostream>
#include <string>
#include "parser.h"
#include "constants.h"
using namespace std;


// IsNumber checks whether symbol is a number or not.
/// TODO:20 check whether 48-57 is the right ascii range.

bool IsNumber(char symbol){
    if(symbol >= 48 && symbol <= 57){
        return true;
    }
    return false;
}


// IsUnary checks whether the character at position count in expression is a
// unary operator.

bool IsUnary (string expression, int count){
    if((expression[count] == PLUS || expression == MINUS) && IsNumber(expression[count+1])){
        return true;
    }
    return false;
}


// GetNumber will get the number in expression which starts at position count.
// length is the length of expression.
string GetNumber(string expression, int count, int length){
    string number;
    for (int i = count; i < length; ++i)
    {
        if(!IsNumber(expression[i])){
            break;
        }
        number += expression[count];
    }
    return number;
}


IsOperator(char symbol){
    if(symbol == PLUS ||
       symbol == MINUS ||
       symbol == MULTIPLY ||
       symbol == DIVIDE ||
       symbol == EXPONENT){
           return true;
       }
       return false;
}

// HandleUnary will start at position count in expression and
// return a simplified number. The max position will be length
// For example: --+5 -> -5
string HandleUnary(string expression, int count, int length){
    int append_negative = 0;
    string number;
    try
    {
        for (int i = count; i < length; ++i){
            if(expression[i] == MINUS){
                append_negative++;
            }
            else if(IsNumber(expression[i])){
                number = GetNumber(expression, i, length);
                break;
            }
            else if (expression[i] != PLUS){
                // TODO:40 throw exception
            }

        }

        // TODO: confirm that a bool value > 1 is also true.
        if(append_negative){
            number = "-" + number;
        }

        return number;
    }
    catch (Exception e) // TODO:30 learn proper exception handling lol
    {

    }
    return "";
}
