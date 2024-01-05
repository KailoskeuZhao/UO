#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main(){

    freopen("outofplace.in", "r", stdin);
    int N;
    cin >> N;

    int sto[N];

    for(int n = 0; n < N; n++){
        cin >> sto[n];
    }

    vector<pair<int, int>> firstplaces;

    int curr = -1;

    int index = 0;
    int num = 0;
    for(int &a : sto){
        if (a != curr){
            firstplaces.push_back(make_pair(num, a));
            num++;
            curr = a;
        }
        index++;
    }

    int BH = -1;
    bool found = false;

   if(sto[0] > sto[1]) BH = sto[0];
   else if (sto[N-1] < sto[N-2]) BH = sto[N-1];
   else{
    for(int a = 1; a < N-1; a++){
        if( (sto[a] > sto[a-1]) && (sto[a] > sto[a+1])){
            BH = sto[a];
            break;
        } else if( (sto[a] < sto[a-1]) && (sto[a] < sto[a+1])){
            BH = sto[a];
            break;
        }
    }
   }

    index = 0;
    int thisloc;
    int reqloc;

    int op;

    
    for(pair<int, int> &a : firstplaces){
        if (a.second == BH){
            thisloc = a.first;
        }
    }
   
    if(BH < firstplaces[0].second) op = thisloc;
    else if(BH > firstplaces[firstplaces.size()-1].second) op = ((firstplaces.size() - 1) - thisloc);
    else{
        for(int a = 0; a < firstplaces.size()-1; a++){
            if(BH >= firstplaces[a].second && BH <= firstplaces[a+1].second){
                if(thisloc > a) {reqloc = a+1;}
                else {reqloc = a;}
                break;
            }
        }

        op = abs(reqloc - thisloc);
    }

    freopen("outofplace.out", "w", stdout);
    cout << op << endl;

    

}