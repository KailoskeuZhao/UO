#include <bits/stdc++.h>



using namespace std;

int main(){
    freopen("race.in", "r", stdin);
#define int long long    
int K, N, X, O;

    freopen("race.out", "w", stdout);
    cin >> K >> N;

    int tt;

    for(int n = 0; n < N; n++){
        cin >> X;
        
        int minn = INT_MAX;
        int mount, down;

        for(int l = 1; l < INT_MAX; l++){
            tt = 0;
            mount = 0;
            mount += ( ((1+l)*l) ) / 2;
            tt += l;
            
            if(l > X){
            mount += ((l-X) * (l - 1 + X))/2;
            tt += (l - X);
            }
            
            if((mount - X) > K) break;
            
            if(mount < K){
            tt += (K - mount) / l;
            if((K - mount) % l > 0) tt++;
            }

            if(tt < minn) minn = tt;
            
        }

        cout << minn << endl;

    }


}