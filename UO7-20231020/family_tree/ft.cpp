#include <bits/stdc++.h>

using namespace std;

int main(){
freopen("family.in", "r", stdin);
map<string, string> mother_edge;
int N;
string a, b;
cin >> N >> a >> b;


string in1, in2;
for(int n = 0; n < N; n++){
    cin >> in1 >> in2;
    mother_edge[in2] = in1;
}

int m_or = 0;
string tis = a;
string up_nex;

vector<pair<int, string>> direct_tree;

while(true){
    direct_tree.push_back(make_pair(m_or, tis));
    if(!mother_edge.count(tis)) break;
    up_nex = mother_edge[tis];
    tis = up_nex;
    m_or++;
}

sort(direct_tree.begin(), direct_tree.end());

freopen("family.out", "w", stdout);

for(pair<int, string> &k : direct_tree){
    if(k.second == b){
        if(k.first < 2){
            cout << b << " is the mother of " << a;
        } else if (k.first < 3){
            cout << b << " is the grand-mother of " << a;
        } else {
            cout << b << " is the ";
            for(int l = 2; l < k.first; l++) cout << "great-";
            cout << "grand-mother of " << a;
        }
        return 0;
    }
}

map<string, int> directs;
for(pair<int, string> &j: direct_tree) {
directs[j.second] = j.first;
}

if(directs.count((mother_edge[b]))){
    if(directs[mother_edge[b]] < 2) cout << "SIBLINGS";
    else if(directs[mother_edge[b]] < 3) cout << b << " is the aunt of " << a;
    else {
        cout << b << " is the ";
        for(int l = 2; l < directs[mother_edge[b]]; l++){
            cout << "great-";
        }
        cout << "aunt of " << a;
    }
    return 0;
}

tis = b;
while(true){
    if(mother_edge.count(tis)){
        if(directs.count(mother_edge[tis])) {
            cout << "COUSINS";
            return 0;
            break;
        }
        tis = mother_edge[tis];
    } else {
        cout << "NOT RELATED";
        return 0;
    }    
}
}