#include<stdio.h>
int main(){
    //3n+1問題
    //任給一個自然數，若為偶數除以2，若為奇數則乘3加1
    //得到一個新的自然數後按照上面的法則繼續演算
    //若干次後得到的結果必然為1
    int n,count=0; //定義count為0
    scanf("%d", &n);
    while(n>1){
        if(n%2==1) n=n*3+1;
        else n /=2; //n /=2 => n=n/2
        count++;//計數器 算總共執行幾次
    }
    printf("%d\n",count);
    return 0;
}