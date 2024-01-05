#include <bits/stdc++.h>

using namespace std;

int main(){
    string a;
    int N;
    cin >> N >> a;
    bool searchas = true;

    vector<int> nums;

    for(char &aa :a){
        if(aa == 'H') nums.push_back(0);
        if(aa == 'G') nums.push_back(1);
    }

    
}