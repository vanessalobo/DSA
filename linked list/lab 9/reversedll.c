#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define SIZE 100

typedef struct Node* nodeptr;

struct Node {
	char *data;
	nodeptr next;
	nodeptr prev;
};



nodeptr createNode () {
	nodeptr temp = (nodeptr)malloc(sizeof(struct Node));
	temp->data = (char *)malloc(SIZE * sizeof(char));
	temp->prev = temp;
	temp->next = temp;
	return temp;
}

void insert (nodeptr list, char *val) {
	nodeptr temp = createNode();
	nodeptr p;

	temp->data = val;
	temp->next = list;

	list->prev = temp;

	if (list->next == list) {
		temp->prev = list;
		list->next = temp;
	}

	else {
		p = list->next;

		while (p->next != list)
			p = p->next;

		temp->prev = p;
		p->next = temp;
	}
}

void inputList (nodeptr list) {
	int i, n;

	printf("\n\tEnter number of terms in the list: ");
	scanf("%d", &n);

	printf("\n\tEnter the list: ");
	for (i = 0; i < n; ++i) {
		//		printf("\tEnter term %d: ", i+1);
		char *item = (char *)malloc(SIZE * sizeof(char));
		scanf(" %s", item);
		insert(list, item);
	}
}

nodeptr createAndInputList () {
	nodeptr li = createNode();
	inputList(li);
	return li;
}

/*
 nodeptr reverseList (nodeptr list) {
	nodeptr revList = createNode();
	nodeptr temp = list->prev;
	while (temp != list) {
 insert(revList, temp->data);
 temp = temp->prev;
	}
	return revList;
 }
 */

void reverseList2 (nodeptr list) {

	// finding half of the list using slow and fast pointers

	nodeptr slow = list->next;
	nodeptr fast = list->next;

	while (fast != list) {
		fast = fast->next;
		if (fast != list) {
			slow = slow->next;
			fast = fast->next;
		}
	}

	nodeptr temp1 = list->next;
	nodeptr temp2 = list->prev;

	while (temp1 != slow) {

		char * swap = temp1->data;
		temp1->data = temp2->data;
		temp2->data = swap;

		temp1 = temp1->next;
		temp2 = temp2->prev;
	}

}

void displayList (nodeptr list) {
	nodeptr temp = list->next;
	while (temp->next != list) {
		printf("%s -> ", temp->data);
		temp = temp->next;
	}
	printf("%s", temp->data);
}

int main (int argc, const char * argv []) {

	nodeptr list = createAndInputList();

	printf("\n\t     Initially: ");
	displayList(list);
	reverseList2(list);
	printf("\n\tAfter Reversal: ");
	displayList(list);

	//	nodeptr revList = reverseList(list);
	//	printf("\n\tAfter Reversal (New): ");
	//	displayList(revList);

	printf("\n\n");
	return 0;
}
