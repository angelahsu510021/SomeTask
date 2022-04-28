#include<cstdio>
#include<algorithm>
//STL小練習
//排序
using namespace std;
const int maxn=10000;

int main() {
    int n,q,x,a[maxn],kase=0;
    while(scanf("%d%d",&n,&q) == 2 && n) {
        printf("CASE# %d:\n",++kase);
        for(int i=0;i<n;i++) scanf("%d",&a[i]);
        sort(a,a+n);//排序
        while(q--) {
            scanf("%d",&x);
            //lower_bound 尋找大於或等於x的第一個位置
            int p=lower_bound(a,a+n,x) -a;//在以排序陣列a尋找x
            if(a[p]==x) printf("%d found at %d\n",x,p+1);
            else printf("%d not found\n",x);
        }
    }
    return 0;
}