#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main(){
    freopen("shell.in", "r", stdin);
    

    int rd;
    cin >> rd;
    int sco = 0;
    int psco = 0;
    int now;

    for(int i = 1; i <= 3; i++){
        now = i;
    for(int n = 0; n < rd; n++){
        int a, b, c;
        cin >> a >> b >> c;
        array show = array<int, 3> {1, 2, 3};
        swap(show[a-1], show[b-1]);

    }
        if (sco>= psco) {psco = sco; sco = 0;} 
    }

    freopen("shell.out", "w", stdout);
    cout << psco;

}