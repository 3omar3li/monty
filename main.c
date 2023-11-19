#include "monty.h"

stack_t *head = NULL;

/**
 * main - main function
 * @argc: function parameter,
 *	arguments count
 * @argv: function parameter,
 *	list of arguments
 * Return: always 0
*/

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	open_file(argv[1]);
	free_nodes();
	return (0);
}

/**
 * create_node - function thats creates a node
 * @n: function parameter,
 *	number to go inside the node
 * Return: upon success a pointer to the node,
 *	Otherwise NULL
*/

stack_t *create_node(int n)
{
	stack_t *node;

	node = malloc(sizeof(stack_t));
	if (node == NULL)
	{
		err(4);
	}
	node->next = NULL;
	node->prev = NULL;
	node->n = n;
	return (node);
}

/**
 * free_nodes - frees nodes in the stack
 * Return: void
*/

void free_nodes(void)
{
	stack_t *tmp;

	if (head == NULL)
	{
		return;
	}
	while (head != NULL)
	{
		tmp = head;
		head = head->next;
		free(tmp);
	}
}

/**
 * add_to_queue - function thats add a node to the queue
 * @new_node: pointer to the new node
 * @ln: line number of the opcode
 * Return: void
*/

void add_to_queue(stack_t **new_node, __attribute__((unused))unsigned int ln)
{
	stack_t *tmp;

	if (new_node == NULL || *new_node == NULL)
	{
		exit(EXIT_FAILURE);
	}
	if (head == NULL)
	{
		head = *new_node;
		return;
	}
	tmp = head;
	while (tmp->next != NULL)
	{
		tmp = tmp->next;
	}
	tmp->next = *new_node;
	(*new_node)->prev = tmp;
}
