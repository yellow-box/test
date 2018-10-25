#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 50
typedef struct{
	int i,j,e;
}Triple;

typedef struct{
	Triple date[MAXSIZE];
	int mu,nu,tu;
}TSMatrix;
//mu 行数 nu列数 tu非零元个数 

int find(TSMatrix &TS,int ci,int cj,int &ce){
	
}
int initTSMatrix(TSMatrix &TS){
	int a=0;int b,c,d;
	TS.tu=3; //非零元个数 
	TS.mu=3;//行数 
	TS.nu=3;//列数 
	while(a<TS.tu){
	printf("请输入第%d个非零元的行号，列号，数值\n",a+1);
	scanf("%d%d%d",&b,&c,&d);
	TS.date[a].i=b;TS.date[a].j=c;TS.date[a].e=d;
	a++;
	}
	return 1;
}
int plusTSMatris(TSMatrix T1,TSMatrix T2,TSMatrix &T3){
	int ci=0; int cj=0; int ce=0;  
	int k=0;int si=0;int newi=0; int flag=0;//k，T1的下表，  newi，T3的下表， 	Si，T2的下表 
	T3.mu=T1.mu;T3.nu=T1.nu;
	for(k=0;k<T1.tu;k++){
	/*	printf("k=%d \n",k);
		printf("si=%d \n",si);*/
		ci=T1.date[k].i; 
		cj=T1.date[k].j;
		ce=T1.date[k].e;
		while(T2.date[si].i<=ci&&si<T2.tu){
			if(flag==1){
				flag=0;
				break;
			}
			while(T2.date[si].i<ci&&si<T2.tu){
				T3.date[newi].e=T2.date[si].e;
				T3.date[newi].i=T2.date[si].i;
				T3.date[newi].j=T2.date[si].j;
				/*printf("k=%d \n",k);
				printf("si=%d \n",si);	
				printf("si< \n");*/
				newi++;
				si++;
			}	//si.i<i
			while(T2.date[si].i==ci&&si<T2.tu){
				if(T2.date[si].j==cj){
					T3.date[newi].e=ce+T2.date[si].e;
					T3.date[newi].i=ci;
					T3.date[newi].j=cj;
					newi++;
					flag=1;si++;
				//	printf("=\n");
					/*	printf("T3i=%d ,t3e=%d ",T3.date[newi-1].i,T3.date[newi-1].e);*/
					break;	//flag=1 直接比较T1的下一个date元 
				}
				else if(T2.date[si].j<cj){
					T3.date[newi].i=T2.date[si].i;
					T3.date[newi].j=T2.date[si].j;
					T3.date[newi].e=T2.date[si].e;
						newi++;
					//	printf("sj<  \n");
					si++;
			
				}
				else if((T2.date[si].j<cj)||(T2.date[si+1].i!=ci)){//si.j>cj
					T3.date[newi].e=ce;
					T3.date[newi].i=ci;
					T3.date[newi].j=cj;
					newi++;
					flag=1;
				 //	printf(">   ");	
					break;	
				}
			

			}//si.i==cj
			
			if(flag==1){
				flag=0;
				break;
			}
		}//si.i<=ci 
		if(T2.date[si-1].i==ci&&T2.date[si-1].j<cj){
					T3.date[newi].e=ce;
					T3.date[newi].i=ci;
					T3.date[newi].j=cj;
					newi++;
			}
		if(si==T2.tu&&(T2.date[si-1].j!=cj||T2.date[si-1].i!=ci)){
					T3.date[newi].e=ce;
					T3.date[newi].i=ci;
					T3.date[newi].j=cj;
						newi++;
					//	printf("T1额外的\n");
		}	//如果T2比完了 T1还没比完 
	}//这里只比完了T1的，是否T2的也比完了 是否还需要加代码 
	if(si<T2.tu){
		T3.date[newi].e=T2.date[si].e;
		T3.date[newi].i=T2.date[si].i;
		T3.date[newi].j=T2.date[si].j;
		newi++;
	//	printf("T2额外的\n");
		si++;	
	}
	T3.tu=newi;
	return 1;
}

int TranposTSMatris(TSMatrix &TS){
	return 1;
}


int main(){
	TSMatrix T1,T2,T3;
	printf("第一个矩阵\n"); 
	initTSMatrix(T1);
	printf("第二个矩阵\n"); 
	initTSMatrix(T2);
	plusTSMatris(T1,T2,T3);
	for(int v=0;v<T3.tu;v++){
		printf("T3矩阵第%d个元素为在第%d行，第%d列，值为%d\n",v+1,T3.date[v].i,T3.date[v].j,T3.date[v].e);
	}
	//T1 3 2 3 T2 3 3 3时出错 
	return 0;
}

#include<stdio.h>
int main(){
	for(int a=1;a<5;a++){		
		for(int i=0;i<=a-1;i++){
			printf(" ");
		}
		for(int j=0;j<=4-a;j++){
			printf("* ");
		}
		printf("\n");
	
	}
	return 0;
}
