#include <string>
#include <deque>
#include <map>
#include "calculate.h"
using namespace std;



bool IsNumber(char symbol);
bool IsUnary (string expression, int count);
float GetNumber(string expression, int* count, int length);
bool IsOperator(char symbol);
string HandleUnary(string expression, int count, int length);
deque<float> Createdeque();
Tree* Create_Tree();
void Add_To_MostRight(char operation, Tree* tree);
void Add_Operator_To_Tree(char operation, Tree* tree);
float Parse_Expression(string expression, int length);
void Delete_deque(deque<float>* deque);

