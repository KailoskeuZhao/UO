#include <bits/stdc++.h>

using namespace std;

bool abTest(int n, string a, string b){
    bool ifyes = true;
    for(char &t: a){
        for(char &l: b){
            if (t == l){ifyes = false;}
        }
    }
    return ifyes;

}

int main(){

    freopen("cownomics.in", "r", stdin);

    int n, m;
    cin >> n >> m;

    vector<string> sc(n), pc(n);

    for(string &s:sc){
        cin >> s;
    }

    for(string &s:pc){
        cin >> s;
    }

    
    bool ifyes = true;
    int ct = 0;
    string a, b;

    for(int k = 0; k < m; k++){
        a = "";
        b = "";
        
        for(int j = 0; j < n; j++){
        a = a + sc[j][k];
        b = b + pc[j][k];
        }
        ifyes = abTest(n, a, b);

        if(ifyes){ct++;}
        else{ifyes = true;}

    }

    freopen("cownomics.out", "w", stdout);

    cout << ct << endl;
}   