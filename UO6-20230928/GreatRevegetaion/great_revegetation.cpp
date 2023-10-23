#include <bits/stdc++.h>

using namespace std;

int main(){

freopen("revegetate.in", "r", stdin);
int N, M;
cin >> N >> M;

int op[N];
vector<set<int>> av_grass_type(N);
for(set<int> &a : av_grass_type){
    a.insert({1, 2, 3, 4});
}

vector<vector<int>> da(N);

int ina, inb;
for(int l = 0; l < M; l++){
    cin >> ina >> inb;
    da[ina-1].push_back(inb-1);
    da[inb-1].push_back(ina-1);
}

int this_grass_type = -1;
int index = 0;
for(vector<int> a : da){
    for(const int &a : av_grass_type[index]){
        this_grass_type = a;
        break;
    }
    op[index] = this_grass_type;
    for(int &a : da[index]){
        av_grass_type[a].erase(this_grass_type);
    }
    index++;
}

freopen("revegetate.out", "w", stdout);
for(int &a : op){
    cout << a;
}

cout << endl;

}