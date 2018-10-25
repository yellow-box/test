#include"stdio.h"
#include"stdlib.h"
#include"string.h"
#define STACK_INT_SIZE 100
#define STACKINCREA  2
typedef struct Sqstack1{
	int		*top;
	int 	 *base;
	int 	 stacksize;
}Sqstack1; 
int initstack1(Sqstack1 &S){
	S.base=(int*)malloc(STACK_INT_SIZE*sizeof(int));
	if(!S.base)return 0;
	S.top=S.base;
	S.stacksize=STACK_INT_SIZE;
	return 1;
} 
int Push1(Sqstack1 &S,int e){
	if(S.top-S.base<S.stacksize){
			*S.top=e;
			S.top++;
		return 1;
	}
	return 0;
}
int Pop1(Sqstack1 &S,int &e){
	if(S.base==S.top){return 0;
	}
	S.top--;
	e=*S.top; 
	return 1;
}
int Gettop1(Sqstack1 S){
	if(S.base==S.top){return 0;
	}
	int e;
	e=*(S.top-1);
	return e;
}
int Isopf(char c){
	switch(c){
		case'+':
		case'-':
		case'*':
		case'/':
		case'(':
		case')':
		case'#':return 1;
		default:return 0;		
	}
}
int connum(char a[]){
	int num=0;int b=1;int x=0;
	int length=strlen(a); 
	for(int t=1;t<=length;t++){
		x=b*(a[length-t]-48);
		b=10*b;
		num=num+x;
	}
	return num;
}
int next(char a[],int &i){
	char b[10];int j=0;
	while(!Isopf(a[i])){
		       b[j]=a[i];
		       j++;i++;
	}
	b[j]='\0';
	return connum(b);
}//i顺便已经被调到下一个位置 

int Comp(char a1, char a2) {
	if(a1=='+'){
		switch(a2){
			case'+':
			case'-':
			case'#':		
			case')':return 62;
			default:return 60;			
		}
	}
	if(a1=='-'){
		switch(a2){
			case'+':
			case'-':
			case'#':		
			case')':return 62;
			default:return 60;				
		}
	}
	if(a1=='*'){
		switch(a2){		
			case'(':return 60;
			default:return 62;				
		}
	}
	if(a1=='/'){
		switch(a2){		
			case'(':return 60;
			default:return 62;				
		}
	}
	if(a1=='('){
		switch(a2){
			case'#':return 0; //（后遇到#是属于表达式错误		
			case')':return 61;
			default:return 60;				
		}
	}
	if(a1==')'){
		switch(a2){		
			case'#':return 0;//)后遇到(是属于表达式错误
			default:return 62;				
		}
	}
	if(a1=='#'){
		switch(a2){	
			case')':return 0;	//#后遇到)是属于表达式错误
			case'#':return 61;
			default:return 60;				
		}
	}
}

int Operate(int a,int b,int c){
	switch(b){
		case'+':return a+c;
		case'-':return a-c;
		case'*':return a*c;
		case'/':return a/c;
		default:return -123321;
		}
}
int Opreatexpress(){
	Sqstack1 OPF,OPS;
	int d,e,x;int i=0;
    char a[100];
	initstack1(OPF);	initstack1(OPS);  Push1(OPF,'#');
	printf("请输入表达式并以#结束\n");
	gets(a);
	while(a[i]!='#'||Gettop1(OPF)!='#'){	
		if(!Isopf(a[i])){
			Push1(OPS,next(a,i));
		}		
		else{
			switch(Comp(Gettop1(OPF),a[i])){
			case'<':Push1(OPF,a[i]);i++;
			break;
			case'=':Pop1(OPF,x);i++;
			break;
			case'>':Pop1(OPF,x) ;Pop1(OPS,d);
			Pop1(OPS,e); Push1(OPS,Operate(e,x,d));//getchar();得到的是字符串，其强转int值是ASCII码，如1的ASCII码是49
			break;
			}
		}
	 }
	printf("计算结果：\n%d",Gettop1(OPS)); 
	return Gettop1(OPS);
} 
int main(){
	Opreatexpress();
	return 0;
}
