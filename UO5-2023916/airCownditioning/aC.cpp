#include<bits/stdc++.h>
using namespace std;

struct Cow{
    int si;
    int ti;
    int ci;
};

struct AC{
    int ai;
    int bi;
    int pi;
    int mi;
    bool on = false;
};

int n, m;
int minn = INT_MAX;
vector<Cow> C;
vector<AC> A;

vector<int> req(101, 0);
vector<int> has(101, 0);

void solve(int index, int curr, bool turn){
    
    if(index >= 0) A[index].on = turn;
    if(index == m){
        bool covered = true;

        for(AC &a : A){
            if (a.on){
                for(int m = a.ai; m <= a.bi; m++) has[m] += a.pi;
                curr += a.mi;
            }
        }

        for(int m = 1; m <= 100; m++){
            if(req[m] > has[m]) covered = false;
        }

        for(AC &a : A){
            if (a.on){
                for(int m = a.ai; m <= a.bi; m++) has[m] -= a.pi;
            }
        }

    

        if(covered){
        if(curr < minn) minn = curr;
        }
        return;
    }

    solve(index+1, curr, true);
    solve(index+1, curr, false);
}

int main(){
cin >> n >> m;
C.resize(n);
A.resize(m);
for(int m = 0; m < n; m++) {
    cin >> C[m].si >> C[m].ti >> C[m].ci;
}
for(int j = 0; j < m; j++){
    cin >> A[j].ai >> A[j].bi >> A[j].pi >> A[j].mi;
}

for(int k = 0; k < C.size(); k++){
    for(int j = C[k].si; j <= C[k].ti; j++){
        req[j] += C[k].ci;
    }
}
    solve(-1, 0, false);
    cout << minn << endl;
}