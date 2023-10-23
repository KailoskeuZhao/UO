#include<bits/stdc++.h>

using namespace std;

int main(){
    freopen("pails.in", "r", stdin);

    int da[3];
    int cm = 0;
    int maxx = 0;


    cin >> da[0] >> da[1] >> da[2];

    for(int n = 0; n < 500; n++){
        for(int k = 0; k < 500; k++){
            cm = n*da[0] + k*da[1];
            if(cm > da[2]) break;
            if(cm > maxx) maxx = cm;
            
        }
    }

    freopen("pails.out", "w", stdout);

    cout << maxx << endl;
}