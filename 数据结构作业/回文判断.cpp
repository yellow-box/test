#include"stdio.h"
#include "stdlib.h"
#define STACK_INT_SIZE 100
#define STACKINCREA  2
#define MAXSIZE 50
typedef struct Stack{
	 int * base;
	 int * top;
	 int stacksize;
}Sqstack;
int initstack(Sqstack &S){
	S.base==(int*)malloc(STACK_INT_SIZE*sizeof(int));
	if(!S.base)return 0;
	S.top=S.base;
	S.stacksize=STACK_INT_SIZE;
	return 1;
}
int Pop(Sqstack &S,int &a){
	if(S.top==S.base)return 0;
	a=*--S.top;
	return 1;
}
int Push(Sqstack &S,int a){
	if(S.top-S.base>=S.stacksize){
		S.base=(int*)realloc(S.base,(S.stacksize+STACKINCREA)*sizeof(int));
		S.top=S.base+S.stacksize;
		S.stacksize=S.stacksize+STACKINCREA;
	}
	if(!S.base) return 0;
	*(S.top++)=a;
	return 1;
}
typedef struct SqQueue
{	char * base;
	int front;
	int rear;
}SqQueue;

int initSqQueue(SqQueue &Q){
	Q.base=(char*)malloc(MAXSIZE*sizeof(char));
	if(!Q.base) return 0;
	Q.front=Q.rear=0;
}

int EnSqQueue(SqQueue &Q,char e){
	if((Q.rear+1)%MAXSIZE==Q.front) return 0;
	Q.base[Q.rear]=e;
	Q.rear=(Q.rear+1)%MAXSIZE;
	return 1;
}

int DeSqQueue(SqQueue &Q,char &e){
	if(Q.rear==Q.front) return 0;
	e=Q.base[Q.front];
	Q.front=(Q.front+1)%MAXSIZE;
	return 1;
} 
 int huiwen(){
 	Sqstack S; SqQueue Q;
 	initstack(S); initSqQueue(Q);	
 	 char b='\0';
 	printf("请输入字符串并以@结束\n");
 	int  a=getchar();
 	Push(S,'#');
 	while(a!='@'){
 		Push(S,a);
 		EnSqQueue(Q,a);
 		a=getchar();
	 }
		EnSqQueue(Q,'#');
	while(a!='#'&&b!='#'){
		Pop(S,a);
		DeSqQueue(Q,b);
		if(a!=b){
			printf("不是回文"); 
			return 0;
		}
	}
	printf("是回文");
	return 1;
 	
 }
int main()
{	int a; int b=027;int c=5;
	printf("%d#%x#",027,27);
//	huiwen();
	return 0;
}
