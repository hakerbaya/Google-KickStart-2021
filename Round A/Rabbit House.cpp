#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    for (int tc = 1; tc <= t; tc++){
        int r,c;
        cin >> r >> c;
        vector<vector<int>> grid(r+1, vector<int>(c+1));

        int newh = 0;
        
        for (int rcnt = 0; rcnt < r; ++rcnt){
            for (int ccnt = 0; ccnt < c; ++ccnt){
               int height;
               cin >> height;
               grid[rcnt][ccnt] = height;
               newh = max(newh, height);
            }
        }
        vector<set<pair<int, int>>> setHeight(newh+1);
        for (int rcnt = 0; rcnt < r; ++rcnt){
            for (int ccnt = 0; ccnt < c; ++ccnt){
               setHeight[grid[rcnt][ccnt]].insert(make_pair(rcnt, ccnt));
            }
        }
        long long ans = 0;
        int rMoves[4] = {0,0,1,-1};
        int cMoves[4] = {1,-1,0,0};

        while (newh > 0){
            for (auto it = setHeight[newh].begin(); it != setHeight[newh].end(); ++it){
                for (int i = 0; i < 4; ++i){
                    int new_row = (*it).first + rMoves[i];
                    int new_col = (*it).second + cMoves[i];
                    if (new_row >= 0 && new_col >= 0 && new_row < r && new_col < c) {
                        int newHeight = grid[new_row][new_col];
                        if (newHeight < newh){
                            auto remove_find = setHeight[newHeight].find(make_pair(new_row, new_col));
                            setHeight[newHeight].erase(remove_find);
                            ans += (long long)(newh - newHeight - 1);
                            setHeight[newh - 1].insert(make_pair(new_row, new_col));
                            grid[new_row][new_col] = newh - 1;
                        }
                    }
                }
            }
            newh -= 1;
        }
        cout << "Case #" << tc << ": " << ans << endl;
    }
    
} 