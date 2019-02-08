//Solved By sean9892 [https://blog.naver.com/ensy0713]
#include<stdio.h>
//Solution for n=15
#define n 15  
//Solution Function(idx=줄 번호, u=세로줄 비트마스크, l,r=대각선 비트마스크)
int f(int idx,int u,int l,int r){  
    if(idx==n)return 1;  
    int sum=0;
    for(int i=0;i<n;i++){
        if(!(u&(1<<i))&&!(l&(1<<(idx+i)))&&!(r&(1<<(n+idx-i)))){
            sum+=f(idx+1,u|(1<<i),l|(1<<(idx+i)),r|(1<<(n+idx-i)));  
        }  
    }  
    return sum;  
}  
  
int main(void){  
    int sum=0;  
    for(int i=0;i<n/2;i++){  
        sum+=2*f(1,1<<i,1<<i,1<<(n-i));  
    }  
    if(n%2){  
        sum+=f(1,1<<n/2,1<<n/2,1<<(n-n/2));  
    }  
    printf("%d",sum);  
}  
