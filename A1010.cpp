#include <vector>
#include <string>
#include <iostream>
#include <map>
using namespace std;
map<long long, char> i2c;
map<char,long long> c2i;
long long to10(string s, long long r){
    long long ans=0;
    for(long long i = 0; i < s.size(); i++){
        ans = ans*r+c2i[s[i]];
    }
    return ans;
}
int main(){
    for(long long i = 0;i<=9;i++){
        c2i['0'+i] = i;
        i2c[i] = '0' + i;
    }
    for(long long i=0;i<=26;i++){
        c2i['a'+i] = 10+i;
        i2c[10+i] = 'a'+i;
    }
    string str[2];
    char cc;
    long long r,index;
    cin >> str[0] >> str[1] >> index >> r;
    index--;
    long long other = 1-index;
    long long ans_r = -1;
    long long sum = to10(str[index],r);
    long long mn=0,mx;
    long long minx;
    for(long long i = 0; i <str[other].size(); i++){
        if(mn<c2i[str[other][i]]) mn = c2i[str[other][i]];
    }
    mn++;
    mx = ((sum>mn)?sum:mn)+1;
    minx = mn;
    while(mn<=mx){
      //  cout << mn << " " << mx << endl;
        long long p = (mn+mx)/2;
        if(sum == to10(str[other],p)){
            ans_r = p;
            break;
        }
        else if(sum >to10(str[other],p)){
            mn = p+1;
        }else {
            mx = p-1;
        }
    }

    if(ans_r>0) {
        while(to10(str[other],ans_r)==sum&&minx<=ans_r){
            ans_r--;
        };
        cout << ++ans_r;
    } else {
        cout << "Impossible";
    }
}
