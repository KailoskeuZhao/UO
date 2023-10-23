#include <bits/stdc++.h>

using namespace std;



int main(){
    int n;

    freopen("triangles.in", "r", stdin);
    cin >> n;

    int a, b;
    
    
    vector<vector<int>> das(n);


    for(int m = 0; m < n; m++){
        cin >> a >> b;
    das[m].push_back(a);
    das[m].push_back(b);
    }

    int outp = 0;
    int width;
    int height;

    for(int m = 0; m < n; m++){
        for(int l = m; l < n; l++){
            width = max(das[l][0] - das[m][0], das[m][0] - das[l][0]);
            height = max(das[l][1] - das[m][1], das[m][1] - das[l][1]);
            if(width * height > outp) outp = width*height;
        }
    }

    freopen("triangles.out", "w", stdout);
    cout << outp << endl;

}