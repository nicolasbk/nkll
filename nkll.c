#include <stdio.h>
#include <stdlib.h>
#include "nkll.h"

node_t *create_node(int value){
	node_t* new_node = malloc(sizeof(node_t));
	new_node->number = value;
	new_node->next = NULL;
	return new_node;
}

node_t *insert_head(node_t **head, node_t **tail, node_t *new_head){
	new_head->next = *head;
	*head = new_head;
	if(*tail == NULL)
		*tail = new_head;
	return new_head;
}
node_t *insert_tail(node_t **head, node_t **tail, node_t *new_tail){
	if(*tail == NULL){
		*tail = new_tail;
		*head = new_tail;
		new_tail->next = NULL;
		return new_tail;
	}
	(*tail)->next = new_tail;
	new_tail->next = NULL;
	*tail = new_tail;
	return new_tail;
}

/* TODO
 * insert_after
 */

void remove_node(node_t **head, node_t **tail, node_t *rmv_node){
	// If head and tail are equal, there's only one node
	if(*head == *tail){
		*head = *tail = NULL;
		free(rmv_node);
		return;
	}

	// If node to remove if the head, set the new
	if(rmv_node == *head){
		*head = (*head)->next;
		free(rmv_node);
		return;
	}
	node_t *curr = *head;
	// 
	for(;curr->next != rmv_node; curr = curr->next);
	if(curr->next == *tail)
		*tail = curr;
	curr->next = rmv_node->next;
	free(rmv_node);
	return;
}

void remove_all(node_t **head, node_t **tail){
	node_t *curr = *head;
	node_t *save = NULL;
	while(curr != NULL){
		save = curr;
		curr = curr->next;
		free(save);
	}
	*head = *tail = NULL;
	return;
}

node_t *find(node_t *head, int value){
	node_t *curr = head;
	for(;curr->number != value && !(curr->next == NULL); curr = curr->next);
	if(curr->number != value)
		return NULL;
	return curr;
}

void print_list(node_t *head){
	if(head == NULL){
		printf("List is empty\n");
		return;
	}
	for(node_t *curr = head; curr != NULL; curr = curr->next)
		printf("%d - ", curr->number);
	printf("\n");
	return;
}

void print_head_and_tail(node_t *head, node_t *tail){
	printf("Head:\n");
	printf("\tpointer: %p\n", head);
	printf("\tnumber: %d\n\n", head->number);
	printf("Tail:\n");
	printf("\tpointer: %p\n", tail);
	printf("\tnumber: %d\n\n", tail->number);
}
