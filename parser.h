#include <string>
#include <queue>
#include <map>

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
string GetNumber(string expression, int* count, int length);
bool IsOperator(char symbol);
string HandleUnary(string expression, int count, int length);
queue<string> CreateQueue();
Tree* Create_Tree();
void Add_To_MostRight(char operation, Tree* tree);
void Add_Operator_To_Tree(char operation, Tree* tree);
void Parse_Expression(string expression, int length);
void Delete_Queue(queue<string>* queue);
void Delete_Node(Node* node);
