#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//j-i>=strlen(b)
int preanily(char a[],char b[],int &num,int n[]){
	int i=0;int j=strlen(a);int k=0;num=0;
	while(i<j){
		if(a[i]==b[k]&&k<strlen(b)){
			i++;k++;
			if(k==strlen(b)){
				n[num]=i-k;
				num++;
				k=0;
			}
		}
		else{
			i++;k=0;	
			}
	}


}

int repalce(){
/*	char ch;int i=0;char s[60];char v[10];char t[10];
	printf("请输入主串，以#结束\n");
	ch=getchar();
	while(ch!='#'&&i<50) {
		s[i]=ch;
		i++;
		ch=getchar();
	}
	s[i]='\0';
	i=0;
	printf("请输入子串，以#结束\n");
	ch=getchar();
	while(ch!='#'&&i<10) {
		t[i]=ch;
		i++;
		ch=getchar();
	}
	t[i]='\0';
	i=0;
	printf("请输入要替换的串，以#结束\n");
	ch=getchar();
	while(ch!='#'&&i<10) {
		v[i]=ch;
		i++;
		ch=getchar();
	}
	v[i]='\0';	*/	//输入 
	int num=0; int i=0;int k=0;int n[10];int g=0;
		char s[]="abcdrfbcd";char t[]="bc";char v[]="aef";//这里是手动输入 
	preanily(s,t,num,n); 
	printf("替换完成后的串为：\n");
	while(num&&i<60){
		if(i==n[g]){
			while(k<strlen(v)){
			printf("%c",v[k]);k++;				
			}
			if(k==strlen(v)){
				k=0;	
			}
			i+=strlen(t);
			if(i<strlen(s)){
			printf("%c",s[i]);
			}
		i++;num--;g++;
		}
		else{
			printf("%c",s[i]);
			i++;
		}
	
	}
	
	return 1;
}
void in(char a[]){
	a[1]='\0';
}
int main(){
	 repalce();

	return 0;
}
