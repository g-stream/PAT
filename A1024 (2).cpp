#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
string add(string s)
{
    string o = s;
    reverse(s.begin(),s.end());
    int r = 0;
    string ans;
    for(int i= s.size()-1;i>=0;i--){
        ans.push_back((s[i]-'0'+o[i]-'0'+r)%10+'0');
        r = (s[i]-'0'+o[i]-'0'+r)/10;
    }
    if(r)ans.push_back(r+'0');
    reverse(ans.begin(),ans.end());
    return ans;
}
bool check(string s)
{
    int  i=0,j=s.size()-1;
    while(i<=j){
        if(s[i]!=s[j]) return false;
        i++;j--;
    }
    return true;
}
int main()
{
    string s;

    int n;
    cin >> s >> n;
      //  cout << "dkjf" << add("143");
    for(int i = 0;i<n;i++){
        s = add(s);
        if(check(s))
    {cout<<s<<endl<<i+1;return 0;
    }
}
cout << s << endl << n;
}
