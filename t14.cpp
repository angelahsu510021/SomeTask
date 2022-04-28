#include<stdio.h>
#include<string.h>
#define maxn 20
//蛇形填數
int a[maxn][maxn]; //宣告陣列
int main(){
    int n,x,y,t=0;
    scanf("%d",&n);
    memset( a ,0,sizeof(a));
    t=a[x=0][y=n-1] = 1; //1.指定a陣列下標 2.矩陣最右上角a[0][n-1]和t訂為1
    while (t < n*n)
    {
        while(x+1<n && !a[x+1][y]) a[++x][y] = ++t;//x遞增 往下走 先判斷是否成立再行填值
        while(y-1>=0 && !a[x][y-1]) a[x][--y] = ++t;//呈上類推
        while(x-1>=0 && !a[x-1][y]) a[--x][y] = ++t;//呈上類推
        while(y+1<n && !a[x][y+1]) a[x][++y] = ++t;//呈上類推
    }
    for(x=0;x<n;x++){
        for(y=0;y<n;y++) printf("%3d",a[x][y]); //矩陣輸出
        printf("\n");
    }
    return 0;
}