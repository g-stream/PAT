
#include<vector>
#include<iostream>
using namespace std;
int main()
{
    int n,m;
    cin >> n >> m;
    int ver = n;
    vector<vector<int> > g(n+1,vector<int>(n+1,0));
    for(int i=0;i<m;i++){
        int n1,n2;
        cin >> n1 >> n2;
        g[n1][n2]=1;
        g[n2][n1]=1;
    }
    vector<bool> passed(n+1,false);
    cin >> n;
    while(n--){
        fill(passed.begin(),passed.end(),false);
        cin>>m;
        vector<int > path;
        for(int i=0;i<m;i++){
            int tmp;
            cin >> tmp;
            path.push_back(tmp);
        }
        bool ok = true;
        for(int i=0;i<m-1;i++){
            if(path[0]!=path[m-1]||m!=ver+1){ok = false;break;}
            if(!g[path[i]][path[i+1]]){
                ok = false;
                break;
            }
            if(passed[path[i]]){
                ok = false;
                break;
            }
            passed[path[i]] = true;
        }
        if(ok)cout<<"YES\n";
        else cout<<"NO\n";
    }
}
