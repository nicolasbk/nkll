#include <stdio.h>
#include <stdlib.h>
#include "nkll.h"

int main(void){
	int op = 0;
	int value = 0;
	node_t *tail = NULL;
	node_t *head = NULL;
	node_t *node = NULL;
	do{
		printf("Select an option:\n");
		printf("1 - Insert head\n");
		printf("2 - Insert tail\n");
		printf("3 - Print list\n");
		printf("4 - Find node\n");
		printf("5 - Remove node\n");
		printf("6 - Exit program\n");
		scanf("%d", &op);
		switch(op){
			case 1:
				printf("Enter node value:\n");
				scanf("%d", &value);
				node = create_node(value);
				insert_head(&head, &tail, node);
				printf("New head inserted\n");
				break;
			case 2:
				printf("Enter node value:\n");
				scanf("%d", &value);
				node = create_node(value);
				insert_tail(&head, &tail, node);
				printf("New tail inserted\n");
				break;
			case 3:
				print_list(head);
				break;
			case 4:
				printf("Enter node value:\n");
				scanf("%d", &value);
				node = find(head, value);
				if(node == NULL){
					printf("%d not in list\n", value);
					break;
				}
				printf("%d found", node->number);
				break;

			case 5:
				printf("Enter node value:\n");
				scanf("%d", &value);
				node = find(head, value);
				if(node == NULL){
					printf("%d not in list\n", value);
					break;
				}
				printf("Removing %d from list\n", node->number);
				remove_node(&head, &tail, node);
				break;
			case 6:
				remove_all(&head, &tail);
				break;
			default:
				printf("Invalid option!\n");
		}
	}while(op != 6);

	return 0;
}
