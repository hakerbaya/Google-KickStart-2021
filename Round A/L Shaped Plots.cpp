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
        int ans = 0;
        vector<vector<int>> up(r+1, vector<int>(c+1, 0));
        vector<vector<int>> down(r+1, vector<int>(c+1, 0));
        vector<vector<int>> left(r+1, vector<int>(c+1, 0));
        vector<vector<int>> right(r+1, vector<int>(c+1, 0));
        vector<vector<int>> grid(r+1, vector<int>(c+1));

        for (int rc = 0; rc < r; ++rc){
            for (int cc = 0; cc < c; ++cc){
               cin >> grid[rc][cc]; 
            }
        }

        for (int row = 0; row < r; ++row){
            int count = 0;
            int i = 0;
            while (i <= c){
                if (i == c || grid[row][i] == 0){
                    int temp_i = i - count;
                    int start = 1;
                    while (temp_i < i) {
                        right[row][temp_i] = count;
                        left[row][temp_i] = start;
                        count -= 1;
                        temp_i += 1;
                        start += 1;
                    }
                    count = 0;
                }
                else {
                    count++;
                }
                i++;
            }
        }

        for (int col = 0; col < c; ++col){
            int count = 0;
            int i = 0;
            while (i <= r){
                if (i == r || grid[i][col] == 0){
                    int temp_i = i - count;
                    int start = 1;
                    while (temp_i < i) {
                        down[temp_i][col] = count;
                        up[temp_i][col] = start;
                        count -= 1;
                        temp_i += 1;
                        start += 1;
                    }
                    count = 0;
                }
                else {
                    count++;
                }
                i++;
            }
        }
        
        for (int rc = 0; rc < r; ++rc){
            for (int cc = 0; cc < c; ++cc){
                if (grid[rc][cc] == 0){
                    continue;
                }
                ans += min(max(0, up[rc][cc]/2 - 1), left[rc][cc]-1);
                ans += min(max(0, left[rc][cc]/2 - 1), up[rc][cc]-1);

                ans += min(max(0, up[rc][cc]/2 - 1), right[rc][cc]-1);
                ans += min(max(0, right[rc][cc]/2 - 1), up[rc][cc]-1);

                ans += min(max(0, down[rc][cc]/2 - 1), left[rc][cc]-1);
                ans += min(max(0, left[rc][cc]/2 - 1), down[rc][cc]-1);

                ans += min(max(0, down[rc][cc]/2 - 1), right[rc][cc]-1);
                ans += min(max(0, right[rc][cc]/2 - 1), down[rc][cc]-1);
            }
        }
        cout << "Case #" << tc << ": " << ans << "\n";
    }
    
} 