#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define SIZE 50


typedef struct Node* nodeptr;
struct Node {
	int data;
	nodeptr next;
};



nodeptr createNode () {
	nodeptr temp = (nodeptr)malloc(sizeof(struct Node));
	temp->next = NULL;
	return temp;
}

void insert (nodeptr * list, int data) {

	if (*list == NULL) {
		*list = createNode();
		(*list)->data = data;
		return;
	}

	nodeptr temp = createNode();
	temp->data = data;

	nodeptr p = *list;
	while (p->next != NULL)
		p = p->next;
	p->next = temp;
}

void removeDuplicates (nodeptr list) {
	nodeptr p = list;
	while (p != NULL) {
		nodeptr temp = p;
		while (temp != NULL && temp->data == p->data) {
			p->next = temp->next;
			temp = temp->next;
		}
		p = p->next;
	}
}

void freeMemory (nodeptr list) {
	nodeptr p = list;
	while (p != NULL) {
		nodeptr temp = p;
		p = p->next;
		free(temp);
	}
	list = NULL;
}

void display (nodeptr list) {
	nodeptr temp = list;
	if (temp != NULL)  {
		while (temp->next != NULL) {
			printf(" %d ->", temp->data);
			temp = temp->next;
		}
		printf(" %d", temp->data);
		temp = temp->next;
	}

	printf("\n\n");
}


int main (int argc, const char * argv []) {

	nodeptr list = NULL;

	printf("\n\tEnter sorted list, -999 to break: \n");

	int data;
	do {
		scanf(" %d", &data);
		if (data != -999)
			insert(&list, data);
	} while (data != -999);

	printf("\n\tInitially: ");
	display(list);

	removeDuplicates(list);

	printf("\n\t after: ");
	display(list);

	freeMemory(list);

}
