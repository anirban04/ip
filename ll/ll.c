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
		return 0;
	}

	/*Go to the end of the list*/
	while(last->next)
		last = last->next;

	last->next = new;
	return 0;
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


/* Function to swap 2 nodes of a linked list given their values */
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

/* Function to return the value stored in the nth node of a linked list */
int get_nth_node(struct node* head, int index)
{
	struct node* curr = head;

	while(curr) {
		index--;
		if (!index)
			return curr->val;
		curr = curr->next;
	}
	return -1;
}

/* Floyd's cycle finding algo - Move 2 pointers first one by 1, second one by 2; if the meet - loop present */
int detect_loop(struct node* head)
{
	struct node* x = head;
	struct node* y = head;

	while(x && y && y->next) {
		x = x->next;
		y = y->next->next;

		if (x == y)
			return 1;
	}

	return 0;
}

int del_node_by_ptr(struct node* node)
{
	struct node* tmp = node->next;

	if (!tmp) {
		printf("This is the last node  - My algo does not work\n");
		return -1;
	}

	node->val = tmp->val;
	node->next = tmp->next;
	free(tmp);
}

/* Main Idea is to traverse the list with curr and keep breaking the next link and making it point to prev */
int reverse_list(struct node** head_ref)
{
	/* Use 3 pointers, start with prev = NULL and curr = head */
	struct node* p = NULL;
	struct node* c = *head_ref;
	struct node* n;

	/* only chek for C cince that is only what we dereference */
	while(c)
	{
		/* Do not update next until here */
		n = c->next;
		/* Cut the link to next and make it point to prev */
		c->next = p;
		/* Update p and c */
		p = c;
		c = n;
	}

	/*Finally update head_ref*/
	*head_ref = p;

	return 0;
}

/* Given a sorted list - Insert an element in a sorted way */
int insert_sorted (struct node** head_ref, struct node* new)
{
	struct node* c;
	struct node* p;
	struct node* tmp;
	p = NULL;
	c = *head_ref;


	/* If list is empty, make this the only element in the list */
	if(!c) {
		*head_ref = new;
		new->next = NULL;
		return 0;
	}

	/* If value of node to be inserted is smaller than the head node then insert at the start */
	if(new->val < c->val) {
		new->next = c->next;
		*head_ref = new;
		return 0;
	}

	/* Find where in the list does this fit in */
	while(c && (new->val > c->val))
	{
		p = c;
		c = c->next;
	}

	tmp = p->next;
	p->next = new;

	if(!c) {
		/* Add to the end of the list */
		new->next = NULL;
	}
	else {
		/* Add after prev */
		new->next = tmp;
	}
}

int remove_duplicates_from_sorted_list(struct node** head_ref)
{
	struct node* p;
	struct node* c;

	p = *head_ref;

	if (!p) {
		printf("List id Null\n");
		return -1;
	}
		
	c = p->next;

	while(c) {
		if (c->val == p->val) {
			/* Delete current */
			p->next = c->next;		
			free(c);
		}
		p = c;
		c = c->next;
	}

}

/* Print the reverse of a linked list in a recursive way */
int recursive_print_reverse(struct node* head)
{
	/* Check for exit case */
	if (head->next)
		recursive_print_reverse(head->next);

	/* Print the value */
	printf("%d\n", head->val);

	return 0;
}

int move_last_to_front(struct node** head_ref)
{
	struct node* c = *head_ref;
	struct node* p = NULL;

	/* Handle the case of no elements in the list */
	if(!c)
		return -1;

	/* Handle the case of only 1 element in the list */
	if(NULL == c->next)
		return -1;

	/* Iterate to the end of the list with 2 pointers */
	while(c->next) {
		p = c;
		c = c->next;
	}

	p->next = NULL;
	c->next = *head_ref;
	*head_ref = c;

	return 0;
}

int create_intersection_of_sorted_lists(struct node** head_ref, struct node* head1, struct node* head2)
{
	struct node* orig_head2 = head2;

	while(head1) {
		while((head2) && (head1->val >= head2->val)) {
			if(head1->val == head2->val) {
				append(head_ref, head1->val);
			}
			head2 = head2->next;
		}
		head1 = head1->next;
		//head2 = orig_head2; // This is needed only for unsorted list
	}
}

int main()
{
	struct node* head = NULL;
	struct node* head1 = NULL;
	struct node* head_int = NULL;
	struct node* new_node;


	append(&head1, 1);
	append(&head1, 3);
	append(&head1, 7);
	append(&head1, 8);
	append(&head1, 9);

	append(&head, 7);
	push(&head, 6);
	push(&head, 5);
	push(&head, 4);
	push(&head, 3);
	push(&head, 2);
	push(&head, 1);
	//insert_after(head->next, 8); //1->7->8->6->4->NULL
	//printf("Before num elements = %d\n", get_count_it(head));
	//print_list(head);
	//del_node(&head, 1);
	//del_node(&head, 8);
	//swap_nodes(&head, 1, 6);
	//swap_nodes(&head, 1, 6);
	//swap_nodes(&head, 1, 4);
	//printf("val at %d node = %d\n", 5, get_nth_node(head, 5));
	//del_node_by_ptr(head);
	//reverse_list(&head);
	//new_node = (struct node*)malloc(sizeof(struct node));
	//new_node->val = 4;
	//insert_sorted(&head, new_node);
	//printf("After num elements = %d\n", get_count_rc(head));
	//print_list(head);
	//remove_duplicates_from_sorted_list(&head);
	//printf("After num elements = %d\n", get_count_rc(head));
	printf("First \n");
	print_list(head);
	//printf("Printing Reverse\n");
	//recursive_print_reverse(head);
	//move_last_to_front(&head);
	//printf("loop detection = %d\n", detect_loop(head));
	//printf("After moving last to front\n");
	printf("Second \n");
	print_list(head1);
	create_intersection_of_sorted_lists(&head_int, head, head1);
	printf("Intersection \n");
	print_list(head_int);
	return 0;
}


