task 0
New node
Write a function that creates a binary tree node:

Prototype: binary_tree_t *binary_tree_node(binary_tree_t *parent, int value);
parent is a pointer to the parent node of the node to create
value is the value to put in the new node
When created, a node does not have any children
Your function must return a pointer to the new node, or NULL on failure


task 1
Heap - Insert
mandatory
Write a function that inserts a value into a Max Binary Heap:

Prototype: heap_t *heap_insert(heap_t **root, int value);
root is a double pointer to the root node of the Heap
value is the value to store in the node to be inserted
Your function must return a pointer to the inserted node, or NULL on failure
If the address stored in root is NULL, the created node must become the root node.
You have to respect a Max Heap ordering
You are allowed to have up to 6 functions in your file
