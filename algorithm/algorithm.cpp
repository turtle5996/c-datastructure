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

//희소행렬의 전치행렬 구하기
void transposetMatrix() { 
	int a[5][3], t[5][3], row, column, count, k, i, j;//a[][]는 희소행렬, t[][]는 만들 전치 행렬 count는 원소개수

	row = a[0][0];
	column = a[0][1];
	count = a[0][2];

	t[0][0] = a[0][1]; //행 열 크기 변경
	t[0][1] = a[0][0];
	t[0][2] = a[0][2];

	k = 1;
	for(i=0;i<column;i++)
		for (j = 1; j < count; j++)
			if (a[j][1] == i) {
				t[k][0] = a[j][1]; t[k][1] = a[j][0]; t[k][2] = a[j][2]; //행,열 위치 변경
				k++;
			}
}

//계수 순차표현 다항식이 덧셈
void polynominal() {

	int f[9], g[7], a[9], degree, ai, fi, gi;

	/* f[9]>g[7]인 경우*/

	degree = f[0]; a[0] = degree; ai = fi = gi = 1;
	for (degree = f[0]; degree >= 0; degree--) {
		if (degree > g[0]) { // g[]보다 큰 차수일때
			a[ai] = f[fi]; ai++; fi++;
		}
		else { // f[]와 g[]가 같은 차수 일때
			a[ai] = f[fi] + g[gi]; ai++; fi++; gi++;
		}
	}
}


//여기부터 스택
#define N 100 // 스택의 최대크기

/* 정수형 스택을 위한 변수정의*/
void stack() { 
	int s[N];
	int top;
	/*공집합인 스택 s 생성*/
	top = -1;

	
}

//스택의 추가함수
int insertStack(int s[], int n, int* top, int x) {
	if (*top < n - 1) { // 스택이 포화상태가 아니면
		*top = *top + 1; // 추가원소를 위한 배열 메모리를 확보함
		s[*top] = x;  //확보된 배열 메모리에 추가원소를 저장
		return(1); //추가성공
	}
	return(0); // 추가실패
}

//스택의 삭제함수
int deleteStack(int s[], int n, int *top){
	int temp;
	if (*top != -1) { //스택이 공집합이 아님
		temp = s[*top]; //현재 탑원소를 임시변수에 저장함
		*top = *top - 1; //현재 top원소를 삭제
		return(temp); // 삭제 원소 반환
	}
	return(0); //삭제 실패
}

//스택의 순차리스트 추가
int insertLinkedstack(struct linkNode** top, int x) {
	struct linkNode* temp;
	temp = (struct linkNode*)malloc(sizeof(struct  linkNode));
	if (temp == NULL) return (0); //노드생성 안됬을시
	temp->data = x; //노드데이터 x 추가
	temp->link = *top;//노드 연결
	*top = temp; // 이제는 temp가 top임
	return(1);
}

//스택의 순차리스트 삭제
int deleteLinkedstack(struct linkNode** top, int x) {
	struct linkNode* temp;
	int imsi;
	temp = (struct linkNode*)malloc(sizeof(struct linkNode));
	if (*top == NULL) return(-1); //top이 비어있을시 반환
	temp = *top; //temp에 top 정보 입력
	*top = (*top)->link; //top은 top 다음노드로 변경
	imsi = temp->data; 
	free(temp);
	return(imsi);
}