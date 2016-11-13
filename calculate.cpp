#include <string>
#include <queue>
#include "parser.h"
#include "calculate.h"
#include "constants.h"
#include <cmath>
#include <map>

int Calculate(string operation, queue<string> *numbers){
    switch (operation)
    {
    case "+":
        return (*numbers).pop() + (*numbers).pop();
        break;
    case "-":
        return (*numbers).pop() - (*numbers).pop();
        break;
    case "/":
        return (*numbers).pop() / (*numbers).pop();
        break;
    case "*":
        return (*numbers).pop() * (*numbers).pop();
        break;
    case "^":
        return pow((*numbers).pop(),(*numbers).pop())
        break;

    default:
        cout << "An error occurred." << endl;
        break;
    }
}

int Calculate_Expression(Node* root, queue<string> *numbers){
    try
    {
        if(root == nullptr && (*numbers).size() == 0){
            return 0;
        }else if(root == nullptr && (*numbers).size() == 1){
            return (*numbers).pop();
        }

        if(root->right == nullptr && root->left == nullptr){
            return Calculate(root->root_val, numbers);
        }

        if(root->right == nullptr){
            numbers.push(Calculate_Expression(root->left, numbers));
            return Calculate(root->root_val, numbers);
        }

        if(root->left == nullptr){
            umbers.push(Calculate_Expression(root->right, numbers));
            return Calculate(root->root_val, numbers);
        }

        if(root->left != nullptr && root->right != nullptr){
            numbers.push(Calculate_Expression(root->left, numbers));
            numbers.push(Calculate_Expression(root->left, numbers));
            Calculate(root->root_val, queue<string> *numbers)
        }
    }
    catch (char* msg)
    {
        cerr << msg << "\n";
    }
}
