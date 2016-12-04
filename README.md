# Infix Notation Parser

I wanted to learn C++ and was trying to think of a suitable project that would help me learn a variety of things. I decided to create an Infix Notation Expression Parser. 

### Background
Infix Notation Expression: "3+2"

Reverse Polish Notation(RPN): "3 2 +"

One of the more popular ways of calculating Infix notation expressions is by turning it into RPN using the `Shunting Yard Algorithm`: https://en.wikipedia.org/wiki/Shunting-yard_algorithm. I decided against using the algorithm and came up with a simpler method to parse the expression. I use a tree to hold the operators and a deque to store the numbers. 

In this process I was able to implement data structures in c++ and learn about dynamic memory, as well as the general syntax.

There were 2 main challenges in the end: 
- Making sure the tree was correct (the algorithm works from the tests I had ran)
- Making sure the calculation was done correctly(at the time of writing this, it has passed my tests, but had failed several times during the testing process)

To begin I only had an interest in solving the first challenge, as without solving it, the second step couldn't be done. 
I eventually came up with a prety easy algorithm.

### The Operator Algorithm
This was a rather simple algorithm to implement. Assuming the current character was an operator(and not unary, which I have handled in my program)

- First check if root of tree is null, if so, the node of the tree will contain that operator. 

- If tree is not null, check if the operator has a lower or equal precedence to that of the root. If so, the left of the tree becomes the root and the root of the tree contains the new operator. 

- If the operator has a higher precedence, add the new operator to the most right of the tree. 


The numbers were simply added to the front/back of the deque when appropriate. 

### The Calculation Algorithm
This is pretty straightforward and can be seen through my code. Calculating the left of the tree is pretty easy. For the right, I needed to make sure I was using the correct numbers from the queue. Thus, if the left was null, I would simply pop 1 number from the front deque and would carry on with calculating the right of the tree. If the left wasn't null, I would caluclate the left of the tree, destroy the left side, and rerun the function with the left side now being null. Once I calculated the right side of the tree, I would push the number gained from the left side onto the front of the tree.

 
