#include<cstdio>
#include<queue>
#include<map>
using namespace std;
const int maxt=1000+10;

int main(){
    int t,kase=0;
    while(scanf("%d",&t)==1 && t){
        printf("scenario #%d\n",++kase);
        //紀錄所有人的團隊編號 
        map<int, int> team; //team[x]表示編號為x的人所再的團隊編號
        for(int i=0;i<t;i++){
            int n,x;
            scanf("%d",&n);
            while(n--) { scanf("%d",&x);team[x]=i; }
        }

        //模擬
        queue<int> q,q2[maxt]; //q是團隊的佇列 q2[i]是團隊i成員的佇列
        for(;;){
            int x;
            char cmd[10];
            scanf("%s",cmd);
            if(cmd[0]=='S') break;
            else if(cmd[0]=='D'){
                int t=q.front();
                printf("%d\n",q2[t].front()); q2[t].pop();
                if(q2[t].empty()) q.pop(); //團體t全體出佇列pop
            }
            else if(cmd[0]=='E'){
                scanf("%d",&x);
                int t=team[x];
                if(q2[t].empty()) q.push(t);//團體t全體進入佇列push
                q2[t].push(x);
            }
        }
        printf("\n");
    }
    return 0;
}
