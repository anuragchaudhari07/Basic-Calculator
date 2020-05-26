typedef struct node {
	int no;
	struct node *prev, *next;
}node;

typedef struct list {
	node *p,*q;
}list;



void init(list *l);
void traverse(list l);
void insert(list *l, int val);
int length(list l);

