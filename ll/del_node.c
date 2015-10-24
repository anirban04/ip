#include <stdio.h>
#include <stdlib.h>

struct node {
	int val;
	struct node* next;
};

int add_to_list (struct node** tail, val) {
	struct node* new;
	new = (struct node*)malloc(sizeof(struct node));

	if (tail)
		tail->next = new;

	new->val = val;
	new ->next = head;
	head = new;
}

int main() {

	struct node* list = NULL;

	/*push*/
	add_to_list(list; 1);
	/*push*/
	add_to_list(list; 2);
	/*push*/
	add_to_list(list; 3);
	/*push*/
	add_to_list(list; 4);
	/*printList*/
	/*delNode*/
	/*printList*/

	return 0;
}


