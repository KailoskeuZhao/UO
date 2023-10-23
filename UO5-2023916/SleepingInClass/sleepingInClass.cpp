#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> modif(vector<vector<int>> da){
    int curr = 0;
    vector<vector<int>> newDa;
    for(int s = 0; s < da.size(); s++){
        for(int k = 0; k < (da[s].size() - 1); k++){
            newDa.push_back({});
            for(int l = 0; l < da[s].size(); l++){

                if(l == (k+1)){}
                else if(l == k){newDa[curr].push_back((da[s][k]+da[s][k+1]));}
                else {newDa[curr].push_back(da[s][l]);}
                
            }
            curr++;
        }
    }

    return newDa;
}

bool check(vector<vector<int>> d){
    bool yes = true;
    for(vector<int> &t: d){
        for(int &a: t){
            if (a != t[0]) yes = false;
        }
        if (yes) return true;
        yes = true;
    }

   
}

int solve(){
    int n, a;
    cin >> n;
    vector<vector<int>> da;
    da.push_back({});
    for(int l = 0; l < n; l++){
        cin >> a;
        da[0].push_back(a);
    }

    bool checked = false;
    int min = 0;

    for(int k = 0; k < n; k++){
        
        checked = check(da);
        if (checked) {
            min = k;
            break; }
        da = modif(da);
    }

    return min;
}

int main(){
    int t;
    cin >> t;
    for(int m = 0; m < t; m++){
        cout << solve() << endl; 
    }
  
}