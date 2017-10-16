#include <string>
#include <vector>
#include <map>
#include <iostream>
using namespace std;
inline char convert(char c)
{
    if(c<='Z'&&c>='A') return c-'A'+'a';
    return c;
}
bool is(char c)
{
    return ('a'<=c&&'z'>=c)||('A'<=c&&'Z'>=c)||('0'<=c&&'9'>=c);
}
int main()
{
    map<string,int> r;
    string s;
    getline(cin ,s);
    string word;
    int index = 0;
    for(int i = 0; i <= s.size(); i++){
        if(is(s[i])&&(i==0||!is(s[i-1]))){
            index = i;word.clear();
        } else if(i>0&&(!is(s[i])||i==s.size())&&is(s[i-1])){
            for(int k=index;k<i;k++){
                word.push_back(convert(s[k]));
            }
            r[word]++;
        }
    }
    int m=0;
    string ans;
    for(map<string,int>::iterator it = r.begin();it!=r.end();it++){
        if(it->second>m){
            m = it->second;
            ans = it->first;
        }
    }
    cout << ans << " " << m;
}
