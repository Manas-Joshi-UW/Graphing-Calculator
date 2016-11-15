#include <string>
#include <queue>
#include <iostream>
#include "calculate.h"
#include "constants.h"
#include <cmath>
#include <map>

float Proper_Fucking_Pop(queue<float> *numbers){
    float number;
    number = (*numbers).front();
    (*numbers).pop();
    return number;
}

float Calculate(string operation, queue<float> *numbers){
    switch (operation[0])
    {
    case PLUS:
        return Proper_Fucking_Pop(numbers) + Proper_Fucking_Pop(numbers);
        break;
    case MINUS:
        return Proper_Fucking_Pop(numbers) - Proper_Fucking_Pop(numbers);
        break;
    case DIVIDE:
        return Proper_Fucking_Pop(numbers) / Proper_Fucking_Pop(numbers);
        break;
    case MULTIPLY:
        return Proper_Fucking_Pop(numbers) * Proper_Fucking_Pop(numbers);
        break;
    case EXPONENT:
        return pow(Proper_Fucking_Pop(numbers),Proper_Fucking_Pop(numbers));
        break;

    default:
        cout << "An error occurred." << endl;
        return 0;
        break;
    }
}

float Calculate_Expression(Node* root, queue<float> *numbers){
    try
    {
        if(root == nullptr && (*numbers).size() == 0){
            return 0;
        }else if(root == nullptr && (*numbers).size() == 1){
            return Proper_Fucking_Pop(numbers);
        }

        if(root->right == nullptr && root->left == nullptr){
            return Calculate(root->root_val, numbers);
        }

        if(root->right == nullptr){
            (*numbers).push(Calculate_Expression(root->left, numbers));
            return Calculate(root->root_val, numbers);
        }

        if(root->left == nullptr){
            (*numbers).push(Calculate_Expression(root->right, numbers));
            return Calculate(root->root_val, numbers);
        }

        if(root->left != nullptr && root->right != nullptr){
            (*numbers).push(Calculate_Expression(root->left, numbers));
            (*numbers).push(Calculate_Expression(root->left, numbers));
        }
        return Calculate(root->root_val, numbers);
    }
    catch (char* msg)
    {
        cerr << msg << "\n";
        return 0;
    }

}
