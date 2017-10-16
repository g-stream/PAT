#include <map>
#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
int num,num_q;
string id,title,author,keyword,pub,year;
map<string,vector<string> > mp_title;
map<string,vector<string> > mp_author;
map<string,vector<string> > mp_kw;
map<string,vector<string> > mp_pub;
map<string,vector<string> > mp_year;
int main()
{
    cin >> num;
    cin.ignore();
    while(num--){
        getline(cin, id);
        getline(cin, title);
        mp_title[title].push_back(id);
        getline(cin, author);
        mp_author[author].push_back(id);
        stringstream sm;
        string line;
        getline(cin,line);
        sm << line;
        while(sm >> keyword){
            mp_kw[keyword].push_back(id);
        }
        getline(cin,pub);
        mp_pub[pub].push_back(id);
        getline(cin,year);
        mp_year[year].push_back(id);

    }
    cin >> num_q;
    cin.ignore();
    while(num_q--){
        string q;
        getline(cin,q);
        char type = q[0];
        string to_q = q.substr(3,q.size()-3);
        cout << q << endl;
        switch(type){
        case '1':
            if(mp_title.count(to_q)){
                sort(mp_title[to_q].begin(),mp_title[to_q].end());
                for(int i = 0; i < mp_title[to_q].size(); i++){
                    cout << mp_title[to_q][i] << endl;
                }
            } else {
                cout << "Not Found\n";
            }
            break;
        case '2':
            if(mp_author.count(to_q)){
                sort(mp_author[to_q].begin(),mp_author[to_q].end());
                for(int i = 0; i < mp_author[to_q].size(); i++){
                    cout << mp_author[to_q][i] << endl;
                }
            } else {
                cout << "Not Found\n";
            }
            break;
        case '3':
            if(mp_kw.count(to_q)){
                sort(mp_kw[to_q].begin(),mp_kw[to_q].end());
                for(int i = 0; i <mp_kw[to_q].size(); i++){
                    cout << mp_kw[to_q][i] << endl;
                }
            } else {
                cout << "Not Found\n";
            }
            break;
        case '4':
            if(mp_pub.count(to_q)){
                sort(mp_pub[to_q].begin(),mp_pub[to_q].end());
                for(int i = 0; i < mp_pub[to_q].size(); i++){
                    cout << mp_pub[to_q][i] << endl;
                }
            } else {
                cout << "Not Found\n";
            }
            break;
        case '5':
            if(mp_year.count(to_q)){
                sort(mp_year[to_q].begin(),mp_year[to_q].end());
                for(int i = 0; i < mp_year[to_q].size(); i++){
                    cout << mp_year[to_q][i] << endl;
                }
            } else {
                cout << "Not Found\n";
            }
            break;

        }
    }
}
