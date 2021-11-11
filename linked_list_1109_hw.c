#include <stdlib.h> 
#include <stdio.h>
#include <stdbool.h>

// 定義節點的元素
typedef struct node{
	int exp;
	int coef;
	struct node *next;
}node;

// 宣告指標head去指向第一個節點 
node *head = NULL;

// 把A與B節點的多項式做出來 
node *AddNode(node *List, int i, int j) {
	node *P = List;

	node *N = (node*)malloc(sizeof(node));
	N->coef = i;
	N->exp = j;
	N->next = NULL;

	if(!P)
		return N;

	while(P->next)
	{
		P = P->next;
	}
	P->next = N;

	return List;
}

//多項式相加 
node *AddList(node *List1, node *List2)
{
	node *Pre = (node*)malloc(sizeof(node));
	node *Head = Pre;

	while(List1 && List2)
	{
		node *P = (node*)malloc(sizeof(node));
		if(List1->exp > List2->exp)
		{
			P->coef = List1->coef;
			P->exp = List1->exp;
			List1 = List1->next;
		}
		else if(List1->exp < List2->exp)
		{
			P->coef = List2->coef;
			P->exp = List2->exp;
			List2 = List2->next;
		}
		else
		{
			P->coef = List1->coef + List2->coef;
			P->exp = List1->exp;
			List1 = List1->next;
			List2 = List2->next;
		}

		Pre->next = P;
		Pre = P;	
	}

	while(List1)
	{

		node *P = (node*)malloc(sizeof(node));
		P->coef = List1->coef;
		P->exp = List1->exp;
		List1 = List1->next;

		Pre->next = P;
		Pre = P;
	}

	while(List2)
	{
		node *P = (node*)malloc(sizeof(node));
		P->coef = List2->coef;
		P->exp - List2->exp;
		List2 = List2->next;

		Pre->next = P;
		Pre = P;	
	}

	Pre->next = NULL;

	node *result = Head->next;
	free(Head);

	return result;
}

//把list Print出來 
void PrintList(node *List){
	while(List!=NULL){
		printf("%dX^%d",List->coef,List->exp);
		if(List->next!=NULL) printf("+");
		List=List->next;
	}
} 
//解放記憶體 
void FreeList(node *List){
	node *Head;
	 while (true){
	 	Head = List;
	 	if (Head == NULL) break;
	 	List = List->next;
	 	free(Head);
	 }
}

int main(){
	node *A = AddNode(AddNode(AddNode(NULL, 1, 10), 2, 2),2,1);  //多項式 A
	printf("多項式A=");
	PrintList(A);
	printf("\n");
	node *B = AddNode(AddNode(NULL, 2, 4), 2, 2);  //多項式 B 
	printf("多項式B=");
	PrintList(B);
	printf("\n");
	node *C = AddList(A, B);						//兩多項式相加
	printf("相加為=");
	PrintList(C);
	printf("\n");
	FreeList(C);
	FreeList(B);
	FreeList(A);
	return 0; 
}
