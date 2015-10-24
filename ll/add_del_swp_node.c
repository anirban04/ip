#include <stdio.h>
#include <stdlib.h>

struct node {
	int val;
	struct node* next;
};

void push(struct node** head_ref, int val)
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
		return -1;
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
		return -1;
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

int del_node(struct node** head_ref, int val)
{
	struct node* curr = *head_ref;
	struct node* prev = *head_ref;

	if(!curr) {
		printf("list is empty\n");
		return -1;
	}

	while(curr) {
		if(curr->val == val) {
			/* Check if this is the first node */
			if (curr == *head_ref)
				*head_ref = curr->next;
			else
				prev->next = curr->next;
		
			free(curr);
		}
		prev = curr;
		curr = curr->next;
	}
}

int get_count_it(struct node* head)
{
	int cnt = 0;
	struct node* curr = head;

	while (curr) {
		curr = curr->next;
		cnt++;
	}

	return cnt;
}

int get_count_rc(struct node* head)
{
	/* Check for head == NULL */
	if (!head)
		return 0;

		return 1 + get_count_rc(head->next);
}

int main()
{
	struct node* head = NULL;
	append(&head, 6); //6->NULL
	push(&head, 7); //7->6->NULL
	push(&head, 1); //1->7->6->NULL
	append(&head, 4); //1->7->6->4->NULL
	insert_after(head->next, 8); //1->7->8->6->4->NULL
	printf("Before Deleting - num elements = %d\n", get_count_it(head));
	print_list(head);
	del_node(&head, 1);
	del_node(&head, 8);
	printf("After Deleting - num elements = %d\n", get_count_rc(head));
	print_list(head);
	return 0;
}


