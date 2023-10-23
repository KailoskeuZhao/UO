#include <bits/stdc++.h>

using namespace std;

int main(){

    freopen("citystate.in", "r", stdin);
    int n;
    cin >> n;

    string in1, in2;
    unordered_map<string, string> da;
    for(int l = 0; l < n; l++){
        cin >> in1 >> in2;
        da[in1] = in2;
    }

    int index_a = 0, index_b = 0;
    string made_a, made_b;
    int maxx = 0;
    for(const pair<string, string> &a : da){
        index_b = 0;
        for(const pair<string, string> &b :da){
            if(index_b > index_a){
                made_a.push_back(a.first[0]);
                made_a.push_back(a.first[1]);
                made_b.push_back(b.first[0]);
                made_b.push_back(b.first[1]);

                if(made_a == b.second && made_b == a.second) maxx++; 
                made_a.clear();
                made_b.clear();
            }

            index_b++;
        }

        index_a++;
    }

    freopen("citystate.out", "w", stdout);
    cout << maxx << endl;
}