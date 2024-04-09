#include "simple.h"
/**
 * _link - built linked list with directories
 * @a: PATH
 * Return: head
 **/

link_t *_link(char *a)
{
	link_t *head = NULL;
	char *TOKEN;

	TOKEN = _strtok(a, ":");
	while (TOKEN != NULL)
	{
		head = _add_nodeint_end(&head, TOKEN);
		TOKEN = _strtok(NULL, ":");
	}
	return (head);
}

/**
 * _add_nodeint_end - adds new string to end node
 * @head: head
 * @n: directories
 * Return: head
 **/

link_t *_add_nodeint_end(link_t **head, char *n)
{
	link_t *new_node;
	link_t *last_node = *head;

	new_node = malloc(sizeof(link_t));
	if (new_node == NULL)
		return (NULL);
	new_node->dir = n;
	new_node->next = NULL;
	if (*head == NULL)
	{
		*head = new_node;
		return (*head);
	}
	else
	{
		while (last_node->next != NULL)
		{
			last_node = last_node->next;
		}
		last_node->next = new_node;
	}
	return (*head);
}

/**
 * free_list - frees a list_t list
 * @head: node head
 */

void free_list(link_t *head)
{
	link_t *temp;

	while (head != NULL)
	{
		temp = head;
		head = head->next;
		free(temp);
	}
}
