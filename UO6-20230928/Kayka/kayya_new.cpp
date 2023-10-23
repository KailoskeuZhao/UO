#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;
    int total_tandem = n - 1;
    vector<int> weights(2*n);
    for(int &l : weights){
        cin >> l;
    }

    sort(weights.begin(), weights.end());

    int opp = INT_MAX;
    vector<int> differs(n-1);
    for(int a = 0; a < weights.size()-1; a++){
        for(int p = a+1; p < weights.size(); p++){
        int curr = 0;
        vector<int> exclude_singles = weights;
        exclude_singles.erase(exclude_singles.begin()+a);
        exclude_singles.erase(exclude_singles.begin()+p - 1);
        for(int i = 1; i <= exclude_singles.size(); i += 2){
            differs[(i-1)/2] = exclude_singles[i] - exclude_singles[i-1];
        }

        sort(differs.begin(), differs.end());
        for(int j = 0; j < total_tandem; j++){
            curr += differs[j];
        }
        if(curr < opp) opp = curr;

        }
    }


  

    
    cout << opp << endl;
}