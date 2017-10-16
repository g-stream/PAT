#include <iostream>
#include <vector>
#include <stack>
using namespace std;
struct node
{
    int p;
    int r;
    int l;
    int var;
};
int main()
{
    vector<int> inorder,preorder;
    stack<int> st;
    int n;
    cin >> n;
    node tree[n+1];
    string s;
    for(int k=0;k<2*n;k++){
        cin >> s;
        if(s[1]=='u'){
            int var;
            cin >> var;
            inorder.push_back(var);
            st.push(var);
        } else {
            preorder.push_back(st.top());
            st.pop();
        }
    }
    for(int i = 0; i < inorder.size(); i++){
        cout << preorder[i];
    }

}
