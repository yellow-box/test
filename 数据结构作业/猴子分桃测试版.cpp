#include"stdio.h"
#include "stdlib.h"

typedef struct Monkey{
	int order;
	int num;
}Monkey;

typedef struct Sqstack
{
	Monkey  * Mon;
	struct Sqstack *next; 
}Sqstack;

typedef struct SqQueue
{
	struct Sqstack* front; 
	struct Sqstack* rear; 
}SqQueue;


int initSqQueue(SqQueue &Q){
	Q.rear=(Sqstack*)malloc(sizeof(Sqstack));
	if(!Q.rear) return 0;
	Q.rear->Mon=NULL; 
	Q.front=Q.rear;
	Q.rear->next=NULL;
	return 1;
}

int EnSqQueue(SqQueue &Q,Monkey *Nmonkey){
	Sqstack *p=Q.rear;
	Q.rear->Mon=Nmonkey;
	Q.rear=(Sqstack*)malloc(sizeof(Sqstack));//冲i前面改到这里了 
	if(!Q.rear) return 0;
	p->next=Q.rear;
	Q.rear->next=NULL;
	return 1;
}

int DeSqQueue(SqQueue &Q,Monkey &theMonkey){
	if(Q.rear==Q.front) return 0;
	Sqstack *q=Q.front;
	theMonkey.order=Q.front->Mon->order;	
	theMonkey.num=Q.front->Mon->num;
	Q.front=Q.front->next;
	free(q);			//原因好像出在第一个front指针里的mon并没没有储存数据，而且我还特意让为空时的front指针的mon中不储存数据 						
	q=NULL;			//关于上一个注释 我已经改成front指针储存数据 ，rear指针不储存数据 
	//printf("DeSqueue里的出队列的CurMonkey->order=%d\n",CurMonkey->order);
	return 1;
}  

int look(SqQueue Q){
	return Q.front->Mon->order;
}
int isblank(SqQueue Q){
	if(Q.rear==Q.front) return 1;
	else return 0;
}
// n=5 k=3 m=40
void fentao(){
	SqQueue Q; int n=5;int k=3;int m=40;	
	initSqQueue(Q);
	 for(int j=1;j<=n;j++){
	 	 Monkey *theMonkey=(Monkey*)malloc(sizeof(Monkey));
	 	 theMonkey->order=j;
	 	 theMonkey->num=0;// 调试好后 把num赋值改回0； 
	 /*	Monkey Nmonkey; Monkey *theMonkey;
	 	Nmonkey.num=0;
	 	Nmonkey.order=j;
	 	theMonkey=&Nmonkey;*/ 
	 	EnSqQueue(Q,theMonkey);
	 	printf("theMonkey->order=%d\n",look(Q));
	 } //这里创建5值猴子并让5只猴子入队列是否有问题？ 可以写一个printf函数打印出来看一下   后记 这里应该没问题了 
/*	 Monkey  CurMonkey;
	 DeSqQueue(Q, CurMonkey);
 printf("1为相等 0为不等 =%d\n",CurMonkey==Q.front->Mon);//输出为0；说明他们不等！ 传递指针失败了 为什么？ 
	 printf("出队列的 CurMonkey->order=%d\n", CurMonkey.order);//出队列有问题    打印Monkey的num没问题 但打印oeder就有问题了  我将for赋值出的num改成1了 但打印num是还是0； 
	printf(" CurMonkey->order=%d\n",look(Q));//出队列没问题 但上一个注释处指针的值传递有点问题 */
	Monkey theMonkey1;int left=0;
	while(!isblank(Q)){
		for(int i=1+left;i<=k;i++){
			DeSqQueue(Q,theMonkey1);
			theMonkey1.num+=i;
			left=(theMonkey1.num)-m;
			if(left>=0){
				i+=left;
				printf("第%d号猴子得到40个桃子，出了队列。\n",theMonkey1.order);
			}	
			else {
			EnSqQueue(Q,&theMonkey1);
			left=0;   //这里加一句left=0；是否解决了上一个注释处的问题？ 
			} 
		}
	}


}
int main (){
	fentao();
	return 0;
} 
