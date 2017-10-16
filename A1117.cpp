#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<int> v;
    for(int i = 0; i < n; i++){
        int tmp;
        cin >> tmp;
        v.push_back(tmp);
    }
    sort(v.rbegin(),v.rend());
    int i=0;
    for(; i < v.size(); i++)
    {
        if(v[i]<=i+1)break;
    }
    cout << i;
}
