#include <iostream>
#include <string>
#include <queue>
#include "parser.h"
#include "constants.h"
using namespace std;



queue<string>* CreateQueue(){
    queue<string>* numbers_queue;
    return numbers_queue;
}

Tree* Create_Tree(){
    Tree* tree = new Tree();
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
string HandleUnary(string expression, int* count, int length){
    int append_negative = 0;
    string number;
    try
    {
        for (int i = *count; i < length; ++i){
            if(expression[i] == MINUS){
                append_negative++;
            }
            else if(IsNumber(expression[i])){
                number = GetNumber(expression, i, length);
                *count = i;
                break;
            }
            else if (expression[i] != PLUS || (expression[i] != DECIMAL && IsNumber(expression[i+1]))){
            // if we don't detect a + and a .NUMBER then there is an error in input
                throw "expression was not written correctly,
                       error was caught in position:" + i +
                      "\n" + expression[i-1] + expression[i]
                      + expression[i+1];
            }
        }

        if(append_negative){
            number = "-" + number;
        }

        return number;
    }
    catch (char* msg)
    {
        cerr << msg << "\n";
    }
    return "";
}

bool Lower_Precedence(char root_operation, char new_operation){
    // TODO: implement this function AFTER the dictionary is made.
    return true;
}

// Add_To_MostRight(char operation, Tree* tree) will add operation
void Add_To_MostRight(char operation, Tree* tree) {
    Node* curr_node = tree->root;
    while(1){
        if(curr_node->right == nullptr){
            Node* temp = new Node();
            temp->root_val = operation;
            temp->left = nullptr;
            temp->right = nullptr;

            tree->root = temp;
            break;
        }
        curr_node = curr_node->right;
    }
}

void Add_Operator_To_Tree(char operation, Tree* tree){
    // TODO: check whether the pointers work out
    if(Lower_Precedence(tree->root, operation)){
        Node* temp = new Node();
        temp->root_val = operation;
        temp->left = tree->root;
        temp->right = nullptr;

        tree->root = temp;
        delete temp;
    } else
    {
        Add_To_MostRight(operation, tree);
    }

}

void Parser_Expression(string expression, int length){
    queue<string>* queue = Create_Queue(); // initialize the queue
    Tree* tree = Create_Tree(); // intialize the tree

    char curr_char;

    for (int count = 0; count < length; ++count)
    {
        curr_char = expression[count];

        if(IsUnary(expression, count)){
            HandleUnary(expression, &count, length);
        }

        if(IsNumber(curr_char)){
            // TODO: Add number to the queue
            GetNumber(expression, &count, length);
        }

        if(IsOperator(curr_char)){
            // TODO: Add operator to the tree

        }
    }
}


void Delete_Queue(queue<string>* queue){
    // TODO: check if there is a easy way to delete the queue.
}


void Delete_Node(Node* node){
    while (node != nullptr)
    {
        Delete_Node(node->right);
        Delete_Node(node->left);
        delete node;
    }
}


void Delete_Tree(Tree* tree){
    Delete_Node(tree->root);
    delete tree;
}
