#include <stdlib.h>
#include <stdio.h>
#include "lists.h"


/**
 * insert_node - Inserts a number into a sorted singly linked list
 * @head: Pointer to the pointer of the head node
 * @number: Number to insert
 *
 * Return: Address of the new node, or NULL if it failed
 */
listint_t *insert_node(listint_t **head, int number){
    //Alocate memory for the new node
    listint_t *new_node = malloc(sizeof(listint_t));
    // Handle failure
    if (new_node == NULL)
        return (NULL);
    //Initialize the new node
    new_node->n = number;
    new_node->next = NULL;

    // Insert at the beginning or when list is empty
    if (*head == NULL || (*head)->n >= number)
    {
        new_node->next = *head;
        *head = new_node;
        return (new_node);
    }

    // Traverse the list to find the correct insertion point
    listint_t *current = *head;
    while (current->next != NULL && current->next->n < number)
    {
        current = current->next;
    }
    // Insert the new node between `current` and `current->next`
    new_node->next = current->next;
    current->next = new_node;

    return (new_node);
}
