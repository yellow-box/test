#include<stdio.h>
#include<stdlib.h>
typedef struct{
	char * ch;
	int length;
}HString;

int AssignHString(HString &S,char* chars){
	if(!chars)return 0;
	if(S.ch)free(S.ch);
	int i;char *c;
	for(i=0,c=chars;*c;i++);
	if(!i){S.length=0;S.ch=NULL;
	}
	else{
		S.ch=(char*)malloc(i*sizeof(c));
		if(S.ch==NULL)return 0;
		for(int j=0;j<=i;j++){
			*(S.ch++)=chars[j];
		}
	}
	return 1;
}


int getNext(HString T,int next[]){
	int	i=1;int j=0; next[1]=0; 
	while(i<T.length){
		if(T.ch[i]==T.ch[j]||j==0){
			next[j++]++;
		}
		else{
			j=next[j];
		}
	}	
}

int Indexkmp(HString S,HString T,int next[],int &pos){
	int i=0;int j=0;
	while(i<=S.length&&j<=T.length){
		if(S.ch[i]==T.ch[j]||j==0){
		i++;j++;
		}
	else{
		j=next[j];
		}
	}
	if(j>T.length)return i-T.length;
	else return 0;
	return 1;
}

int cutHString(HString &S,HString T,HString &C1,HString &C2,int pos){
	int i=0; int j=0;
	/*int pos=0;int next[T.length];
	getNext(T,next);
	Indexkmp(S,T,next,pos);*/
	C1.length=S.length-pos;
	C2.length=S.length-C1.length-T.length;
	while(i<C1.length){
		C1.ch[i]=S.ch[i];i++;
	}
	i=0;j=C1.length+T.length;
	while(j<S.length){
		C2.ch[i]=S.ch[j];
	}
	return 1;
}

int ConnectHString(HString &S,HString C1,HString V,HString C2){
	if(S.ch)free(S.ch);
	int k=C1.length+V.length+C2.length; 
	S.ch=(char*)malloc(k*sizeof(char));
	if(!S.ch)return 0;
	k=0;
	while(k<C1.length){
		S.ch[k]=C1.ch[k];
		k++;
	}
	int l=0;
	while(l<V.length){
		S.ch[k]=V.ch[l];
		l++;k++;
	}
	l=0;
	while(l<C2.length){
		S.ch[k]=C2.ch[l];
		l++;k++;
	}	
	return 1;
}
int Replace(HString &S,HString T,HString V){
	HString C1,C2; int j,k;
	int pos=0;int next[T.length];
	getNext(T,next);
	Indexkmp(S,T,next,pos);
	int c1l=pos;
	int c2l=S.length-c1l-T.length;
	C1.ch=(char *)malloc(c1l*sizeof(char));
	C2.ch=(char *)malloc(c2l*sizeof(char));
	if(!S.ch)free(S.ch);
	j=cutHString(S,T,C1,C2,pos);
	k=ConnectHString(S,C1,V,C2);
	if(j||k) return 0;
	for(int i=0;i<S.length;i++){
		printf("%c",S.ch[i]);
	}
	return 1;	
}//子串为T，V长度可能大于T   //老师好像说的是要替换掉主串中所有的和子串相同的地方 

int main(){
	char s[]="abcdefhijk";
	char t[]="bc";
	char v[]="dfgg";
	HString S,T,V;
	 AssignHString(S,s);
	 AssignHString(T,t);
     AssignHString(V,v);
     Replace(S,T, V);
	return 0;
}
