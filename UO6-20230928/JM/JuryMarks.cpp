#include <bits/stdc++.h>

using namespace std;

int main(){
int N, K;
cin >> K >> N;

long long tis;
long long curr = 0;
vector<long long> a_store(K);
for(int l = 0; l < K; l++) cin >> a_store[l];

unordered_set<long long> b_store;
unordered_set<long long> valid_bescore;
for(int l = 0; l < N; l++) {
    cin >> tis;
    b_store.insert(tis);
}

int index = 0;
for(const long long &a: b_store){
    if (index == 1) break;
    for(int n = K; n > 0; n--){
        unordered_set<long long> score_board;
        score_board = b_store;
        score_board.erase(a);
        long long fronta = a, backta = a;
        for(int l = n; l < K; l++){
            fronta += a_store[l];
            score_board.erase(fronta);
        }
        for(int p = n-1; p > 0; p--){
            backta -= a_store[p];
            score_board.erase(backta);
        }
        if(!score_board.size()){
            valid_bescore.insert((backta - a_store[0]));
        }
    }
    index++;
}

cout << valid_bescore.size() << endl;

}