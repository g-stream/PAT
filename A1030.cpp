#include<vector>
#include <iostream>
using namespace std;
int main()
{
    int n_c,n_l,start,dist;
    cin >> n_c >> n_l >> start >> dist;
    vector<vector<int> > distance(n_c,vector<int>(n_c,0));
    vector<vector<int> > weight(n_c,vector<int>(n_c,0));
    vector<bool> vis(n_c);
    for(int k = 0; k < n_l; k++) {
        int i,j,d,w;
        cin >> i >> j >> d >> w;
        distance[i][j] = d;
        weight[i][j] = w;
    }
    vector<int> know(n_c);
    vector<int> w(n_c);
    vector<int> d(n_c,0x7fffffff);
    vector<int> pre(n_c);
    int now = start;
    know[now] = true;
    vis[now] = true;
    d[now] = 0;
    w[now] = 0;
    for(int i = 0; i < n_c;i++) {
           if(know[dist]) break;

        for(int j = 0; j < n_c; j++){
            if(distance[now][j]&&!know[j]&&(d[now] + distance[now][j]<d[j]||(d[now] + distance[now][j]==d[j]&&w[now]+weight[now][j]<w[j]))){
                vis[j] = true;
                d[j] = d[now] + distance[now][j];
                w[j] = w[now] + weight[now][j];
                pre[j] = now;
               // cout << "dist" << j <<"=" << d[j]<<"w:"<<w[j]<<endl;
            }
        }
        int next,tmp_d=0x7fffffff;
        for(int j = 0;j<n_c;j++)
        {
            if(!know[j]&&vis[j]&&d[j]<tmp_d)
            {
                next = j;
                tmp_d = d[j];
            }
        }
        now = next;
        know[now]=true;
    }
    vector<int> v;
    int tmp = dist;
    v.push_back(tmp);
    do{
        v.push_back(pre[tmp]);
        tmp = pre[tmp];
    }while(pre[tmp]!=start);
    cout << start<<" ";
    for(int i =0;i<v.size();i++){
        cout<< v[v.size()-1-i]<<" ";
    }
    cout << d[dist] << " ";

    cout<<w[dist];
}
