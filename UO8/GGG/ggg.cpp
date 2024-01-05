/*
ID: a9816581
LANG: C++
TASK: gift1
*/

#include<bits/stdc++.h>

using namespace std;

int retNum(string sea, vector<pair<string, int>> d){
    for(pair<string, int> &a : d){
        if(sea == a.first){
            return a.second;
        }
    }
    
}

int main(){

    freopen("gift1.in", "r", stdin);
    int pep = 0;
    std::cin >> pep;

    vector<pair<string, int>> head(pep);

    string in1;

    for(int l = 0; l < pep; l++){
        cin >> in1;
        head[l].first = in1;
        head[l].second = l;
    }

    vector<int> mone(pep);
    for(int &a: mone) {a = 0;}

    int in2, in3;
    string in_name;
    string gimme;

    for(int l = 0; l < pep; l++){
        cin >> in_name;
        cin >> in2 >> in3;

        
        for(int p = 0; p < in3; p++){
            cin >> gimme;
            mone[retNum(gimme, head)] += (in2 / in3);
        }

        mone[retNum(in_name, head)] -= in2;
        if(in3){
        mone[retNum(in_name, head)] += (in2 % in3);
        }
    }

    freopen("gift1.out", "w", stdout);

    for(int l = 0; l < pep; l++){
        cout << head[l].first << " " << mone[l] << endl; 
    }


}