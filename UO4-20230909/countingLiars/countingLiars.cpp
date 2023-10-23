#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;

    vector<int> GT;
    vector<int> LT;

    int curr;
    int loww = INT32_MAX;

    for(int m = 0; m < n; m++){
        char a;
        int b;
        cin >> a >> b;
        if(a == 'G'){
            GT.push_back(b);
        } else {
            LT.push_back(b);
        }
    }

    for(int &a : GT){
        curr = 0;
        for(int &b : LT){
            if (b < a) curr++;
        }
        for(int &c : GT){
            if (c > a) curr++;
        }
        if (curr < loww) loww = curr;
    }

    cout << loww;
    
}