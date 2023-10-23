#include <bits/stdc++.h>

using namespace std;

int main(){
    freopen("notlast.in", "r", stdin);
    int n;
    cin >> n;
    unordered_map<string, int> da{
        {"Bessie", 0},
        {"Elsie", 0},
        {"Gertie", 0},
        {"Daisy", 0},
        {"Annabelle", 0},
        {"Henrietta", 0},
        {"Maggie", 0}
    };

    string in1;
    int in2;

    string ou;
    for(int f = 0; f < n; f++){
        cin >> in1 >> in2;
        da[in1] += in2;
    }

    map<int, string> reversa;
    for(const pair<string, int> &a: da){
        if(reversa[a.second] != ""){ reversa[a.second] = "Tie";
        } else reversa[a.second] = a.first;
    }

    freopen("notlast.out", "w", stdout);

    if(reversa.size() == 1) cout << "Tie" << endl; 
    else {
        int ci = 0;
        for(const pair<int, string> &a : reversa){
            if(ci == 1){
                ou = a.second;
                break;
            }
            ci++;
        }
        cout << ou << endl;
    }
    
}