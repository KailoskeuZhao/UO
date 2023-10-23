#include <bits/stdc++.h>

using namespace std;

vector<int> fb(10);
vector<int> sb(10);

vector<int> pos_ans;

void solve(int index, vector<int> curr_fb, vector<int> curr_sb, int currm_fb, int currm_sb){
    
    vector<int> passon_fb, passon_sb;
    int this_fb, this_sb;
    int currl;

    if(index == 4){
        currl = currm_fb;
        bool uni = true;
        for(int &a : pos_ans){
            if (a == currl) uni = false;
        }

        if(uni) pos_ans.push_back(currl);
        return;
    }
    else if((index%2) == 0){
    
    for(int a = 0; a < curr_fb.size(); a++){
        this_fb = curr_fb[a];
        passon_fb = curr_fb;
        passon_fb.erase(passon_fb.begin() + a);
        passon_sb = curr_sb;
        passon_sb.push_back(this_fb);
        solve(index+1, passon_fb, passon_sb, (currm_fb - this_fb), (currm_sb + this_fb));
    }

    } else {

    for(int a = 0; a < curr_sb.size(); a++){
        this_sb = curr_sb[a];
        passon_sb = curr_sb;
        passon_sb.erase(passon_sb.begin() + a);
        passon_fb = curr_fb;
        passon_fb.push_back(this_sb);
        solve(index+1, passon_fb, passon_sb, (currm_fb + this_sb), (currm_sb - this_sb));
    }

    }
    
}



int main(){

    freopen("backforth.in", "r", stdin);
    for(int n = 0; n < 10; n++){
        cin >> fb[n];
    }
    for(int n = 0; n < 10; n++){
        cin >> sb[n];
    }

    solve(0, fb, sb, 0, 0);

    /*

    sort(pos_ans.begin(), pos_ans.end());

    int op = 1;
    int thiss, after;
    after = -1;

    for(int i = 0; i < pos_ans.size(); i++){
        thiss = pos_ans[i];
        if(after != -1&& thiss != after){
            op++;
        }
        after = pos_ans[i];
    }

    */
    freopen("backforth.out", "w", stdout);
    //vector<int> d = pos_ans;

    

    cout << pos_ans.size() << endl;

}