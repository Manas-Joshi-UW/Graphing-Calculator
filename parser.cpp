#include <string>
#include <deque>
#include <iostream>
#include "parser.h"
#include "constants.h"
#include <map>
using namespace std;


// Createdeque() will create the deque in which the numbers will be stored.
deque<float> Createdeque(){
    deque<float> numbers_deque;
    return numbers_deque;
}

// Create_Tree() will create the tree in which the operations are stored.
Tree* Create_Tree(){
    Tree* tree = new Tree();
    tree->root = nullptr;
    return tree;
}

// IsNumber checks whether symbol is a number or not.
bool IsNumber(char symbol){
    if(symbol >= 48 && symbol <= 57){
        return true;
    }
    return false;
}


// IsUnary checks whether the character at position count in expression is a
// unary operator.
bool IsUnary (string expression, int count){
    try{
    if(count == 0 && (expression[count] == PLUS || expression[count] == MINUS)){
        return true;
    }else if(count == 0){
        return false;
    }
    if((IsNumber(expression[count-1]) || expression[count-1] == C_BRACKET)
       && IsOperator(expression[count])
       && (expression[count+1] == PLUS || expression[count+1] == MINUS)){
        return false;
    }
    if(IsOperator(expression[count-1]) && (expression[count] == PLUS || expression[count] == MINUS)){
        return true;
    }
        
    
    }
    catch(string msg){
        
    }
    catch(...){
        cout << "An error occurred, please ensure you've written the expression correctly"<<endl;
    }
    return false;
}


// GetNumber will get the number in expression which starts at position count.
// length is the length of expression.
float GetNumber(string expression, int* count, int length){
    string number;
    for (int i = *count; i < length; i++)
    {
        if(!IsNumber(expression[i]) && expression[i] != '.'){
            *count = i-1;
            break;
        }
        number += expression[i];
    }
    return stof(number);
}

// IsOperator(char symbol) will check if symbol is an operator.
bool IsOperator(char symbol){
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
float HandleUnary(string expression, int* count, int length){
    int append_negative = 0;
    float number = 1;
    try
    {
        for (int i = *count; i < length; ++i){
            if(expression[i] == MINUS){
                append_negative++;
            }
            else if(IsNumber(expression[i])){
                number = GetNumber(expression, &i, length);
                *count = i;
                break;
            }
            else if (expression[i] != PLUS || (expression[i] != DECIMAL && IsNumber(expression[i+1]))){
            // if we don't detect a + and a .NUMBER then there is an error in input
                throw "expression was not written correctly,"
                       "error was caught in position:" + to_string(i) +
                      "\n" + to_string(expression[i-1]) + to_string(expression[i])
                      + to_string(expression[i+1]);
            }
        }

        if(append_negative % 2 == 1){
            number = -1 * number;
        }

        return number;
    }
    catch (char* msg)
    {
        cerr << msg << "\n";
        return 0;
    }
}

// Add_To_MostRight(char operation, Tree* tree) will add operation to the most
// right branch in tree.
void Add_To_MostRight(char operation, Tree* tree) {
    Node* curr_node = tree->root;
    while(1){
        if(curr_node->right == nullptr){
            Node* temp = new Node();
            temp->root_val = operation;
            temp->left = nullptr;
            temp->right = nullptr;

            curr_node->right = temp;
            break;
        }
        curr_node = curr_node->right;
    }
}

// Add_Operator_To_Tree(char operation, Tree* tree) adds operation to
// tree appropriately.
void Add_Operator_To_Tree(char operation, Tree* tree){
    cout << "reaches here "<<endl;
    map<char,int> precedences;
    precedences[PLUS] = 5;
    precedences[MINUS] = 5;
    precedences[MULTIPLY] = 3;
    precedences[DIVIDE] = 3;
    precedences[EXPONENT] = 2;

    if(tree->root == nullptr){
        Node* temp = new Node();
        temp->root_val = operation;
        temp->left = nullptr;
        temp->right = nullptr;

        tree->root = temp;

        return;
    }
    char root_val = tree->root->root_val[0];
    if(precedences[root_val] <= precedences[operation]){
        Node* temp = new Node();
        temp->root_val = operation;
        temp->left = tree->root;
        temp->right = nullptr;

        tree->root = temp;
    } else
    {
        Add_To_MostRight(operation, tree);
    }
}

// Parse_Expression(string expression, int length) will parse expression,
// which has a length of length.
float Parse_Expression(string expression, int length){
    deque<float> deque = Createdeque(); // initialize the deque
    Tree* tree = Create_Tree(); // intialize the tree



    char curr_char;

    for (int count = 0; count < length; ++count)
    {
        curr_char = expression[count];

        if(curr_char == O_BRACKET){
            string expression_in_brackets = "";
            for (int i = count + 1; i < length; ++i)
            {
                if(expression[i] == C_BRACKET){
                    count = ++i - 1;
                    break;
                }
                expression_in_brackets += expression[i];
            }
           deque.push_back(Parse_Expression(expression_in_brackets, expression_in_brackets.length()));
        }

        if(IsUnary(expression, count)){
            deque.push_back(HandleUnary(expression, &count, length));
            continue;
        }

        if(IsNumber(curr_char)){
            // #TODO:20 Add number to the deque
            deque.push_back(GetNumber(expression, &count, length));
        }

        if(IsOperator(curr_char)){
            Add_Operator_To_Tree(curr_char, tree);
        }
    }
    return Calculate_Expression(tree->root, &deque);
}

// Delete_Node(Node* node) will delete node and it's branches.
void Delete_Node(Node* node){
    while (node != nullptr)
    {
        Delete_Node(node->right);
        Delete_Node(node->left);
        delete node;
    }
}

// Delete_Tree(Tree* tree) will delete the tree and it's nodes.
void Delete_Tree(Tree* tree){
    Delete_Node(tree->root);
    delete tree;
}
