#include <iostream>

using namespace std;

//���Ḯ��Ʈ ����ü ����
typedef struct linkNode
{
	int data;
	struct linkNode* link;

} listNode;


/*��� ���� ����*/
typedef struct node {
	int data;
	struct node* before;
	struct node* after;
} doubleNode;



void main() {
    //���Ḯ��Ʈ ���ۺκ� ����
	listNode* first;
	first = NULL;

	doubleNode* dlist;
	dlist = NULL;

}

//���Ḯ��Ʈ �߰����� �Լ�
void insertLinkList(listNode** first, listNode* current, int x) {
	listNode* temp;
	temp = (listNode*)malloc(sizeof(listNode));
	temp->data = x;
	if (current == NULL) {
		temp->link = *first;
		*first = temp;
	}
	else {
		temp->link = current->link;
		current->link = temp;
	}
	free(temp);
}

//current ���� ��� ����
int deleteLinkList(listNode** first, listNode* current) {
	listNode* temp;
	int imsi;
	temp = (listNode*)malloc(sizeof(listNode));
	if (current == NULL) {
		temp = *first;
		*first = temp->link;
	}
	else if (current->link == NULL) {
		return(0);// ���� ����
	}
	else {
		temp = current->link;
		current->link = temp->link;
	}
	imsi = temp->data;
	free(temp);
	return (imsi);
}

//���Ḯ��Ʈ�� Ž��
listNode* searchLinkedlist(listNode* first, int key) {
	listNode* current;
	current = first;
	while (current != NULL) {
		if (current->data == key)return(current);
		current = current->link;
	}

	return(NULL);
}

//���Ḯ��Ʈ�� ��ü���
void printLinkedlist(linkNode* first) {
	listNode* current;
	current = first;
	while (current != NULL) {
		printf("%d", current->data);
		current = current->link;
	}
	return;
}

//���Ḯ��Ʈ�� ��������
void reverseLinklist(listNode** first) {
	listNode* last, * current, * temp;
	last = NULL;
	current = *first;
	while (current != NULL) {
		temp = current;
		current = current->link;
		temp->link = last;
		last = temp;
	}
	*first = last;
	return;
}

//���߿��Ḯ��Ʈ �߰�
void adddoublelistNode(node* dlist) {
	doubleNode* temp, *current, *next;

	//�Ǿտ� �߰���
	if (current == NULL) {
		temp->after = dlist;
		dlist->before = temp;
		temp->before = NULL;
		dlist = temp;
	}
	//�׿�
	else {
		next = current->after;
		temp->after = next;
		next->before = temp;
		current->after = temp;
		temp->before = current;
	}
	return;
}

//���߿��Ḯ��Ʈ�� ����
void deletDoubleListNode(node* dlist) {
	doubleNode* pre, * next, * current;
	current = (node*)malloc(sizeof(node));

	//�Ǿտ� ����
	if (current == dlist) {
		dlist->before = current->before;
		dlist = current;
	   
	}

	//�׿�
	else {
		next = current->after;
		pre = current->before;
		next->before = pre;
		pre->after = next;
	}
	free(current);

}

void transposetMatrix() { //�������� ��ġ��� ���ϱ�
	int a[5][3], t[5][3], row, column, count, k, i, j;//a[][]�� ������, t[][]�� ���� ��ġ ��� count�� ���Ұ���

	row = a[0][0];
	column = a[0][1];
	count = a[0][2];

	t[0][0] = a[0][1]; //�� �� ũ�� ����
	t[0][1] = a[0][0];
	t[0][2] = a[0][2];

	k = 1;
	for(i=0;i<column;i++)
		for (j = 1; j < count; j++)
			if (a[j][1] == i) {
				t[k][0] = a[j][1]; t[k][1] = a[j][0]; t[k][2] = a[j][2]; //��,�� ��ġ ����
				k++;
			}
}

void polynominal() {

	int f[9], g[7], a[9], degree, ai, fi, gi;

	/* f[9]>g[7]�� ���*/

	degree = f[0]; a[0] = degree; ai = fi = gi = 1;
	for (degree = f[0]; degree >= 0; degree--) {
		if (degree > g[0]) { // g[]���� ū �����϶�
			a[ai] = f[fi]; ai++; fi++;
		}
		else { // f[]�� g[]�� ���� ���� �϶�
			a[ai] = f[fi] + g[gi]; ai++; fi++; gi++;
		}
	}
}