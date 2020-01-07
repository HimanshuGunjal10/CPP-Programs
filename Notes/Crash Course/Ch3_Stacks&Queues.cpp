
Stacks: Use to implement a recusrsive approach iteratively.
usecase: when you are using recursion and want to temporarily store data and check in the next step as you recurse.
if failed remove it

------------
3.2 Stack Min
------------

Approach 1: maintain a new variable in the stack calss called minele and for each node, have the current min element stored
when you push new just check if new element is less than top`s minele and accordingly set the minele of the new node
For each node, we have another integer. so buliding up space

Approach 2: maintain another stack of minelements.
At each push or pop check if the new element is less than the top of the minelestack.
best approach.