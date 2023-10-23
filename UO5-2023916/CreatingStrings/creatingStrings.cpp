#include <bits/stdc++.h>

using namespace std;

int sta1[26]{0};
int n;
char togo;
vector<string> tout;


void solve(int at, const string op){
    if (at == n) {tout.push_back(op);
    return;
    }
    

    for(int j = 0; j < 26; j++){
        if (sta1[j] > 0) {
            sta1[j] --;
            solve(at + 1, op + (char)('a' + j));
            sta1[j] ++;
        }

    }
}

int main(){

    char ch;
    string inn;
    cin >> inn;
    n = inn.size();
    for(int j = 0; j < n; j++){
        ch = inn[j];
        sta1[ch-'a']++;
    }

    solve(0, "");
    cout<< tout.size() << endl;
    for(string &u: tout){
        cout << u << endl;
    }



}