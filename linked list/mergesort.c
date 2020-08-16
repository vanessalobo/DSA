#include <stdio.h>
#include <stdlib.h>

#define UNDERFLOW_CHAR '\0'

typedef struct Node* nodeptr;

struct Node {
	char data;
	nodeptr next;
};



nodeptr getnode() {
	nodeptr temp = (nodeptr)malloc(sizeof(struct Node));
	temp->next = temp;
	temp->data = UNDERFLOW_CHAR;
	return temp;
}

void insert (nodeptr list, char item) {
	nodeptr temp = getnode();
	nodeptr p;

	temp->data = item;
	temp->next = list;

	if (list->next == list)
		list->next = temp;

	else {
		p = list->next;

		while (p->next != list)
			p = p->next;
		p->next = temp;

	}
}

void display (nodeptr list) {
	nodeptr temp = list->next;

	if (temp != list)  {
		while (temp->next != list) {
			printf(" %c ->", temp->data);
			temp = temp->next;
		}
		printf(" %c", temp->data);
		temp = temp->next;
	}
}


int main () {

	nodeptr list1 = getnode();
	nodeptr list2 = getnode();
	nodeptr newList = getnode();

	int i, n;
	char item;

	printf("\n\tList 1: Enter no of elements: ");
	scanf("%d", &n);
	printf("\n\tEnter List 1 elements in ascending order: ");
	for (i = 0; i < n; ++i) {
		scanf(" %c", &item);
		insert(list1, item);
	}

	printf("\n\tList 2: Enter no of elements: ");
	scanf("%d", &n);
	printf("\n\tEnter List 2 elements in ascending order: ");
	for (i = 0; i < n; ++i) {
		scanf(" %c", &item);
		insert(list2, item);
	}

	nodeptr temp1 = list1->next;
	nodeptr temp2 = list2->next;

	while (temp1 != list1 && temp2 != list2) {
		char c1 = temp1->data;
		char c2 = temp2->data;
		if (c1 > c2) {
			insert(newList, c2);
			temp2 = temp2->next;
		}
		else {
			insert(newList, c1);
			temp1 = temp1->next;
		}
	}
	while (temp1 != list1) {
		insert(newList, temp1->data);
		temp1 = temp1->next;
	}
	while (temp2 != list2) {
		insert(newList, temp2->data);
		temp2 = temp2->next;
	}

	printf("\n\tList 1: ");
	display(list1);
	printf("\n\tList 2: ");
	display(list2);
	printf("\n\tMerged: ");
	display(newList);

	printf("\n\n");
}

