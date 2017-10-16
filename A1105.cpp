
#include<iostream>
#include<vector>
#include<cstdio>
#include<algorithm>
#include<functional>
#include<cmath>
#include<utility>
using namespace std;
void print(const vector<int> & v)
{
    for(int i = 0; i < v.size(); i++) {
        if(i>0) cout << " ";
        cout << v[i];
    }
    cout << endl;
}
int main()
{
    int num;
    cin >> num;
    vector<int> v;
    for(int i = 0; i < num; i++) {
        int tmp;
        cin >> tmp;
        v.push_back(tmp);
    }
    int n,m;
    n = (int)sqrt((double)num);
    while(num%n!=0)n--;
    m = num/n;
    vector<vector<int> >ans(m,vector<int>(n,-1));
    sort(v.rbegin(),v.rend());
    pair<int,int> directions[4];
    directions[0] = make_pair(0,1);
    directions[1] = make_pair(1,0);
    directions[2] = make_pair(0,-1);
    directions[3] = make_pair(-1,0);
    pair<int,int> pos = make_pair(0,0);
    int d = 0;
    for(int i = 0; i < v.size();) {

        ans[pos.first][pos.second] = v[i++];
        if((d==0&&((pos.second+1)==n||ans[pos.first][pos.second+1]>=0))||
           (d==1&&((pos.first+1)==m||ans[pos.first+1][pos.second]>=0))||
           (d==2&&((pos.second-1)==-1||pos.second>=1&&ans[pos.first][pos.second-1]>=0))||
           (d==3&&((pos.first-1)==-1||pos.first>=1&&ans[pos.first-1][pos.second]>=0)))
           {d = (d+1)%4;}
        pos.first += directions[d].first;
        pos.second += directions[d].second;
    }
    for(int i = 0; i < ans.size(); i++) {
        print(ans[i]);
    }

}
