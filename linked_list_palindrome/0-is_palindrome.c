#include "lists.h"
#include <stddef.h>

/**
 * is_palindrome - checks if a singly linked list is a palindrome
 * @head: double pointer to the first node of a singly linked list
 *
 * Return: 0 if not palindrome, 1 if palindrome
 */

int is_palindrome(listint_t **head)
{
	/* if not given valid pointer (no list), return 0 */
	if (head == NULL)
		return (0);
	/* if linked list is empty, return 1 */
	if (*head == NULL)
		return (1);
	/* otherwise, use recursive palindrome_check function */
	return (palindrome_check(head, *head));
}

/**
 * palindrome_check - checks is list is a palindrome recursively
 * @head: double pointer to beginning of list
 * @mover: single pointer to list to move to end
 *
 * Return: 0 if not palindrome, 1 if palindrome
 */
int palindrome_check(listint_t **head, listint_t *mover)
{
	/* move pointer to the end of the linked list */
	if (mover->next)
	{
		/* if return is true, move front pointer forward */
		/* moving head to next node will allow to check against end */
		/*   when recurisively working back up through the stack */
		if (palindrome_check(head, mover->next))
			(*head) = (*head)->next;
		/* otherwise, indicate already failed check */
		else
			return (0);
	}
	/* check if front pointer matches end pointer */
	if ((*head)->n == mover->n)
		/* if true, return success to move up stack which will move */
		/*   front pointer forward and end pointer backward */
		return (1);
	/* otherwise, indicate up through the stack that failed check */
	return (0);
}
