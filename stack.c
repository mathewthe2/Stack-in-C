#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct stackNode{
	int key;
	struct stackNode *next;
}*top = NULL;
typedef struct stackNode stackNode;

stackNode *push(stackNode *currentNode, int key) {
	if (currentNode==NULL) {
		stackNode *temp;
		temp = (stackNode *)malloc(sizeof(stackNode));
		temp -> key = key;
		temp->next = top;
		top = temp;
		return temp;
	}
	currentNode = push(currentNode->next, key);
	return currentNode;
}

stackNode *pop(stackNode *currentNode) {
	if (top==NULL)
		printf("empty stack\n");
	else {
		stackNode *temp = top;
		top = top->next;
		printf("%d\n", temp->key);
		free(temp);
	}
	return currentNode;
}

int main(){
    stackNode *root = NULL;
	char command[50];
	while (scanf("%s",command)!=EOF) {
    if (command[0] == 'p' && command[1] == 'u') {
          int key;
    			scanf(" %d", &key);
    			root = push(root, key);
        } else if (command[0] == 'p' && command[1] == 'o') {
          root = pop(root);
        }
      }
/*
		scanf(" %s", command);
		if (strcmp( command, "push") == 0) {
			int key;
			scanf(" %d", &key);
			root = push(root, key);
		} else if (strcmp( command, "pop") == 0) {
			root = pop(root);
		} else {
			//printf("Wrong command!\n");
			//break;
		}
    */
	}
