
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <sstream>
using namespace std;
string fun(string s)
{
    sort(s.begin(),s.end());
    string r = s;
    reverse(s.begin(),s.end());
    stringstream sm;
    int r_int,s_int;
    sm << r;
    sm >> r_int;
    sm.clear();
    sm << s;
    sm >> s_int;
    int ans = s_int - r_int ;
   // cout << "ans:" << ans<<endl;
    sm.clear();
    sm << ans;
    string re;
    sm >> re;
    while(re.size()!=4){
        re.insert(re.begin(),'0');
    }
    return re;
}
int main()
{
    string s;
    cin >> s;
    while(s.size()!=4){
        s.insert(s.begin(),'0');
    }
    sort(s.begin(),s.end());
    if(s[0]==s[s.size()-1]){
        cout << s << " - " << s << " = " << "0000";
        return 0;
    } else {
        while(s != "6174"){
            sort(s.begin(),s.end());
            string r = s;
            reverse(r.begin(),r.end());
            cout << r << " - " << s << " = ";
            s = fun(s);
            cout << s << endl;
        }
    }
}
