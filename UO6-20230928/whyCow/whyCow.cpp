#include <bits/stdc++.h>

using namespace std;

int main(){
    freopen("cowqueue.in", "r", stdin);
    int n;
    cin >> n;
    vector<pair<long, long>> da(n);

    for(pair<long, long> & a: da){
        cin >> a.first >> a.second;
    }

    sort(da.begin(), da.end());

    long long now_time = 0;

    for(pair<long, long> &ui: da){
        if(now_time < ui.first){
            now_time = ui.first + ui.second;
        } else{
            now_time += ui.second;
        }
    }

    freopen("cowqueue.out", "w", stdout);
    cout << now_time << endl;
}