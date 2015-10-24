#include <stdio.h>
#include <stdlib.h>

struct node {
	int val;
	struct node* next;
};

int push(struct node** head_ref, int val)
{
	struct node* new = (struct node*)malloc(sizeof(struct node));
	new->val = val;
	new->next = *head_ref;
	*head_ref = new;
}

int append(struct node** head_ref, int val)
{
	struct node* new = (struct node*)malloc(sizeof(struct node));
	struct node* last = *head_ref;
	
	new->val = val;
	new->next = NULL;
	
	/*Check if the list is empty*/
	if (NULL == *head_ref)
	{
		*head_ref = new;
		return;
	}

	/*Go to the end of the list*/
	while(last->next)
		last = last->next;

	last->next = new;
	return;
}

int insert_after(struct node* prev_node, int val)
{
	struct node* new;

	/*Check if prev_node is null*/
	if(NULL == prev_node) {
		printf("prev_node cannot be null\n");
		return;
	}

	new = (struct node*)malloc(sizeof(struct node));
	new->val = val;
	new->next = prev_node->next;
	prev_node->next = new;
}

int print_list(struct node* node)
{
	while(node) {
		printf("%d \n", node->val);
		node = node->next;
	}
}

int main()
{
	struct node* head = NULL;
	append(&head, 6); //6->NULL
	push(&head, 7); //7->6->NULL
	push(&head, 1); //1->7->6->NULL
	append(&head, 4); //1->7->6->4->NULL
	insert_after(head->next, 8); //1->7->8->6->4->NULL
	print_list(head);
	return 0;
}
