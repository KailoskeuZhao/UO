#include <bits/stdc++.h>

using namespace std;

int main(){

freopen("lifeguards.in", "r", stdin);
vector<pair<int,int>> d;

int n;
cin >> n;

int maxb = 0;

for(int m = 0; m < n; m++){
int a, b;
cin >> a >> b;
if(b > maxb){ maxb = b;}
d.push_back(make_pair(a,b));
}


int smaCons = 1000;
int nowCons = 0;
int curr = 0;
int starMan = 0;
int tcoved = 0;
bool duha;

maxb = min(maxb, 1000);

for(int m = 0; m < maxb +1; m++){
    for(int k = 0; k < n; k++){
        if(m == d[k].first){
            curr++;
        } else if (m == d[k].second){
            curr--;
        }
    }

    if(curr == 1){
        tcoved ++;
        nowCons++;
        duha = true;
    }


    if(curr > 1 || curr == 0){

        if(duha && nowCons < smaCons){
        smaCons = nowCons;
        }
        nowCons = 0;
        duha = false;
    }

      if(curr > 1){
        tcoved ++;
        duha = false;
    }

    

    }

    freopen("lifeguards.out", "w", stdout);

    cout << tcoved - smaCons << endl;
}