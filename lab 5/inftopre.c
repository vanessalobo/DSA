# include <stdio.h>
# include <string.h>
#include<process.h>
# define MAX 20
void infixtoprefix(char inf[20],char pre[20]);
void reverse(char arr[30]);
char pop();
void push(char symbol);
int isOperator(char symbol);
int prcd(char symbol);
int top=-1;
char stack[MAX];
int main() {
	char inf[20],pre[20],temp;
	printf("Enter infix expression: ");
	scanf("%s", &inf);
	infixtoprefix(inf,pre);
	reverse(pre);
	printf("Prefix expression: %s",pre);
	isdigit()
}

void infixtoprefix(char inf[20],char pre[20]) {
	int i,j=0;
	char symbol;
	stack[++top]='#';
	reverse(inf);
	for (i=0;i<strlen(inf);i++) {
		symbol=inf[i];
		if (isOperator(symbol)==0) {
			pre[j]=symbol;
			j++;
		} else {
			if (symbol==')') {
				push(symbol);
			} else if(symbol == '(') {
				while (stack[top]!=')') {
					pre[j]=pop();
					j++;
				}
				pop();
			} else {
				if (prcd(stack[top])<=prcd(symbol)) {
					push(symbol);
				} else {
					while(prcd(stack[top])>=prcd(symbol)) {
						pre[j]=pop();
						j++;
					}
					push(symbol);
				}

			}
		}

	}

	while (stack[top]!='#') {
		pre[j]=pop();
		j++;
	}
	pre[j]='\0';
}

void reverse(char arr[30])
{


	int i,j;
	char temp[100];
	for(i=strlen(arr)-1,j=0;i+1!=0;--i,++j) {
		temp[j]=arr[i];
	}
	temp[j]='\0';
	strcpy(arr,temp);


}

char pop() {
	char a;
	a=stack[top];
	top--;
	return a;
}

void push(char symbol) {
	top++;
	stack[top]=symbol;
}

int prcd(char symbol) {
	switch(symbol) {
		case '+':
		        case '-':
		        return 2;
		break;
		case '*':
		        case '/':
		        return 4;
		break;
		case '$':
		        case '^':
		        return 6;
		break;
		case '#':
		        case '(':
		        case ')':
		        return 1;
		break;
	}
}

int isOperator(char symbol) {

	switch(symbol) {
		case '+':
		        case '-':
		        case '*':
		        case '/':
		        case '^':
		        case '$':
		        case '&':
		        case '(':
		        case ')':
		        return 1;
		break;
		default:
		        return 0;

	}
}
