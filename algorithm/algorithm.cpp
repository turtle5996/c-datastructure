#include <iostream>

using namespace std;

//연결리스트 구조체 생성
typedef struct linkNode
{
	int data;
	struct linkNode* link;

} listNode;


/*노드 구조 정의*/
typedef struct node {
	int data;
	struct node* before;
	struct node* after;
} doubleNode;



void main() {
    //연결리스트 시작부분 생성
	listNode* first;
	first = NULL;

	doubleNode* dlist;
	dlist = NULL;

}

//연결리스트 추가연산 함수
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

//current 직후 노드 삭제
int deleteLinkList(listNode** first, listNode* current) {
	listNode* temp;
	int imsi;
	temp = (listNode*)malloc(sizeof(listNode));
	if (current == NULL) {
		temp = *first;
		*first = temp->link;
	}
	else if (current->link == NULL) {
		return(0);// 삭제 실패
	}
	else {
		temp = current->link;
		current->link = temp->link;
	}
	imsi = temp->data;
	free(temp);
	return (imsi);
}

//연결리스트의 탐색
listNode* searchLinkedlist(listNode* first, int key) {
	listNode* current;
	current = first;
	while (current != NULL) {
		if (current->data == key)return(current);
		current = current->link;
	}

	return(NULL);
}

//연결리스트의 전체출력
void printLinkedlist(linkNode* first) {
	listNode* current;
	current = first;
	while (current != NULL) {
		printf("%d", current->data);
		current = current->link;
	}
	return;
}

//연결리스트의 역순구성
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

//이중연결리스트 추가
void adddoublelistNode(node* dlist) {
	doubleNode* temp, *current, *next;

	//맨앞에 추가시
	if (current == NULL) {
		temp->after = dlist;
		dlist->before = temp;
		temp->before = NULL;
		dlist = temp;
	}
	//그외
	else {
		next = current->after;
		temp->after = next;
		next->before = temp;
		current->after = temp;
		temp->before = current;
	}
	return;
}

//이중연결리스트의 삭제
void deletDoubleListNode(node* dlist) {
	doubleNode* pre, * next, * current;
	current = (node*)malloc(sizeof(node));

	//맨앞에 삭제
	if (current == dlist) {
		dlist->before = current->before;
		dlist = current;
	   
	}

	//그외
	else {
		next = current->after;
		pre = current->before;
		next->before = pre;
		pre->after = next;
	}
	free(current);

}

