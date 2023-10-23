#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main(){
    

    freopen("word.in", "r", stdin);
    freopen("word.out", "w", stdout);

    int a,b;
    cin >> a >> b;

    int llo = 0;
    for (int i = 0; i < a; i++){
        string o;
        cin >> o;
        llo += o.length();
        if (llo > b){
            cout << "\n" << o;
            llo = o.length();
        } else {
            if (i == 0){
                cout << o;
            } else {
            cout << " " << o;
            }

        }
    }
    
    return 0;
    }