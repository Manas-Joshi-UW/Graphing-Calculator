#include <iostream>
#include <string>
#include <map>
#include "parser.h"
using namespace std;
int main()
{
    string expression;
    cout << "Hello word"<<endl;
    cin >> expression;
    Parse_Expression(expression, expression.length());
    return 0;
}
