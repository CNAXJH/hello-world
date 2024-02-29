#include<stdio.h>
#include<stdlib.h>
#include<time.h>


typedef struct Node {
	int data;
	struct Node* next;
}Node;


Node* GetNewNode(int val) {
	Node* p = (Node*)malloc(sizeof(Node));
	p->data = val;
	p->next = NULL;
	return p;
}

Node* Insert(Node*head,int pos,int val) {
	if (pos == 0) {
		Node* p = GetNewNode(val);
		p->next = head;
		return p;
	}
	
	Node *p = head,*q;
	for (int i =1; i < pos; i++) 
		p = p->next;
	q = GetNewNode(val);
	q->next = p->next;
	p->next = q;
	return head;

}

void Print(Node *head) {
	Node* q=head;
	for (Node* p = head; p->next;p=p->next) {
		printf("%d->",p->data );
		q = p->next;
	}
	printf("%d\n",q->data);
	return;
}
void clear(Node* head) {
	if (head == NULL)return;
	for (Node* p=head, *q; p;p=q) {
		q=p->next;
		free(p);

	}
	return;
}



int main() {
	srand(time(0));
	#define MAX_OP  20
	Node* head = NULL;
	for (int i = 0; i < MAX_OP; i++) {
		int pos = rand() % (i + 1);
		int	val = rand() % 100;
		printf("insert %d at %d to linklist\n",val,pos);
		head = Insert(head, pos, val);
		Print(head);
	}

	return 0;
}