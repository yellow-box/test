#include"stdio.h"
#include"stdlib.h"
#include"stack"
#define MAXSIZE 50 
typedef struct BiTNode{
	char date;
	struct BiTNode *lchild;
	struct BiTNode *rchild;	
}BiTNode,*BiTree;


void print(BiTree T){
	printf("%c ,",T->date);
}

int CreatBiTree(BiTree &T){
	char ch;
	scanf("%c",&ch);
	if(ch==' ')T=NULL;
	else{
		if(!(T=(BiTNode *)malloc(sizeof(BiTNode))))return 0;
		T->date=ch;
		CreatBiTree(T->lchild);
		CreatBiTree(T->rchild);	
	}
//	 stack <BiT>a  ;
	
	return 1;
} 
int PreTranversBiTree(BiTree T){
	if(T){
	printf("%c ",T->date);
	PreTranversBiTree(T->lchild);
	PreTranversBiTree(T->rchild);
	}

	return 1;
}

int InTranversBiTree(BiTree T){
	if(T){
		InTranversBiTree(T->lchild);
		printf("%c ",T->date);
		InTranversBiTree(T->rchild);
	
	}
 return 1; 
}
int LaterTranversBiTree(BiTree T){
	if(T){
		LaterTranversBiTree(T->lchild);
		LaterTranversBiTree(T->rchild);
		printf("%c ",T->date);
	}
	return 1;
} 
void countleaf(BiTree T,int &num){
	if(T)
	{	if(T->lchild==NULL&&T->rchild==NULL){
		num++;//printf("--%c --",T->date);
	}
		countleaf(T->lchild,num);
		countleaf(T->rchild,num);
	}
	
}//计算爷子节点 
int leaf_num(BiTree T)
{
    if (T == NULL)
        return 0;
    if (T->lchild == NULL && T->rchild == NULL)     return 1;
	
   
    return (leaf_num(T->lchild) + leaf_num(T->rchild));
}//计算叶子结点的尾递归优化 



int CcTranversBiTree(BiTree T){
	BiTree Bqueue[20];int rear,front;rear=front=-1;BiTree B;
	rear=(rear+1)%20;
	Bqueue[rear]=T;
	while(rear!=front){
		front=(front+1)%20;
		B=Bqueue[front];
		printf("%c ",B->date);
		if(B->lchild){
			rear=(rear+1)%20;
			Bqueue[rear]=B->lchild;
		}
		if(B->rchild){
			rear=(rear+1)%20;
			Bqueue[rear]=B->rchild;	
		}
	} 
	return 1;
} //层次遍历 

 
int main(){
	BiTree T;int num =0; 
	CreatBiTree(T);
		printf("先序遍历\n");
	PreTranversBiTree( T);
	printf("\n层次遍历\n");
	CcTranversBiTree( T);
	printf("\n中序遍历\n");
	InTranversBiTree(T);
		printf("\n后序遍历\n");
	LaterTranversBiTree( T); 
	countleaf(T,num);
	num=leaf_num( T);
	printf("\n叶子节点个数=%d",num);
	return 0;
}
