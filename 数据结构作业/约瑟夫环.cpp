#include"stdio.h"
#include"stdlib.h"
typedef struct LNode{
	int password ;
	int order;
	struct LNode *next ;
}LNode, *LinkList;




void creatList(LinkList &L,int a){
	LinkList p,s;
	L=(LinkList)malloc(sizeof(LNode));
	L->next=NULL;
	s=L;
	int i=1;
	printf("3172484"); 
	while(i<=a){
		int b;
		p=(LinkList)malloc(sizeof(LNode));
		p->order=i;
		i++;
		s->next=p;
		s=p;
		printf("请为该节点设置密码\n");
		scanf("%d",&b);
		p->password=b;
	}
	printf("-------\n"); 
	s->next=L->next; //头尾相接 

}

void runList(LinkList &L,int m){
	LinkList p,c;
	p=L;

	printf("出列顺序为：\n") ; 
	while(p->next!=p){
	
		for(int i=1;i<m;i++){ 
			p=p->next; 
		//	printf("--第%d号,i=%d--",p->order,i);
		}
		printf("%d,",p->next->order); 
		c=p->next;
		m=c->password;
		p->next=p->next->next;
		free(c);
		}
		printf("%d,",p->order); 
}

void print(LinkList L){
	LinkList p=L->next;

	for(int i=1;i<=7;i++){
		printf("第%d号的密码是%d,",p->order,p->password);
		p=p->next;
	}
	printf("\n");
}



int main(){
	LinkList L;
	creatList(L,7);
	print(L);
	runList(L,20);
	
	
	return 0;
}



