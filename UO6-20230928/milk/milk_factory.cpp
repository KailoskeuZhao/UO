#include <bits/stdc++.h>

using namespace std;

int main(){

freopen("factory.in", "r", stdin);
int N;
cin >> N;
int req = N-1;

vector<unordered_set<int>> da(N);

int in1, in2;
for(unordered_set<int> a: da){
    cin >> in1 >> in2;
    da[in1-1].insert(in2-1);
}

int index = 0;
int op = -1;
bool failed = false;

freopen("factory.out", "w", stdout);

for(unordered_set<int> a: da){
    if(a.size() > 1){
        cout << -1 << endl;
        failed = true;
        break;
    }
    else if(a.size() == 0){
        op = index +1;
    }
    index++;
}

if(!failed){
    cout << op << endl;
}


}