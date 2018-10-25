#include"stdio.h"
#include"stdlib.h"
#define STACK_INT_SIZE 100
#define STACKINCREA  2
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
		if(!S.base) return 0;
		S.top=S.base+S.stacksize;
		S.stacksize=S.stacksize+STACKINCREA;
	}
	
	*S.top++=a;
	return 1;
}
void convers(){
	Sqstack S;
	int n=0;int m=0;int c=0; 
	initstack(S);
	printf("请输入一个数\n") ;
	scanf("%d",&n);
	printf("请输入要转化成的进制\n") ;
	scanf("%d",&c);
	while(n){
		Push(S,n%c);
		n=n/c;
	}
	printf("结果为：\n") ;
	while(S.top!=S.base){
		Pop(S,m);
		printf("%d",m);
	}
}

int main(){
	convers();
	
	return 0;
}
