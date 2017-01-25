#include "calculate.h"
#include "constants.h"
#include <cmath>
#include <deque>
#include <iostream>
#include <map>
#include <string>

float Proper_Pop(deque<float> *numbers) {
  float number;
  number = (*numbers).front();
  (*numbers).pop_front();
  return number;
}

float Proper_BackPop(deque<float> *numbers) {
  float number;
  number = (*numbers).back();
  (*numbers).pop_back();
  return number;
}

void ReformDeque(Node *root, deque<float> *numbers) {
  if (root == nullptr) {
    return;
  }

  if (root->right == nullptr && root->left == nullptr) {
    (*numbers).push_front(Proper_BackPop(numbers));
    (*numbers).push_front(Proper_BackPop(numbers));
  } else {
    (*numbers).push_front(Proper_BackPop(numbers));
    ReformDeque(root->left, numbers);
    ReformDeque(root->right, numbers);
  }
}

float Calculate(string operation, deque<float> *numbers) {
  try {
    switch (operation[0]) {
    case PLUS:
      return Proper_Pop(numbers) + Proper_Pop(numbers);
      break;
    case MINUS:
      return Proper_Pop(numbers) - Proper_Pop(numbers);
      break;
    case DIVIDE: {
      float a = Proper_Pop(numbers);
      float b = Proper_Pop(numbers);
      if (b == 0) {
        throw "Division by 0 error!";
      }
      return a / b;
      break;
    }
    case MULTIPLY:
      return Proper_Pop(numbers) * Proper_Pop(numbers);
      break;
    case EXPONENT:
      return pow(Proper_Pop(numbers), Proper_Pop(numbers));
      break;

    default:
      cout << "An error occurred." << endl;
      return 0;
      break;
    }
  } catch (string message) {
    cerr << message << endl;
  } catch (...) {
    cerr << "Unknown error" << endl;
  }
  return 0;
}

float Calculate_Expression(Node *root, deque<float> *numbers) {
  int count = 0;
  try {
    if (root == nullptr && (*numbers).size() == 0) {
      return 0;
    } else if (root == nullptr && (*numbers).size() == 1) {
      return Proper_Pop(numbers);
    }

    if (root->right == nullptr && root->left == nullptr) {
      return Calculate(root->root_val, numbers);
    }

    if (root->right == nullptr) {
      (*numbers).push_front(Calculate_Expression(root->left, numbers));
      return Calculate(root->root_val, numbers);
    }

    if (root->left == nullptr) {
      float a = Proper_Pop(numbers);
      (*numbers).push_front(Calculate_Expression(root->right, numbers));
      (*numbers).push_front(a);
      return Calculate(root->root_val, numbers);
    }

    if (root->left != nullptr && root->right != nullptr) {
      (*numbers).push_front(Calculate_Expression(root->left, numbers));
      Delete_Node(root->left);
      return Calculate_Expression(root, numbers);
    }
    return Calculate(root->root_val, numbers);
  } catch (char *msg) {
    cerr << msg << "\n";
    return 0;
  }
}

// Delete_Node(Node* node) will delete node and it's branches.
void Delete_Node(Node *node) {
  while (node != nullptr) {
    Delete_Node(node->right);
    Delete_Node(node->left);
    delete node;
  }
}
