#include<stdio.h>
#define maxn 105
//逆序輸出
int a[maxn]; //宣告 maxn個整型變數的陣列 0~(maxn-1),但大陣列應宣告maxn函數外
int main(){
    int x, n=0;
    while(scanf("%d", &x)==1){
        a[n++]=x; //指定值a[n]=x,在執行n=n+1
    }
    for(int i = n-1;i>=1;i--){
        printf("%d",a[i]); //倒過來XD
    }
    printf("%d\n",a[0]);
    return 0;
}