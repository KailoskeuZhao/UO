#include <bits/stdc++.h>

using namespace std;

int main(){

    freopen("swap.in", "r", stdin);

    long long N, K;
    cin >> N >> K;

    long long a1, a2, b1, b2;

    cin >> a1 >> a2 >> b1 >> b2;

    int op[N];

    freopen("swap.out", "w", stdout);
    for(long long l = 1; l <= N ; l++){
        vector<long long> sequenca;
        long long curr_pos = l;
        long long start_pos = l;
        while(true){
            if(curr_pos <= a2 && curr_pos >= a1){
                    curr_pos = a2 - curr_pos + a1;
            }
            if(curr_pos <= b2 && curr_pos >= b1){
                    curr_pos = b2 - curr_pos + b1;
            }
            
            sequenca.push_back(curr_pos);
            if(curr_pos == start_pos) break;
        }
        
        long long red;
        red = K % sequenca.size();
        if(red == 0) red = sequenca.size();
        op[(sequenca[red-1]-1)] = l ;
    }

    for(int &a : op) cout << a << endl;
}