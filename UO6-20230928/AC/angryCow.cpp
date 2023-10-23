#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(){
    freopen("angry.in", "r", stdin);
    int n;
    cin >> n;
    vector<ll> da(n);
    for(int h = 0; h < n; h++) cin >> da[h];
    sort(da.begin(), da.end());

    int maxx = 1;
    
    for(int index = 0; index < n - 1; index++){
        ll lb = 0;
        ll ub = 0;
        ll lbr = 1, rbr = 2;
        ll boomba = 0;
        if(da[index+1] == (da[index] + 1)){
            boomba += 2;
            lb = da[index] - lbr;
            ub = da[index+1] + rbr;
            for(int left_through = index - 1; left_through >= 0; left_through--){
                if (da[left_through] >= lb){
                    boomba++;
                    if(da[left_through-1] < lb){
                    lbr++;
                    lb = (da[left_through] - lbr);
                    }
                } else{
                    break;
                }
      
            }
            for(int right_through = index + 2; right_through < da.size(); right_through++){
                if(da[right_through] <= ub){
                    boomba++;
                    if(da[right_through+1] > ub){
                    rbr++;
                    ub = (da[right_through] + rbr);
                    }
                } else{
                    break;
                }

            }
        }

        if (boomba > maxx) maxx = boomba;
    }

    freopen("angry.out", "w", stdout);

    cout << maxx << endl;
    
}