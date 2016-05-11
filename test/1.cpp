#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>
#define m 3
#define MAXLEN 100
typedef char datatype;
/*
typedef struct node {
	datatype data;
	struct node *child[m];
}node;
typedef node *tree;

tree createtree() {
	int i;
	char ch;
	tree t;
	if ((ch = getchar()) == '#')
		t = NULL;
	else {
		t = (tree)malloc(sizeof(node));
		t->data = ch;
		for (i = 0;i < m;++i)
			t->child[i] = createtree();
	}
	return t;
}
*/

/*
//˫�ױ�ʾ��
#define MAXSIZE 100
typedef struct node {
	datatype data;
	int parent;
}node;
typedef struct tree {
	node treelist[MAXSIZE];
	int length, root;
}tree;



typedef struct node {
	datatype data;
	int parent;
}node;

typedef struct tree {
	node treelist[MAXLEN];
	int length, root;
};
*/




//���ӱ�ʾ����ָ�뷽ʽ��
typedef struct node {
	datatype data;
	struct node *child[m];
}node,*tree;
//tree root;

/*
#define m 3
typedef struct node {
	datatype data;
	node *child[m];
}node,*tree;
*/



/*
//���ӱ�ʾ�������鷽ʽ��
#define m 3
typedef struct node {
	datatype data;
	int child[m];
}treenode;
treenode tree[MAXLEN];
int root;
int length;


#define m 3
typedef struct node {
	datatype data;
	int child[m];
}treenode;
treenode tree[MAXLEN];
int root;
int length;
*/


/*
//���ӱ�ʾ��������ʽ��
typedef struct chnode {
	int child;
	struct chnode *next;
}chnode,*chpoint;
typedef struct {
	datatype data;
	chpoint firstchild;
}node;
typedef struct {
	node treelist[MAXLEN];
	int length, root;
}tree;



typedef struct chnode {
	int child;
	struct chnode *next;
}chnode,*chpoint;
typedef struct {
	datatype data;
	chpoint firstchild;
}node;
typedef struct {
	node treelist[MAXLEN];
	int length, root;
}tree;
*/

/*
//�����ֵܱ�ʾ��
typedef struct node {
	datatype data;
	struct node *firstchild, *rightsibling;
}node,*pnode;
pnode root;


typedef struct node {
	datatype data;
	struct node *firstchild, *nextsibling;
}node ,*pnode;
pnode root;
*/

/*

//ǰ�����
void preorder(tree p) {
	if (p != NULL) {
		printf("%c", p->data);
		for (int i = 0;i < m;i++)
			preorder(p->child[i]);
	}
}

//�������
void postorder(tree p) {
	if (p != NULL) {
		for (int i = 0;i < m;i++)
			postorder(p->child[i]);
		printf("%c", p->data);
	}
}

//ǰ�����������
tree createtree() {
	char ch;
	tree t;
	if ((ch == getchar()) == '#')
		t = NULL;
	else {
		t = (tree)malloc(sizeof(node));
		t->data = ch;
		for (int i = 0;i < m;i++)
			t->child[i] = createtree();
	}
	return t;
}

//���Ĳ�α���
void levelorder(tree t) {
	tree queue[100];
	int f = 0, r = 1;  //f������ͷ �� r������β
	tree p;
	queue[0] = t;
	while (f < r) {
		p = queue[f];
		f++;
		printf("%c", p->data);
		for(int i=0;i<m;i++)  //���ձ����ʵ�Ԫ�ص�������Ů������ν���
			if (p->child[i]) {
				queue[r] = p->child[i];
				r++;
			}
	}
}

*/


//���������ű�ʾת�������ĺ��ӱ�ʾ�����鷽ʽ��
#define m 3
#define MAXSIZE 20 //���ӱ�ʾ����Ӧ�������С
#define BMAXSIZE 50  //���ű�ʾ��Ӧ�������С
typedef struct node {
	datatype data;
	int child[m];
}treenode;
treenode tree[MAXSIZE];
int root ,length;
char p[BMAXSIZE];
void bracktotree(char p[], int *root, int *length, treenode tree[]) {
	int stack[MAXSIZE], top = 0;
	int j = 0, k = 0, l, done = 1, i;
	*root = 0;
	tree[j].data = p[k];
	k++;
	for (int i = 0;i < m;i++)
		tree[j].child[i] = -1;
	while (done) {
		if (p[k] == '(') {    //
			stack[top] = j;
			top++;
			k++;
		}
		else if (p[k] == ')') {  //
			top--;
			if (top == 0)
				done = 0;
			else
				k++;
		}
		else if (p[k] == ',') {   //
			k++;
		}
		else {   //
			j++;
			tree[j].data = p[k];
			for (i = 0;i < m;i++)
				tree[j].child[i] = -1;
			l = stack[top - 1];
			i = 0;
			//
			while (tree[l].child[i] != -1)
				i++;
			tree[l].child[i] = j;
			k++;
		}
	}
	*length = j + 1;
}