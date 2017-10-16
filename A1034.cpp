#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;
map<string,string> parent;
string find(string s)
{
    if(parent[s]==s)
        return parent[s];
    else {
        string ans = find(parent[s]);
        parent[s] = ans;
        return ans;
        }
}

int main()
{



    return 0;
}
