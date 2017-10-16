#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
const int maxn = 100010;
int record[maxn];
int in[maxn];
int main()
{
 fill(record,record+maxn,-1);
  fill(in,in+maxn,0);
  int n;
  cin >>  n;
  while(n--){
  	int n1,n2;
    cin >> n1 >> n2;
    record[n1] = n2;
    record[n2] = n1;
  }
  cin >> n;
  vector<int> v;
  while(n--){
  	int tmp;
    cin >> tmp;
    v.push_back(tmp);
    in[tmp]++;
    if(record[tmp]!=-1){
      if(in[record[tmp]]){
      	v.erase(find(v.begin(),v.end(),record[tmp]));
        v.pop_back();
      }
    }
  }
  sort(v.begin(),v.end());
  cout<<v.size()<<endl;
  for(int i = 0; i < v.size(); i++)
  {
  	if(i>0)cout << " ";
    printf("%05d",v[i]);
  }
}
