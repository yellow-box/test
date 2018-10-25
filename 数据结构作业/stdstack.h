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
	
	*(S.top++)=a;
	return 1;
}
int Gettop(Sqstack &S,int &a){
	if(S.base==S.top)return 0;
	a=*(S.top-1);
	return 1;
}
