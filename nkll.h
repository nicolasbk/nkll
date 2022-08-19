#ifndef NKLL_H
#define NKLL_H

struct node {
	int number;
	struct node* next;
};

typedef struct node node_t;

node_t *create_node(int value);
node_t *insert_head(node_t **head, node_t **tail, node_t *new_head);
node_t *insert_tail(node_t **head, node_t **tail, node_t *new_tail);
node_t *insert_after(node_t **head, node_t **tail, node_t *curr_node, node_t *new_node);
void remove_node(node_t **head, node_t **tail, node_t *rmv_node);
void remove_all(node_t **head, node_t **tail);
node_t *find(node_t *head, int value);
void print_list(node_t *head);
void print_head_and_tail(node_t *head, node_t *tail);

#endif // NKLL_H
