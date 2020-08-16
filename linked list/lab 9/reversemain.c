#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 50

#define initString(size) (char *)malloc(size * sizeof(char));

typedef char * String;

typedef struct Node* nodeptr;
struct Node {
	String data;
	struct Node *prev;
	struct Node *next;
};

nodeptr initNode (String data) {
	nodeptr node = (nodeptr)malloc(sizeof(struct Node));
	node->data = initString(SIZE);
	strcpy(node->data, data);
	node->prev = node;
	node->next = node;
	return node;
}



void insertFront (nodeptr list, String data) {

	nodeptr temp = initNode(data);
	nodeptr first = list->next;

	list->next = temp;
	temp->next = first;
	first->prev = temp;
	temp->prev = list;


}

void insertRear (nodeptr list, String data) {

	nodeptr temp = initNode(data);
	nodeptr last = list->prev;

	last->next = temp;
	temp->prev = last;
	temp->next = list;
	list->prev = temp;


}


void displayList (nodeptr list, String id) {

	if (list->next == list) {
		printf("\n\tEmpty List!");
		return;
	}

	printf("\n\tList %s: ", id);
	printf(" <-{");

	nodeptr temp = list->next;

	while (temp->next != list) {
		printf(" %s <->", temp->data);
		temp = temp->next;
	}

	printf(" %s }->\n", temp->data);
}

void reverseList (nodeptr *list) {

	nodeptr head = *list;

	nodeptr first = head->next;
	nodeptr last = head->prev;

	first->prev = NULL;
	last->next = NULL;

	nodeptr curr = first;

	while (curr != NULL) {
		nodeptr temp = curr->prev;
		curr->prev = curr->next;
		curr->next = temp;
		curr = curr->prev;
	}

	head->next = last;
	head->prev = first;

	first->next = head;
	last->prev = head;
}



int main (int argc, const char * argv []) {

	nodeptr list = initNode("<HEAD>");

	insertRear(list, "def");
	insertRear(list, "abc");
	insertRear(list, "xyz");

	displayList(list, "TWD");

	int choice;

	do {

		printf("\n\t 1. Insert Rear.");
		printf("\n\t 2. Insert Front.");



		printf("\n\t 3. Reverse List.");

		printf("\n\t 0. Display");
		printf("\n\tChoice: ");
		scanf(" %d", &choice);

		if (choice == 1 || choice == 2) {
			String str = initString(SIZE);
			printf("\n\tEnter item to be inserted: ");
			scanf(" %s", str);
			if (choice == 1)
				insertRear(list, str);
			else if (choice == 2)
				insertFront(list, str);
		}






    if (choice == 3) {
			reverseList(&list);
			printf("\n\tReversed successfully.");
		}

		displayList(list, "TWD");

	} while (choice >= 1 && choice <= 3);

}
