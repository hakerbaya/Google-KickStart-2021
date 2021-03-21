
#include <bits/stdc++.h>
using namespace std;

#define ll long long
int main(){
     ios_base::sync_with_stdio(false);
     cin.tie(NULL);
     
     int t; cin >> t;
     for(int tc = 1;tc <=t;tc++){
         ll ans = 0,cnt=0;
         ll len,K;cin >> len >> K;
         string s; cin >> s;

         for(ll i=0;i<len/2;i++){
             if(s[i]!=s[(len-1)-i]){
                 cout << s[i] <<" "<<s[(len-1)-i] <<"\n";
                 cnt++;
             } else{
                 cout << s[i] <<" "<<s[(len-1)-i] <<"\n";
             }
         }
         if(cnt>= K){
             ans = 0;
         } else{
             ans = K-cnt;
         }
         cout << "Case #"<<tc<<": "<<ans<<"\n";
    }
}
