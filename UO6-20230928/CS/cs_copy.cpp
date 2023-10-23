#include <bits/stdc++.h>

using namespace std;



int main(){

    freopen("citystate.in", "r", stdin);
    long long n;
    cin >> n;
    long long maxx = 0;

    string in1, in2, in3;
    string revo;
    unordered_map<string, long long> da;
    for(long long l = 0; l < n; l++){
        cin >> in1 >> in2;
        if(in1.substr(0,2) != in2){
        in3 = in1.substr(0,2) + in2;
        if(da.count(in3) == 0) da[in3] = 0;
        da[in3] += 1;
        }
    }

    for(const pair<string, long long> &a :da){
        revo = a.first.substr(2,4) + a.first.substr(0,2);
        if(da.count(revo) != 0){
            maxx += a.second * da[revo];
            da[a.first] = 0;
            da[revo] = 0;
        }
    }
 
    freopen("citystate.out", "w", stdout);
    cout << maxx << endl;
}