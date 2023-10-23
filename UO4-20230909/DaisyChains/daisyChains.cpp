#include <bits/stdc++.h>

using namespace std;

int main(){
    int n = 0;
    cin >> n;
    
    int da[n];

    for(int m = 0; m < n; m++){
        cin >> da[m];
    }

    int to_po = 0;

    for(int m = 0; m < n; m++){
        for(int k  = m; k < n; k++){
            
            double avg = 0;

            for(int j = m; j <= k; j++){
                avg += da[j];
            }
            avg = avg/((k-m)+1);

            for(int j = m; j <= k; j++){

            if (avg == da[j]){ to_po++;
            break;}

            }

         

        }
    }

    cout << to_po << endl;
}