#include <bits/stdc++.h>

struct rect{
    int x1 = 0, y1 = 0, x2 = 0, y2 = 0;
    int width = 0;
    int height = 0;
    void calwidth(){width = x2-x1;}
    void calheighth(){height = y2-y1;}
};

void solve(){
    int wh[2];
    rect ft, st;
    std::cin >> wh[0] >> wh[1];
    std::cin >> ft.x1 >> ft.y1 >> ft.x2 >> ft.y2;
    ft.calheighth();  ft.calwidth();
    std::cin >> st.width >> st.height;

    bool solving = true;

    int pos = 0;
    if(st.width > (wh[0] - ft.width)) pos++;
    if(st.height > (wh[1] - ft.height)) pos++;
    if(pos == 2 || (st.height > wh[1] || st.width > wh[0])) 
    {   solving = false;
        std::cout << -1 << std::endl;
    }

    if(solving){
        std::vector<int> steps(4);
        for(int &a:steps){
            a = 2 * 1000000000;
        }

        if(wh[1] - ft.height >= st.height){
        int tTb = std::max((st.height - (wh[1] - ft.y2)), 0);
        steps[0] = tTb;
    
        int bTb = std::max((st.height - ft.y1), 0);
        steps[1] = bTb;
        }

        if(wh[0] - ft.width >= st.width){
        int rTb = std::max(st.width-(wh[0] - ft.x2), 0);
        steps[2] = rTb;

        int lTb = std::max((st.width- ft.x1), 0);
        steps[3] = lTb;
        }

        std::sort(steps.begin(), steps.end());
        std::cout << steps[0] << std::endl;
        
    }

   
}

main(){
    int t = 0;
    std::cin >> t;

    for(int n = 0; n < t; n++) solve();

}