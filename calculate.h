#include <deque>
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



float Calculate(string operation, deque<float> *numbers);
float Calculate_Expression(Node* root, deque<float> *numbers);
