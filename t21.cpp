#include <cstdio>
#include <string>
#include <vector>
#include <iostream>
using namespace std;
const int maxn=30;
int n;
vector<int> pile[maxn]; //每個pile[i]是一個vector
//從左到右有n個木塊,編號0~n-1
//move a onto b:把a和b上方的木塊全部歸位 然後把a放在b上面
//move a over b:把a上方的木塊全部歸位 然後把a放在b所在木塊堆的頂部
//pile a onto b:把b上方的木塊全數歸位 然後把a及上面的木塊整體放在b上面
//pile a over b:把a及上面的木塊整體放在b所在的木塊堆的頂部

//找木塊a所在的pile和height,以引用的形式返回呼叫者
void find_block(int a,int& p,int& h) {
    for(p=0;p<n;p++){
        for(h=0;h<pile[p].size();h++){
            if(pile[p][h]==a) return;
        }
    }
}

//把第p堆高度為h的木塊上方的所有木塊移回原位
void clear_above(int p,int h) {
    for(int i=h+1;i<pile[p].size();i++) {
        int b=pile[p][i];
        pile[b].push_back(b); //把木塊b放回原位
    }
    pile[p].resize(h+1); //pile只保留下標0~h的元素
}

//把第p堆高度為h及其上方的木塊整體移動到p2堆的頂部
void pile_onto(int p,int h,int p2) {
    for(int i=h;i<pile[p].size();i++){
        pile[p2].push_back(pile[p][i]);
    }
    pile[p].resize(h);
}

void print() {
    for(int i=0;i<n;i++) {
        printf("%d:",i);
        for(int j=0;j<pile[i].size();j++){
            printf(" %d",pile[i][j]);
        } 
        printf("\n");
    }
}

int main() {
    int a,b;
    cin >> n;
    string s1,s2;
    for(int i=0;i<n;i++) pile[i].push_back(i);
    while(cin >> s1 >> a >> s2 >>b){
        int pa,pb,ha,hb;
        find_block(a,pa,ha);
        find_block(b,pb,hb);
        if(pa==pb) continue;
        if(s2=="onto") clear_above(pb, hb);
        if(s1=="move") clear_above(pa, ha);
        pile_onto(pa,ha,pb);
    }
    print();
    return 0;
}