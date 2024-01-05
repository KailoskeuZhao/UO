#include <bits/stdc++.h>

using namespace std;

int main(){

long long N, K;
cin >> N >> K;
long long da[N];

long long tt = 0;

for(int l = 0; l < N; l++){
    cin >> da[l];
}

if(N > 1){
    long long sec;
    for (long long l = 1; l < N; l++){
        sec = da[l] - da[l-1];
    if(sec < K+1) tt += sec;
    else tt += K+1;
    }
}

    

tt += (K+1);

cout << tt;

}