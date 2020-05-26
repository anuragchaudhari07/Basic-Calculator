#include<stdlib.h>
#include<stdio.h>
#include "list.h"

void init(list *l) {
	l->p = NULL;
	l->q = NULL;
}

void insert(list *l, int val) {
	node *temp, *x;

	x = (node *) malloc(sizeof(node));
	x->no = val;

	temp = l->q;

	if(temp == NULL) {
		l->p = x;
		l->q = x;
		x->prev = NULL;
		x->next = NULL;
		return;
	}
	
	temp->next = x;
	x->prev = temp;
	x->next = NULL;
	l->q = x;
	
}

void traverse(list l) {
	node *temp;
	
	temp = l.q;

	if(temp == NULL)
		return;
	
	do {
		printf("%d", temp->no);
		temp = temp->prev;
	}while(temp!=NULL);
}

int length(list l) {
	node *temp;
	int len = 0;	

	temp = l.p;

	if(temp == NULL)
		return 0;
	
	do {
		temp = temp->next;
		len++;
	}while(temp!=NULL);

	return len;
}


