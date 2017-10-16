#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
string add(string s)
{
    string r = s;
    reverse(s.begin(),s.end());
    int rr = 0;
    string ans;
    for(int i = r.size()-1; i >= 0; i--){
        ans.push_back((r[i]+s[i]-'0'*2+rr)%10+'0');
        rr = (r[i]+s[i]-'0'*2)/10;
    }
    if(rr){
        ans.push_back(rr+'0');
    }
    reverse(ans.begin(),ans.end());
    return ans;
}
bool is(string s) {
    int i = 0;
    int j = s.size()-1;
    for(;i<=j;i++,j--){
        if(s[i]!=s[j]) return false;
    }
    return true;
}
int main()
{
    string s;
    int n;
    cin >> s >> n;
    for(int i = 0; i < n; i++){
        if(is(s)) {
            cout << s << endl << i << endl;
            return 0;
        }
        s = add(s);
    }
    cout << s << endl << n << endl;

}
