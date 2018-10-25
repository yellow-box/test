 #include"stdio.h"
#include "stdlib.h"
typedef struct Monkey
{
	int order;
	int num;
	struct  Monkey *next; 
} Monkey;

typedef struct SqQueue
{
	struct  Monkey* front; 
	struct  Monkey* rear; 
}SqQueue;


int initSqQueue(SqQueue &Q){
	Q.rear=( Monkey*)malloc(sizeof( Monkey));
	if(!Q.rear) return 0; 
	Q.front=Q.rear;
	Q.rear->next=NULL;
	return 1;
}

int EnSqQueue(SqQueue &Q,int nnum,int norder){
	 Monkey* p=Q.rear;
	Q.rear->order=norder;
	Q.rear->num=nnum;
	Q.rear=( Monkey*)malloc(sizeof (Monkey));
	if(!Q.rear) return 0;
	p->next=Q.rear;
	Q.rear->next=NULL;
	return 1;
}

int DeSqQueue(SqQueue &Q,int &nnum,int &norder){
	if(Q.rear==Q.front) return 0;
	 Monkey* q=Q.front;
	norder=Q.front->order;	
	nnum=Q.front->num;
	Q.front=Q.front->next;
	free(q);								
	q=NULL;			
	return 1;
}  

int look(SqQueue Q){
	return Q.front->order;
}
int isblank(SqQueue Q){
	if(Q.rear==Q.front) return 1;
	else return 0;
}
// n=5 k=3 m=40
void fentao(){
	SqQueue Q; int n=5;int k=3;int m=40;int nnum=0;int norder;	
	printf("请输入猴子个数\n"); 
	scanf("%d",&n);
	printf("请输入每个筐的桃子数上限\n"); 
	scanf("%d",&k);
	printf("请输入每个猴子桃子个数上限\n"); 
	scanf("%d",&m);
	initSqQueue(Q);
	 for(int j=1;j<=n;j++){	 
	 	 norder=j;
	 	 nnum=0;
	 	EnSqQueue(Q,nnum,norder);
	 } 
	int left=0;
	while(!isblank(Q)){
		for(int i=1+left;i<=k;i++){
			DeSqQueue(Q,nnum,norder);
			nnum+=i;
			left=nnum-m;
			if(left>=0){
				i+=left;
				printf("第%d号猴子得到40个桃子，出了队列。\n",norder);
			}	
			else {
			EnSqQueue(Q,nnum,norder);
			left=0;   
			} 
		}
	}

}
int main (){
	fentao();
	return 0;
} 
