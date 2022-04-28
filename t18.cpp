#include<stdio.h>
#include<string.h>  //使用menset

int readchar() {
    for(;;) {
        int ch =getchar();
        if(ch != '\n' && ch != '\r') return ch; //一直讀到非分行符號為止
    }
}
int readint(int c) {
    int v=0;
    while (c--) v=v*2 +readchar() - '0';
    return v;
}

int code[8][1<8];
int readcodes() {
    memset(code,0,sizeof(code));//陣列清空
    code[1][0]=readchar(); //直接調到下一行開始讀取入結束讀到EOF
    for(int len =2;len <=7;len++) {
        for(int i =0;i<(1<<len)-1;i++) {
            int ch=getchar();
            if(ch == EOF) return 0;
            if(ch == '\n' || ch == '\r') return 1;
            code[len][i]=ch;
        }
    }
    return 1;
}

void printcodes() {
    for(int len=1;len <= 7;len++){
        for(int i =0;i<(1<<len)-1;i++){
            if(code[len][i]==0) return;
            printf("code[%d][%d]=%c\n",len,i,code[len][i]);
        }
    }
}

int main() {
    while(readcodes()) {
        for(;;) {
            int len =readint(3);
            if(len == 0) break;
            for(;;) {
                int v=readint(len);
                if(v == (1<<len)-1) break;
                putchar(code[len][v]);
            }
        }
        putchar('\n');
    }
    return 0;
}