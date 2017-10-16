#include <vector>
#include <iostream>
#include<cstdio>
#include<algorithm>
#include<functional>
using namespace std;
const int maxn = 510;
int G[maxn][maxn];
int T[maxn][maxn];
int wG[maxn];
int wT[maxn];
int pG[maxn];
int pGt[maxn];
int pT[maxn];
int pTn[maxn];
bool visG[maxn];
bool visT[maxn];
int source,destination;
int n_s,n_r;
const int INF = 0x3fffffff;
int main()
{
    cin >> n_s >> n_r;
    for(int i = 0; i < n_s; i++){
        pG[i] = -1;
        pT[i] = -1;
        visG[i] = false;
        visT[i] = false;
        wG[i] = INF;
        wT[i] = INF;
        for(int j = 0; j < n_s; j++){
            T[i][j] = INF;
            G[i][j] = INF;
        }
    }
    for(int i = 0; i < n_r; i++){
        int s,d,one_way,l,t;
        cin >> s >> d >> one_way >> l >> t;
        T[s][d] = t;
        G[s][d] = l;
        if(one_way==0){
            T[d][s] = t;
            G[d][s] = l;
        }
    }
    cin >> source >> destination;
    wT[source] = 0;
    wG[source] = 0;
    pTn[source] = 1;
    pGt[source] = 0;
    for(int i = 0; i < n_s; i++){
        int uT=-1,uG=-1;
        int minT = INF;
        int minG = INF;
        for(int j = 0; j < n_s; j++){
            if(!visG[j]&&wG[j]<minG){
                minG = wG[j];
                uG = j;
            }
            if(!visT[j]&&wT[j]<minT){
                minT = wT[j];
                uT = j;
            }
        }
        if(uT==-1&&uG==-1)break;
        visT[uT] = true;
        visG[uG] = true;
        for(int j = 0; j < n_s; j++){
            if(!visG[j]&&G[uG][j]!=INF){
                if(G[uG][j]+wG[uG]<wG[j]){
                    wG[j] = G[uG][j]+wG[uG];
                    pGt[j] = pGt[uG] + T[uG][j];
                    pG[j] = uG;
                } else if(G[uG][j]+wG[uG]==wG[j]){
                    if(pGt[j] > pGt[uG] + T[uG][j]){
                        pGt[j] = pGt[uG] + T[uG][j];
                        pG[j] = uG;
                    }
                }
            }
            if(!visT[j]&&T[uT][j]!=INF){
                if(wT[uT]+T[uT][j]<wT[j]){
                    wT[j] = wT[uT]+T[uT][j];
                    pTn[j] = pTn[uT]+1;
                    pT[j] = uT;
                }else if(wT[uT]+T[uT][j]==wT[uT]){
                    if(pTn[j]>pTn[uT]+1){
                        pTn[j] = pTn[uT]+1;
                        pT[j] = uT;
                    }
                }
            }
        }
    }
    vector<int> ansG,ansT;
    int d1=destination,d2=destination;
    while(d1!=source){
        ansG.push_back(d1);
        d1 = pG[d1];
    }
    while(d2!=source){
        ansT.push_back(d2);
        d2 = pT[d2];
    }
    reverse(ansG.begin(),ansG.end());
    reverse(ansT.begin(),ansT.end());
    if(ansG==ansT){
        cout << "Distance = " << wG[destination] << "; Time = " << wT[destination] << ": ";
        cout << source;
        for(int i = 0; i < ansG.size(); i++){
            cout << " -> " << ansG[i];
        }
        cout <<endl;
    } else {
        cout << "Distance = " << wG[destination] << ": ";
        cout << source ;
        for(int i = 0; i < ansG.size(); i++){
            cout << " -> "<< ansG[i] ;
        }
        cout <<endl;
        cout << "Time = " << wT[destination] << ": ";
        cout << source ;
        for(int i = 0; i < ansT.size(); i++){
            cout << " -> " << ansT[i];
        }
        cout <<endl;
    }
}
