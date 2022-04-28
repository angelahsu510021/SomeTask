#include<stdio.h>
#include<math.h>
//尋找aabb數字判斷為完全平方數
int main(){
    for(int a=1;a<=9;a++){
        for (int b=0; b <=9; b++)
        {
            int n =a*1100+b*11;//在使用n的地方定義n
            int m =floor(sqrt(n)+0.5); //floor+0.5用意為四捨五入
            if(m*m==n);
            printf("%d\n",n);
        }
    }
    return 0;
}