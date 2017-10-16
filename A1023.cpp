#include <sstream>
#include<iostream>
#include <algorithm>
#include <string>
using namespace std;
string d(string s)
{
    string ans;
    int jin=0;
    char now;
    for(int i =0;i<s.size();i++)
    {

        now = ((s[s.size()-1-i]-'0')*2+jin)%10+'0';
        jin = (s[s.size()-1-i]-'0')*2/10;
        ans.push_back(now);
    }
    if(jin)ans.push_back((char)(jin+'0'));
    reverse(ans.begin(),ans.end());
    return ans;
}
int main()
{
    string orgin;
    cin >> orgin;
    string backup = d(orgin);
    string processed = backup;
    sort(orgin.begin(),orgin.end());
    sort(processed.begin(),processed.end());
    if(orgin == processed) cout<<"Yes";
    else cout  << "No";
    cout << endl<<backup;
    return 0;
}
