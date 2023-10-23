#include <bits/stdc++.h>

using namespace std;

int main(){

freopen("planting.in", "r", stdin);
int n;
cin >> n;
vector<unordered_set<int>> node_map(n);

int maxx = 0;
int a, b;
for(int l = 0; l < (n-1); l++){
    cin >> a >> b;
    node_map[a-1].insert(b-1);
    node_map[b-1].insert(a-1);

}

for(int l = 0; l < n; l++){
    a = node_map[l].size() + 1;
    if(a > maxx) maxx = a;
}

freopen("planting.out", "w", stdout);

cout << maxx << endl;
}