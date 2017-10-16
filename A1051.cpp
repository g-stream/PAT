#include <iostream>
#include <stack>
#include <vector>
using namespace std;
int main()
{
    int s,n,k;
    cin >> s >> n >> k;
    int now;
    vector<bool> v;
    while(k--) {
        vector<int> l;
        bool flag = true;
        for(int i = 1;i <= n; i++) {
            cin >> now;
            l.push_back(now);
        }
        stack<int> st;
        int num=1;
        for(int i = 0;i < n; i++) {
            while(num<=n&&(st.empty()||st.top()!=l[i])){
                st.push(num++);
            }
     //       cout << "st.size():" << st.size()<<endl;
            if(st.size()>s) {flag=false;break;}
            if (st.top()==l[i]) {
                st.pop();
            } else {flag = false;break;}

        }
        if(flag) cout<< "YES"<<endl;
        else cout<< "NO"<<endl;
    }
    return 0;
}
