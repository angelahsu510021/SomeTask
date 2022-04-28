#include<stdio.h>
#include<string.h>
#define maxn 1000
#define maxl 100
#define EPS 1e-5
//資料結構小小成績系統 

int n=0;
char sid[maxn][maxl]; //定義學號
int cid[maxn]; //定義班級
char name[maxn][maxl]; //定義姓名
int score[maxn][5]; //定義待輸入的4門課程成績
int removed[maxn];

const char *course_name[]= {"中文", "數學", "英文", "程式設計"};

int valid(int k) {
    for(int i=0;i<k;i++) if (!removed[i]) {
        if(strcmp(sid[i],sid[k])==0) return 0;
    }
    return 1;
}

//新增資料
void add() {
    for(;;) {
        printf("請輸入學生學籍資料 按0結束\n");
        scanf("%s",sid[n]);
        if(strcmp(sid[n],"0")==0) break;
        //將成績輸入
        scanf("%d%s%d%d%d%d",&cid[n],name[n],&score[n][0],&score[n][1],&score[n][2],&score[n][3]);
        if(valid(n)) {score[n][4]=score[n][0]+score[n][1]+score[n][2],score[n][3];n++;}
        else printf("學生編號重複");
    }
}

int rank(int k) {
    int r=0;
    for(int i=0;i<n;i++){
        if(!removed[i] && score[i][4]>score[k][4]) r++;
    }
    return r+1;
}

void DQ(int isq) {
    char s[maxl];
    for(;;) {
        printf("請輸入學生編號或姓名 輸入0結束");
        scanf("%s",s);
        if(strcmp(s,"0")==0) break;
        int r=0; //刪除
        for(int i=0;i<n;i++) if(!removed[i]) {
            if(strcmp(sid[i],s)==0 || strcmp(name[i],s)==0) {
                if(isq) printf("%d %s %d %s %d %d %d %d %d %.2f\n", rank(i), sid[i], cid[i], name[i], score[i][0], score[i][1], score[i][2], score[i][3], score[i][4], score[i][4]/4.0+EPS);
                else {removed[i]=1;r++;}
            }
        }
        if(!isq) printf("%d (s)同學已被刪除\n",r);
    }
}


double get_course_stat(int c,int s,int *passed,int *failed){
    int tot=0;
    *passed=*failed=0;
    for(int i=0;i<n;i++){ //判斷及格與否
        if(!removed[i] && (c==0 || cid[i] == c)) {
            tot += score[i][s];
            if(score[i][s] >= 60) (*passed)++;else (*failed)++;
        }
    }
    return (double)tot / (double)(*passed + *failed);
}

void get_overall_stat(int c,int *cnt) {
    cnt[0]=cnt[1]=cnt[2]=cnt[3]=cnt[4]=0;
    for(int i=0;i<n;i++){ //全部排名
        if(!removed[i] && (c==0 || cid[i]==c)) {
            int k=0;
            for(int j=0;j<4;j++) if(score[i][j] >= 60) k++;
            cnt[k]++;
        }
    }
}

void stat() {
    int c;
    printf("輸入課程編號 輸入0結束\n");
    scanf("%d",&c);
    for(int i=0;i<4;i++) {
        int passed,failed;
        double avg = get_course_stat(c, i, &passed, &failed);
        printf("%s\n",course_name[i]);
        printf("平均: %.2f\n",avg+EPS);
        printf("通過學生人數: %d\n",passed);
        printf("被當學生人數: %d\n",failed);
        printf("\n");
    }
    int cnt[5];
    get_overall_stat(c,cnt);

    printf("全部: \n");
    printf("全部及格總數: %d\n", cnt[4]);
    printf("3科及格總數: %d\n", cnt[4]+cnt[3]);
    printf("2科及格總數: %d\n", cnt[4]+cnt[3]+cnt[2]);
    printf("1科及格總數: %d\n", cnt[4]+cnt[3]+cnt[2]+cnt[1]);
    printf("全部不及格總數: %d\n", cnt[0]);
    printf("\n");
}


int main() {
    for(;;) {
        int choice;
        printf("成績計算系統\n");
        printf("\n");
        printf("1 - 新增\n");
        printf("2 - 刪除\n");
        printf("3 - 查詢\n");
        printf("4 - 排名\n");
        printf("5 - 全部資訊統計\n");
        printf("0 - 離開\n");
        printf("\n");

        scanf("%d", &choice);
        if(choice == 0) break;
        if(choice == 1) add();
        if(choice == 2) DQ(0);
        if(choice == 3) DQ(1);
        if(choice == 4) printf("顯示排名會傷同學的心 不給看\n");
        if(choice == 5) stat();
    }
    return 0;
}