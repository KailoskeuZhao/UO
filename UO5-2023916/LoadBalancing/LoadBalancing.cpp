#include <bits/stdc++.h>

using namespace std;
int main(){

    int x, y, n, dis1;

    freopen("balancing.in", "r", stdin);
    cin >> n >> dis1;
    vector<int> Xs, Ys;
    vector<pair<int, int>> XY;

    for(int m = 0; m < n; m++){
        cin >> x >> y;
        Ys.push_back(y);
        Xs.push_back(x);
        XY.push_back(make_pair(x,y));

    }
    
    sort(Xs.begin(), Xs.end());
    sort(Ys.begin(), Ys.end());

    int curr = 0;
    int loww = 100;
    int a = 0, b = 0, c = 0, d = 0;

    for(int m = 0; m < n; m++){
        x = Xs[m] +1;
        for(int k = 0; k < n; k++){
            y = Ys[k] + 1;

            for(int da = 0; da < XY.size(); da++){
                if(XY[da].first > x){
                    if(XY[da].second > y){
                        a++;
                    } else{
                        d++;
                    }
                } else{
                    if(XY[da].second > y){
                        b++;
                    } else{
                        c++;
                    }
                }
            }

            curr = max(max(a, b), max(c, d));
            if (curr < loww) loww = curr;
            a = 0;
            b = 0;
            c = 0;
            d = 0;
        }
    }

    freopen("balancing.out", "w", stdout);
    cout << loww << endl;

}