#include <bits/stdc++.h>

using namespace std;


int main(){

    int n;

    cin >> n;

    long day[n][2];

    for(int m = 0; m < n; m++){
        cin >> day[m][0];
    }
    
    for(int m = 0; m < n; m++ ){
        cin >> day[m][1];
    }

    long max = 0;
    long re1 = 0;

    for(int m = 0; m < n; m++){
        for(int k = m+1; k< n; k++){
            re1 = pow(day[k][0] - day[m][0], 2) + pow(day[k][1] - day[m][1], 2);
            if (re1 > max) max = re1;
        }
    }

    cout << max << endl;
    
 

}