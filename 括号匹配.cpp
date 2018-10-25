#include"stdio.h"
#include"stdlib.h"
//#include"C:\Users\u\Desktop\数据结构C语言\stdstack.h"
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
		S.top=S.base+S.stacksize;
		S.stacksize=S.stacksize+STACKINCREA;
	}
	if(!S.base) return 0;
	*(S.top++)=a;
	return 1;
}
int Gettop(Sqstack &S,int &a){
	if(S.base==S.top)return 0;
	a=*(S.top-1);
	return 1;
}
int comp(){
	Sqstack S; char c; int d,e,f,h;
	initstack(S);
	printf("请输入表达式，以#结束\n");
	while((c=getchar())!='#'){
		if(c=='('||c=='['){
			Push(S,c);
		}
		if(c==')'||c==']'){
			h=Gettop(S,f);
			if(h&&f=='('&&c==')') Pop(S,d);
			else if(h&&f=='['&&c==']') Pop(S,d);
			else {
				printf("匹配失败");
				return 0; 
			}
		}
	}
	if(S.top==S.base){
		printf("匹配成功");
		return 1;
	}
	else {
	printf("匹配失败1");
	return 0;
	}
	
}
int main(){	
	comp();
	return 0;
}
