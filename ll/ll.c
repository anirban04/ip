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
	int cnt = 0;

	while(node && cnt < 10) {
		printf("%d \n", node->val);
		node = node->next;
		cnt++;
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

int get_pos_prev(struct node* head, int val, struct node** pos_prev)
{
	struct node* curr = head;
	struct node* prev = head;

	while(curr) {
		if(curr->val == val) {
			/* Check if this is the first node in the list */
			if(curr == head)
				*pos_prev = NULL;
			else
				*pos_prev = prev;
			return 0;
		}
		prev = curr;
		curr = curr->next;
	}

	if (!curr) {
		return -1;
	}
}

int swap_nodes(struct node** head_ref, int val1, int val2)
{
	struct node* node1_p;
	struct node* node2_p;
	struct node* node1;
	struct node* node2;
	struct node* tmp;

	if (val1 == val2)
		return 0;

	if (get_pos_prev(*head_ref, val1, &node1_p)) {
		printf("node 1 is not present in the list");
		return -1;
	}

	if (get_pos_prev(*head_ref, val2, &node2_p)) {
		printf("node 2 is not present in the list");
		return -1;
	}

	if (node1_p) {
		node1 = node1_p->next;
	}
	else {
		node1 = *head_ref;
	}

	if (node2_p) {
		node2 = node2_p->next;
	}
	else {
		node2 = *head_ref;
	}
	
	if (node1_p)
		node1_p->next = node2;
	else
		*head_ref = node2;

	if (node2_p)
		node2_p->next = node1;
	else
		*head_ref = node1;

	tmp = node1->next;
	node1->next = node2->next;
	node2->next = tmp;

	return 0;
}

int main()
{
	struct node* head = NULL;
	append(&head, 6); //6->NULL
	push(&head, 7); //7->6->NULL
	push(&head, 1); //1->7->6->NULL
	append(&head, 4); //1->7->6->4->NULL
	insert_after(head->next, 8); //1->7->8->6->4->NULL
	printf("Before num elements = %d\n", get_count_it(head));
	print_list(head);
	//del_node(&head, 1);
	//del_node(&head, 8);
	printf("After num elements = %d\n", get_count_rc(head));
	//swap_nodes(&head, 1, 6);
	//swap_nodes(&head, 1, 6);
	swap_nodes(&head, 1, 4);
	print_list(head);
	return 0;
}


