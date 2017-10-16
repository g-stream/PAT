#include<iostream>
#include<string>
#include<vector>
#include<deque>
#include<set>
#include<functional>
#include<algorithm>
using namespace std;

int main()
{
    int n,m,k;
    set<string> in;
    deque<string> ans;
    cin >> n >> k >> m;
    m--;
    k--;
    while(n--){
        string str;
        cin >> str;
        ans.push_back(str);
    }
    vector<string> v;
    while(m--){
        ans.pop_front();
        if(ans.empty()){
        cout << "Keep going...\n";
        return 0;
            }
    }
    while(!ans.empty()){
        if(!ans.empty()){
            while(find(v.begin(),v.end(),ans[0])!=v.end()){
                ans.pop_front();
            }
            if(ans.empty()){break;}
            v.push_back(ans[0]);
            ans.pop_front();
        }
        for(int i = 0; i < k; i++){
            if(ans.empty())break;
            ans.pop_front();
        }
    }
    for(int i = 0; i < v.size(); i++){
        cout << v[i] << endl;
    }
}
