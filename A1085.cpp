#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    long long  n,p;
    cin >> n>>p;
    vector<long long > v;
    while(n--){
        int tmp;
        cin >> tmp;
        v.push_back(tmp);
    }
    sort(v.begin(),v.end());
    int m=1;
    for(int i = 0;i+m-1<v.size();i++){
        while(i+m-1<v.size()&&v[i]*p>=v[i+m-1]){
            m++;
        }
    }
    cout<<--m;
}
