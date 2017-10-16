#include <string>
#include <iostream>
#include <string>
#include <queue>
#include <algorithm>
using namespace std;
bool str_less(const string& s1,const string & s2)
{
    return s1+s2<s2+s1;
}
int main()
{
    vector<string> v;
    int n;
    cin >> n;
    if(n==0) {cout << 0;return 0;}
    while(n--)
    {
        string s;
        cin >> s;
        v.push_back(s);
    }
    sort(v.begin(),v.end(),str_less);
    string sum;
    for(int i = 0;i<v.size();i++) {
        sum += v[i];
    }
    while(sum[0]=='0'&&sum.size()!=1)sum.erase(sum.begin());
    cout<< sum;
}
