#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
int main() {
    vector<int> v1,v2;
    int n;
    cin >> n;
    while(n--) {
        int i;
        cin >> i;
        v1.push_back(i);
    }
    cin >> n;
    while (n--) {
        int i;
        cin >> i;
        v2.push_back(i);
    }
    sort(v1.begin(),v1.end());
    sort(v2.begin(),v2.end());
    int sum = 0;
    for(int i = 0;i<v1.size()&&i<v2.size();i++)
        if(v1[i]<0&&v2[i]<0) sum+=v1[i]*v2[i];
        else break;
    for(int i = 0;i<v1.size()&&i<v2.size();i++)
        if(v1[v1.size()-1-i]>0&&v2[v2.size()-i-1]>0) sum+=v1[v1.size()-1-i]*v2[v2.size()-i-1];
        else break;
    cout << sum;
}
