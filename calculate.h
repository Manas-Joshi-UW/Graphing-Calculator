#include <queue>
#include <string>

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



float Calculate(string operation, queue<float> *numbers);
float Calculate_Expression(Node* root, queue<float> *numbers);
