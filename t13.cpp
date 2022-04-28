#include<stdio.h>
#include<string.h>
#define maxn 1010
//開燈問題 n 盞燈 k個人 k<=n<=1000
int a[maxn];
int main(){
    int n, k, f=1;
    memset(a,0,sizeof(a)); //將陣列a清除
    scanf("%d%d", &n,&k);
    for(int i=1;i<=k;i++){
        for(int j=1;j<=n;j++){
            if(j % i ==0){
                a[j] = !a[j];
            }
        }
    }
    for(int i=1; i<=n;i++){ //變數f 第一個變數之前不能有空格
        if(a[i]){
            if(f) f=0;
            else printf(" ");
            printf("%d",i);
        }
    }
    printf("\n");
    return 0;
}