#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#include <math.h>

// StackSize => 定義Stack容量大小
// stack => 堆疊 是一個全域變數，用來裝載資料。 
// top => 用來判斷Stack目前裝載的高度，預設 -1 (Empty) 
#define stackSize 50
char stack[stackSize];
int top = -1;

// --------------------
// Stack Function 
// --------------------

// IsEmpty 判斷是否為空陣列
int IsEmpty(void)
{
	return top == -1;
}

// IsFull 判斷是否為滿的陣列 
int IsFull()
{
	return top == stackSize - 1; 
}

// Push 放入 
void push(char item)
{
	if(IsFull())
	return;
	
	stack[++top] = item; 
}

// Pop 刪除
int pop()
{
	if(IsEmpty())
	return -1;
	
	return stack[top--]; 
}

// getTopData 取得Stack最頂端資料 
char getTopData()
{
	return stack[top];   
}

// --------------------
// Calculate Function
// --------------------

// getPriority 取得運算子的優先序
int getPriority(char c)
{
	switch(c) 
	{
		case ')':
			return 1;
			
		case '^':
			return 2;
			
		case '+':
		case '-':
			return 3;
			
		case '*':
		case '/':
			return 4;
			
		case '(':
			return 5;	
	}
}

// IsDight 判斷十進位
int IsDight(char c)
{
	return '0'<=c && c<='9';
}

// convertPostfix => infix(中序) 轉至 postfix(後序) 
void convertPostfix(char infix[], char postfix[])
{
	int i=0,p=0;
	
	while(infix[i]!='\0')
	{
		char ch = infix[i++];
		
		if(IsDight(ch))
		{
			postfix[p++] = ch;
		}
		else 
		{
			if(IsEmpty() || getPriority(ch)>=getPriority(getTopData()))
			{
				push(ch);
			}
			else
			{
				while(!IsEmpty() && getTopData()!='(')
				{
					postfix[p++] = pop();
				}
				
				ch==')' ? pop():push(ch);
			}
		}	
	}

	while(!IsEmpty()) 
	{
		postfix[p++] = pop();
	}

}



// Calculate Function
int calculate(char postfix[])
{
	int i=0;
	float stack[stackSize];
	int top = -1;
	
	while(postfix[i]!='\0')
	{
		char ch = postfix[i++];
		
		if(IsDight(ch))
		{
			stack[++top] = (float)atof(&ch);
		}
		else
		{
			float a = stack[top--];
			float b = stack[top--];
			float c;
			
			switch(ch)
			{
				case '^':
					c = (int)b ^ (int)a;
					break;
					
				case '+':
					c = b + a;
					break;
					
				case '-':
					c = b - a;
					break;
					
				case '*':
					c = b * a;
					break;
					
				case '/':
					c = b / a;
					break;	
			}
			stack[++top] = c;
		}
	}
	
	return stack[top--];	
}


// Main Function
int main(void){ 

	// 運算式-題目 
	char infix[] = "3+4^2+(8+5*6)/(9-7)";
	char postfix[strlen(infix)];

	// array傳進function是採call by address
	convertPostfix(infix, postfix);
	float result = calculate(postfix);
	
	printf("題目:%s\n", infix);
	printf("infix Size：%ld\n", strlen(infix));
	printf("postfix Size：%ld\n", strlen(postfix));
	printf("後序：%s\n", postfix);
	printf("後序的計算結果：%.2f\n", result);
	
}