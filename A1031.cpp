#include<iostream>
#include <string>
using namespace std;
int main()
{
    string str;
    cin >> str;
    int n,m;
    n = (str.length()+2)/3;
    m = (str.size())+2-2*n;
    char a[n][m];
    for(int i = 0; i < n; i++)
    for(int j = 0; j < m; j++) {
        a[i][j] = ' ';
    }
    int index = 0;
    for(int i = 0; i < n; i++,index++) {
        a[i][0] = str[index];
    }
    for(int i = 1; i < m; i++,index++) {
        a[n-1][i] = str[index];
    }
    for(int i = n-2; i >=0; i--,index++) {
        a[i][m-1] = str[index];
    }
    for(int i = 0; i < n; i++) {
     for(int j = 0; j < m; j++) {
        cout << a[i][j];
    }
    cout << endl;
    }

    return 0;
}
