#include <bits/stdc++.h>

using namespace std;

struct chain{
    int start = -1;
    int finish;
};

int main(){
    int N, Q;
    cin >> N >> Q;

    map<int, int> da;
    unordered_map<int, chain> da1;
    vector<int> dada;

    int now;

    for(int n = 0; n < N; n++){
        cin >> now;
        dada.push_back(now);
        da[now] ++;
        if(da1[now].start == -1)da1[now].start = n;
        da1[now].finish = n;
    }

    int summa = 0;
    int summa_rb_dec = 0;


    while(dada.size() > 0){
        int curr = 0;
        set<int> chain_groups;
        int rb = da1[dada[0]].finish - summa_rb_dec;
        chain_groups.insert(dada[0]);
        for(int l = 0; l <= rb; l++){
            if(dada[l] != dada[0]){
                chain_groups.insert(dada[l]);
                if((da1[dada[l]].finish - summa_rb_dec) > rb ) rb = da1[dada[l]].finish - summa_rb_dec;
            }
        }
        int maxx = 0;
        int chain_sum = 0;

        if(chain_groups.size() != 1){

            for(const int &a: chain_groups){
                chain_sum += da[a];
                if(da[a] > maxx) maxx = da[a];
            }
            curr = chain_sum - maxx;
            summa += curr;

        }
        
        dada.erase(dada.begin(), dada.begin() + (rb+1));
        summa_rb_dec += rb+1;
    }

    cout << summa;
}