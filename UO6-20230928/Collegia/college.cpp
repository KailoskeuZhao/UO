#include <bits/stdc++.h>

using namespace std;

int main(){

    int n;
    cin >> n;
    vector<int> as(n);
    for(int &a: as) cin >> a;

    sort(as.rbegin(), as.rend());

    long long maxx = 0, curr = 0;
    long long saved_tui;
    long long now_tui;
    for(int a = 0; a < as.size(); a++){
        now_tui = as[a];
        curr = now_tui*(a+1);
        if(curr > maxx) {
            maxx = curr;
            saved_tui = now_tui;
        } else if(curr == maxx){
            if(now_tui < saved_tui) saved_tui = now_tui;
        }
    }

    cout << maxx << " " << saved_tui << endl;


}