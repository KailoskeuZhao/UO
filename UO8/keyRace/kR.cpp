#include<bits/stdc++.h>

using namespace std;

int main(){
    int s, v1, v2, t1, t2;

    cin >> s >> v1 >> v2 >> t1 >> t2;

    int ft1 = 0, ft2 = 0;

    ft1 = 2 * t1 + (v1 * s);
    ft2 = 2 * t2 + (v2 * s);

    if(ft1 < ft2){
        cout << "First";
    } else if (ft1 == ft2){
        cout << "Friendship";
    } else{
        cout << "Second";
    }
}