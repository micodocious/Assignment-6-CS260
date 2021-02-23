# Assignment-6-CS260

### Create some tests (at least one per function) that you want your Binary Search Tree (BST) to pass before you start coding.
When given (50,60,30,90,20,40,55)
some tests include testing the insertion function to expect (50,30,60,20,40,55,90)
Expecting 
Inorder traversal of tree
20, 30, 40, 50, 55, 60, 90,
Preorder traversal of tree
50, 20, 30, 40, 55, 60, 90,
Post traversal of tree
20, 30, 40, 55, 60, 90, 50,

## Implement a binary search tree that includes:

1. nodes to store values,

2. an add function that adds a new value in the appropriate location based on our ordering rules,
(I likely used less than or equal to going to the left and greater than values going to the right)

3. a remove function that finds and removes a value and then picks an appropriate replacement node
(successor is a term often used for this)

4. we have at least one tree traversal function

Bonus if you implement the three common traversals (pre-order, post-order, in-order)

More Bonus if you also include a breadth-first traversal (sometimes called a level-order search)

5. Analyze and compare the complexity of insert and search as compared to a binary tree without any order in its nodes.
- For a binary Tree and BST,searching gives a worst case complexity of O(n) because it has to traverse all its children, same with insertion. 
