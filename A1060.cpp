#include <string>
#include <iostream>
using namespace std;
string convert(string s, int n)
{
    while(s.size()&&s[0]=='0')s.erase(s.begin());
    if(s.size()==0){
        s  = "0.";
        while(n--)s+="0";
        s+="10^0";
        return s;
    }

}
int main()
{
    string s1,s2;
    int n;
    cin >> n >> s1 >> s2;

}
