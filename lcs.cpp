#include<iostream>
#include<vector>
using namespace std;

int lcs_length(string s1, string s2, int i, int j){
        if(i>=s1.size() || j>=s2.size()) return 0;
        if(s1[i] == s2[j]){
            return 1 + lcs_length(s1,s2,i+1,j+1);
        }else{
            int x = lcs_length(s1,s2,i,j+1);
            int y = lcs_length(s1,s2,i+1,j);
            return max(x,y);
        }
    }

    int lcsdp(string s1, string s2, int i, int j, vector<vector<int>>& dp){
        int n = s1.size();
        int m = s2.size();
        dp[0][0] = 0;
        for(int i=1;i<=n;i++){
            dp[i][0] = 0;
        }
        for(int i=1;i<=m;i++){
            dp[0][i] = 0;
        }
        for(int i=1;i<=n;i++){
            for(int j=1; j<=m;j++){
                if(s1[i-1] == s2[j-1]){
                    dp[i][j] = 1+dp[i-1][j-1];
                    cout<<1;
                }else{
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                    cout<<0;
                }
            }
        }
        // for(int i=0;i<=n;i++){
        //     for(int j=0;j<=m; j++){
        //         cout<<dp[i][j]<<" ";
        //     }
        //     cout<<"\n";
        // }
        return dp[n][m];
    }

int main(){
    string s1,s2;
    cin>>s1>>s2;
    cout<<lcs_length(s1,s2,0,0);
    return 0;
}