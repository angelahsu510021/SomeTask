#include<stdio.h>
#include<string.h>
#define maxn 100
int left,chance; //猜left個位置 錯chance次算輸
char s[maxn],s2[maxn]; //s為答案 s2為猜的字串
int win,lose;
//劊子手game
void guess(char ch){
    int bad=1;
    for(int i=0;i<strlen(s);i++)
        if(s[i] == ch) { left-- ; s[i] = ' '; bad=0; } //將猜對的字元改成空格
    if(bad) --chance;
    if(!chance) lose=1; //輸
    if(!left) win=1; //贏
}

int main(){
    int rnd;
    while (scanf("%d%s%s",&rnd,s,s2) == 3 && rnd != -1)
    {
        /* code */
        printf("round %d\n",rnd);
        win=lose=0; //初始化為0
        left=strlen(s);
        chance=7;
        for(int i = 0; i < strlen(s2) ;i++){
            guess(s2[i]); //呼叫guess函數猜一個字母
            if(win || lose) break; //狀態檢查
        }
        //結果輸出
        if(win) printf("win\n");
        else if(lose) printf("lose\n");
        else printf("chickened out\n");
    }
    return 0;
}