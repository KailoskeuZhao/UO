#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;
    int toca = n - 1;
    vector<int> weights(2*n);
    for(int &l : weights){
        cin >> l;
    }

    sort(weights.begin(), weights.end());
    vector<pair<int, int>> differs(2*n-1);

    for(int i = 1; i <= differs.size(); i++){
        differs[i-1].first = weights[i] - weights[i-1];
        differs[i-1].second = i-1;
    }

    sort(differs.begin(), differs.end());

    int opp = INT_MAX;
    for(int o = 0; o < differs.size(); o++){
        int full = 0;
        vector<int> tbo;
        int curr = 0;
        bool validi = true;
        for(int d = o; full < toca; d++){
            bool checked = true;

            if(d == differs.size()) {
                validi = false;
                break;
            }


            for(int &p : tbo){
                if(p == differs[d].second) {
                    checked = false;
                    break;
                }
            }
            
            if(checked){
                full++;
                curr += differs[d].first;
                tbo.push_back(differs[d].second + 1);
                tbo.push_back(differs[d].second - 1);
            }

        }

        if(validi){
        if (curr < opp) opp = curr;
        }

    }

  

    
    cout << opp << endl;
}