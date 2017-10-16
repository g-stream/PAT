#include<vector>
#include<iostream>
#include<string>
#include<sstream>
using namespace std;
int convert(int n)
{
  int sum = 0;
  do{
    sum += n%10;
    n/=10;
  }while(n);
  return sum;
}
int num[9*4+1]={0};
  int cnt=0;
int main()
{
  int n;
  cin>>n;
  vector<int> v;
  for(int i = 0; i<n;i++){
    int tmp;
    cin >> tmp;
  // v.push_back(tmp);
    int ed = convert(tmp);
    if(num[ed]==0){num[ed]++;cnt++;}
  }
  bool first = true;
  cout << cnt<<endl;
  for(int i=0;i<37;i++)
  {
    if(num[i]){if(!first)cout<<" ";
               cout<<i;
               first = false;}
  }
}
