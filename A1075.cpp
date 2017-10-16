#include <cstdio>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
int score[100000][6];
int full_mark[6];
struct R
{
    int r;
    int id;
    bool flag;
    int cnt;
};
bool cmp (const R& r1,const R& r2)
{
    if(score[r1.id][0]!=score[r2.id][0])
        return score[r1.id][0]>score[r2.id][0];
    else if(r1.cnt!=r2.cnt)
        return r1.cnt>r2.cnt;
    else return r1.id<r2.id;
}
int main()
{
    int n,k,m;
    cin >>n>>k>>m;
    for(int i = 1; i <= k;i++)
        cin >> full_mark[i];
    R v[n+1];
    for(int i = 1; i <= n; i++) {
        v[i].id = i;v[i].flag = false;v[i].cnt=0;
        score[i][0] = 0;
        for(int j = 1;j<=k;j++) {
            score[i][j] = -1;
        }
    }
    while(m--) {
        int i,j,s;
        cin >> i >> j >> s;
        if(score[i][j]==-1&&s==-1)score[i][j] = 0;
        if(s>=0)v[i].flag = true;
        if(score[i][j]<s)score[i][j]=s;
    }
    for(int i = 1;i<=n;i++)
    {
        int sum = 0;
        for(int j = 1;j<=k;j++) {

            if(score[i][j]>=0){sum+=score[i][j];}
            if(full_mark[j] == score[i][j])
                v[i].cnt++;
        }
        score[i][0] = sum;

    }
    sort(v+1,v+n+1,cmp);
    for(int i =1;i<=n;i++)
    {
        if(i==1) v[i].r =1;
        else if(score[v[i].id][0] == score[v[i-1].id][0] ) {
            v[i].r = v[i-1].r;
        }
        else v[i].r = i;
    }
    for(int i = 1;i<=n;i++) {
        if(v[i].flag) {
            printf("%d %05d %d",v[i].r,v[i].id,score[v[i].id][0]);
            for(int j = 1;j<=k;j++) {
                if(score[v[i].id][j]>=0) printf(" %d",score[v[i].id][j]);
                else printf(" -");
            }
            printf("\n");
        }
    }
    return 0;
}

