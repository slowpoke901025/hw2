#include<stdio.h>

#define QueueSize 6
char Queue[QueueSize];
int front = 0, rear = 0;
int flag = 0;

// --------------------
// Queue Function 
// --------------------

// IsEmpty 判斷是否為空陣列 
int isEmpty(){
	return front == rear && !flag;
}

// IsFull 判斷是否為滿的陣列 
int isFull(){
	return (rear) == front && flag;
}

// Enqueue 放入 
void Enqueue(char arr[],char item){
	if(isFull())
	return;
	
	arr[rear] = item;
	rear = (rear+1)%QueueSize;
	
	if(front == rear)
	flag = 1;
}

// Dequeue 刪除 
void Dequeue(char arr[]){
	if(isEmpty())
	return;
	
	arr[front] = ' ';
	front = (front+1)%QueueSize;
}

// showQueue 取出元素 
void showQueue(char arr[]){
	int i;
	if (isEmpty() && flag == 0){
		printf("Circular Queue is empty!\n");
		return;
	}
	printf("Queue Statues： ");
	for (i = 0; i < QueueSize; i++){
		printf("%d：%c  ", i, Queue[i]);
	}
	printf("\n");
}

// --------------------
// Queue Function End
// --------------------
// --------------------
// Main Function
// --------------------
int main(void){
	Dequeue(Queue);
	Enqueue(Queue,'D');
	Enqueue(Queue,'W');
	Enqueue(Queue,'G');
	Enqueue(Queue,'W');
	Enqueue(Queue,'I');
	Enqueue(Queue,'N');
	showQueue(Queue);
	Enqueue(Queue,'F');
	Dequeue(Queue);
	Dequeue(Queue);
	Dequeue(Queue);
	Enqueue(Queue,'E');
	Enqueue(Queue,'D');
	Enqueue(Queue,'G');
	showQueue(Queue);
}
// --------------------
// Main Function End
// --------------------
