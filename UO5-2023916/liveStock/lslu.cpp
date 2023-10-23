#include<bits/stdc++.h>
using namespace std;

bool ifyes(vector<string> sto, vector<pair<string, string>> req){
    
    for(int a = 0; a < sto.size(); a++){
        if(sto[a] == "Beatrice"){
            
        }
        for(pair<string, string> &p: req){
            if(p.first == sto[a]){
                if(sto[a+1] == p.second || sto[a-1] == p.second){}
                else return false;
            }
        }
    }

    return true;
} 

int ditor(vector<pair<string,int>> ditorder, string inn){
    for(pair<string, int> &a: ditorder){
        if(inn == a.first) return a.second;
    }
    
    return -1;
}


int main(){
    vector<string> sto{"Bessie", "Buttercup", "Belinda", "Beatrice", "Bella", "Blue", "Betsy", "Sue"};
    vector<string> solve{"Bessie", "Buttercup", "Belinda", "Beatrice", "Bella", "Blue", "Betsy", "Sue"};
    vector<string> fedin{"Beatrice", "Belinda", "Bella", "Bessie", "Betsy", "Blue", "Buttercup", "Sue"};
    vector<pair<string, int>> ditorder(8);

    freopen("lineup.in", "r", stdin);

    for(int m = 0; m < 8; m++){
        ditorder[m] = make_pair(fedin[m], m);
    }

    int n;
    cin >> n;
    string nouse1;
    string a, b;
    vector<pair<string, string>> req(n);
    for(int l = 0; l < n; l++){
        cin >> a >> nouse1 >> nouse1 >> nouse1 >> nouse1 >> b;
        req[l] = make_pair(a, b);
    }

    bool ifye = true;

    do{
        
        ifye = ifyes(fedin, req);

        if(ifye){
            if(ditor(ditorder, fedin[0]) < ditor(ditorder,solve[0])){
                solve = fedin;
            } else if(ditor(ditorder, fedin[0]) == ditor(ditorder,solve[0])){
                if(ditor(ditorder, fedin[1]) < ditor(ditorder,solve[1])){
                    solve = fedin;
                }
            }
        }
    }while(next_permutation(fedin.begin(), fedin.end()));

    freopen("lineup.out", "w", stdout);

    for(string &a : solve){
        cout << a << endl;
    }
}