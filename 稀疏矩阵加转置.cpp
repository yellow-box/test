#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 50
#include"iostream"
using namespace std;
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
	int k=0;int si=0;int newi=0; int flag1=0;int flag2=0;//k，T1的下表，  newi，T3的下表， 	Si，T2的下表 
	T3.mu=T1.mu;T3.nu=T1.nu;
	for(k=0;k<T1.tu&&si<T2.tu;k++){

	/*	printf("k=%d \n",k);
		printf("si=%d \n",si);*/
		ci=T1.date[k].i; 
		cj=T1.date[k].j;
		ce=T1.date[k].e;
		if(T2.date[si].i==ci){
			if(T2.date[si].j==cj){
				T3.date[newi].e=ce+T2.date[si].e;
				T3.date[newi].i=ci;
				T3.date[newi].j=cj;
				newi++; si++;
				if(si==T2.tu){
					flag2=1;
				}
				if(k==T1.tu-1){
					flag1=1;
				}
			}
			else if(T2.date[si].j<cj){
				T3.date[newi].e=T2.date[si].e;
				T3.date[newi].i=T2.date[si].i;
				T3.date[newi].j=T2.date[si].j;
				newi++; si++;k--;
				if(si==T2.tu){
					flag2=1;
				}	
			}
			else {
				T3.date[newi].e=ce;
				T3.date[newi].i=ci;
				T3.date[newi].j=cj;
				newi++;
				if(k==T1.tu-1){
					flag1=1;
				}
			}	
		}
	 	else if(T2.date[si].i<ci){
			T3.date[newi].e=T2.date[si].e;
			T3.date[newi].i=T2.date[si].i;
			T3.date[newi].j=T2.date[si].j;
			newi++; si++;k--;	
			if(si==T2.tu){
				flag2=1;
			}
		} 
		else {
			T3.date[newi].e=ce;
			T3.date[newi].i=ci;
			T3.date[newi].j=cj;
			newi++;
			if(k==T1.tu-1){
					flag1=1;
				}
		}
		
		if(flag1||flag2){
			break;
		}
	
	}
	if(flag1==0){
		k=k+1;
		while(k<T1.tu){
		T3.date[newi].e=T1.date[k].e;
		T3.date[newi].i=T1.date[k].i;
		T3.date[newi].j=T1.date[k].j;
	//		printf("flag1 newi=%d\n",newi);	
		k++;newi++;	
		}
	}
	if(flag2==0){
		while(si<T2.tu){
		T3.date[newi].e=T2.date[si].e;
		T3.date[newi].i=T2.date[si].i;
		T3.date[newi].j=T2.date[si].j;
	//	printf("flag2 newi=%d\n",newi);	
		si++;newi++;
		}
	}
	
	
	T3.tu=newi;
	return 1;
}

int TranposTSMatris(TSMatrix M,TSMatrix &T ){
	T.mu=M.mu;T.nu=M.nu;T.tu=M.tu;
	int num[10];int copt[10];
	if(T.tu) {
		for(int c=0;c<M.tu;c++)num[c]=0;
		for(int t=0;t<M.tu;t++)++num[(M.date[t].j)-1];
		copt[0]=0;
		for(int c=1;c<M.tu;c++)copt[c]=copt[c-1]+num[c-1];
		int c=0;int q;
		for(int p=0;p<M.tu;p++){
			c=M.date[p].j;c--; q=copt[c];
			T.date[q].i=M.date[p].j;T.date[q].j=M.date[p].i;T.date[q].e=M.date[p].e;
			++copt[c];
		}
	}
	return 1;
}
void output(TSMatrix a)
{
    int c = 0;
    for (int l = 1; l <= a.mu; l++)
    {
        for (int q = 1; q<= a.nu; q++)
        {
            if (l!=a.date[c].i||q != a.date[c].j || c == a.tu)
            {
                cout << "0 ";
            }
            else
            {
                cout << a.date [c].e << " ";
                c++;
            }
        }
        cout << endl;
    }
}


int main(){
	TSMatrix T1,T2,T3;
	printf("第一个矩阵\n"); 
	initTSMatrix(T1);
		printf("第一个矩阵\n"); 
	output(T1);
	printf("第二个矩阵\n"); 
	initTSMatrix(T2);
		printf("第二个矩阵\n");
	output(T2);
	plusTSMatris(T1,T2,T3);
		printf("和矩阵\n");
	output(T3);
/*	TranposTSMatris(T1,T3);
printf("转置后矩阵\n");
	output(T3);*/
	return 0;
}
