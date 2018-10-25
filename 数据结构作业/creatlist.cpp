#include"stdio.h"
#include"stdlib.h"

//可能初始化的第一句时头指针未置空 
typedef struct LNode{
	char Letter;
	struct	LNode  *next;
}LNode, *LinkList;

void CreatList(LinkList &L){
	LinkList s;
	L=(LinkList)malloc(sizeof(LNode));
	L->next=NULL;
	LinkList p=L;
	for(int a=97;a<=122;a++){
	s=(LinkList)malloc(sizeof(LNode));
	s->Letter=(char)a;
	s->next=p->next;
	p->next=s;
	p=s;
	
	printf("%c ,",s->Letter);
	}
	printf("\n");
}

int FindLetter(LinkList L,char e){
	LinkList s;
	int i=1;
	s=L->next ;
	while(s){
		if(s->Letter==e){
			
			return i;
		}
	++i;
	s=s->next;
	}
	return 0;
}

int InsertList( LinkList &L,char e){
	LinkList p=L->next;LinkList s;
	while(p){
		if((e-(p->Letter))<2){
			s=(LinkList)malloc(sizeof(LNode));
			s->Letter=e;
			s->next=p->next;
			p->next=s;
			return 1;
		}
		p=p->next;	
	}
	if(!p) return 0;
}

int DeleteList(LinkList &L,int i,char &e){
	LinkList p=L;int j=0;LinkList s;
	while(p->next&&j<i-1){
		p=p->next;++j;
	}
	if(!(p->next)||j>i-1)
	return 0;
	s=p->next;
	e=s->Letter;
	p->next=s->next;
	free(s);
	return 1;
}
 

void print(LinkList L){
	LinkList s=L->next;
	while(s){
		printf("%c ,",s->Letter);
		s=s->next;
	}
	printf("\n");
}

int main(){

	int ss=1;
	char aa;
	LinkList L; 
	CreatList(L);
//	int A=FindLetter(L,'e');
//	printf("%d\n",A)	; 
//	InsertList(L,'g');
	DeleteList(L,7,aa);
	print(L); 
	printf("%c",aa);
	return 0;}

