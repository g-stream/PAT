#include<cstdio>
#include<set>
using namespace std;
set<int> s[51];
int main()
{
    int n;
    scanf("%d",&n);
    int m;
    int index = 1;
    while(n--){
        scanf("%d",&m);
        while(m--){
            int k;
            scanf("%d",&k);
            s[index].insert(k);
        }
        index++;
    }
    scanf("%d",&m);
    while(m--){
        int i,j;
        scanf("%d%d",&i,&j);
        int total =s[i].size();
        int same = 0;
        for(set<int>::iterator it=s[j].begin();it!=s[j].end();it++){
            if(s[i].count(*it))same++;
            else total++;
        }
        printf("%0.1f%%\n",same*100.0/total);
    }
}
