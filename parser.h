#include <string>
#include <queue>
using namespace std;

struct Node{
    string root_val;
    Node* right;
    Node* left;
};

struct Tree
{
    Node* root;
};


bool IsNumber(char symbol);
bool IsUnary (string expression, int count);
string GetNumber(string expression, int count, int length);
bool IsOperator(char symbol);
string HandleUnary(string expression, int count, int length);
