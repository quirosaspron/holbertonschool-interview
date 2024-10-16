#include <stdlib.h>
#include "binary_trees.h"

/**
 * binary_tree_node - adds a node to the binary tree
 * @parent: pointer to the parent node of the node to create
 * @value:  value to put in the new node
 * Return: address of the new node or NULL if it fails
 */

binary_tree_t *binary_tree_node(binary_tree_t *parent, int value){

    binary_tree_t *new_node = malloc(sizeof(binary_tree_t));
    if (new_node == NULL){
        free(new_node);
        return (NULL);
    }

    if (parent){ 
        if (parent->left){ // if parent already has a left child
            if (parent->right){ // if parent also has a right child
                free(new_node);
                return (NULL);
            }
            else // there is no right child
                parent->right = new_node;
       }
       else // add to the left
           parent->left = new_node;
   }
   new_node->left = NULL;
   new_node->right = NULL;
   new_node->n = value;
   new_node->parent = parent;

   return (new_node);
}
