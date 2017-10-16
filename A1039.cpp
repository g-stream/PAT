#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
int main()
{
    int n,m;
    cin >> n >> m;
    map<string,vector<int> > record;
    while(m--) {
        int k,index;
        cin >> index >> k;
        while(k--) {
            string s;
            cin >> s;
            record[s].push_back(index);
        }
    }
    vector<string> v;
    string s;
    while(n--){
        cin >> s;
        v.push_back(s);
    }
    for(int i = 0; i < v.size(); i++){
        //cout << "processing:" <<i<<endl;
        cout << v[i] << " " << record[v[i]].size();
        sort(record[v[i]].begin(),record[v[i]].end());
        for(int j = 0; j < record[v[i]].size(); j++)
        {
            cout<< " " << record[v[i]][j];
        }
        cout << endl;
    }
    return 0;
}
