#include<stdio.h>
int main(){ // 輸入n S=1!+2!+...+n!
    int n, S=0;
    scanf("%d" ,&n);
    for(int i=1;i<=n;i++){ // 寫階乘累加的迴圈
        int f =1; //宣告階乘 初始化為1
        for(int j=1;j<=i;j++){ // 寫階乘累乘的迴圈 3!=3*2*1
            f *= j;
        }
        S += f;
    }
    printf("%d\n", S % 1000000); //取階乘累加後的末六位
    return 0;
}