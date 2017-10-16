#include<algorithm>
#include<vector>
#include<iostream>
#include<cmath>
using namespace std;
int main()
{
    int n;
    vector<double> v;
    cin >> n;
    while(n--){
        double tmp;
         cin >> tmp;
         v.push_back(tmp);
    }

    sort(v.begin(),v.end());
    double sum = v[0];
    for(int i = 1 ;i < v.size(); i++){
        sum = (sum + v[i])/2;
    }
    cout << int(sum) << endl;
}
