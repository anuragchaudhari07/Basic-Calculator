#include<stdlib.h>
#include<stdio.h>
#include "list.h"

list readno();
list addition(list a, list b);
list subtraction(list a, list b);

list readno() {
	char ch;
	int no;
	list l;

	init(&l);

	while(ch != '\n') {
		scanf("%c", &ch);
		no = ch - '0';
		if(no != -38)
			insert(&l, no);	
	}

	return l;
}

list addition(list a, list b) {
	node *temp, *tmp;
	int x=0,y=0;
	int len1,len2;
	int remain=0,sum=0,count=0;

	len1 = length(a);
	len2 = length(b);

	int len = len2;

	if(len1 > len2)
		len = len1;

	list add;
	init(&add);

	temp = a.q;
	tmp = b.q;

	do {
		x = 0;
		y = 0;

		if(temp != NULL) {
			x = temp->no;
			temp = temp->prev;
		}

		if(tmp != NULL) {
			y = tmp->no;
			tmp = tmp->prev;
		}

		sum = x + y + remain;
		remain = sum / 10;
		sum = sum % 10;

		insert(&add, sum);
		
		count++;

	}while(count != len);

	insert(&add,remain);	
	
	return add;

}


list subtraction(list a, list b) {
	node *temp, *tmp;
	int x=0,y=0;
	int len1,len2;
	int carry=0,subtract=0,count=0;

	len1 = length(a);
	len2 = length(b);

	int len = len2;

	if(len1 > len2)
		len = len1;

	list sub;
	init(&sub);

	temp = a.q;
	tmp = b.q;

	do {
		x = 0;
		y = 0;

		if(temp != NULL){
			x = temp->no;
			temp = temp->prev;
		}

		if(tmp != NULL) {
			y = tmp->no;
			tmp = tmp->prev;
		}

		if(x < y) {
			subtract = 10 + x - y - carry;
			carry = 1;
		}
		if(x == y && carry == 1) {
			subtract = 10 + x - y - carry;
			carry = 1;
		}

		if(x == y && carry == 0) {
			subtract = x - y;
			carry = 0;
		}
		
		if(x > y) {
			subtract = x - y - carry;
			carry = 0;
		}

		//traverse(sub);
		insert(&sub, subtract);
		//traverse(sub);
		count++;

	}while(count != len);
	
	
	return sub;

}

int main() {
	list a,b,c;
	list d,e,f;
	int ch;
	
	printf("Addition: \n");
	
	printf("Enter no\n");
	a = readno();
	
	printf("Enter no\n");
	b = readno();

	c = addition(a, b);
	
	printf("Addition: ");
	traverse(c);
	printf("\n");
	
	printf("Subtraction: \n");

	printf("Enter no\n");
	d = readno();
	
	printf("Enter no\n");
	e = readno();

	f = subtraction(d, e);
	
	printf("Subtraction: ");
	traverse(f);
	printf("\n");
	
	return 0;
}
