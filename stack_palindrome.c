#include<stdio.h>
#include<string.h>
int top=0;
char stack[50];
void push(char c){
    //int top=0;
    top++;
    stack[top]=c;



}

char pop(){
    char each;
    each=stack[top];
    top--;
    return each;

}
 
int main(){
    char string[]="rotators";
    int i,count=0,len;
    len=strlen(string);
    for(i=0;i<len;i++){
        push(string[i]);
    }
    for(i=0;i<len;i++){
        if(string[i]==pop())
        count++;
    }
    if(len==count)   printf("pallindrome");
    else printf("not pallindrome");
} 