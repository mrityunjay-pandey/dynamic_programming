#include<iostream>
#include<bits/stdc++.h>
// #include<algorithm>
using namespace std;

int med(string s1, string s2, int i, int j){
    if(i==s1.size()){ return s2.size()-j;}
    if(j==s2.size()){return s1.size()-i;}

    if(s1[i] == s2[j]) return med(s1,s2,i+1,j+1);
    else{
        int x = med(s1,s2,i,j+1);       // Insert
        int y = med(s1,s2,i+1,j+1);    // Update
        int z = med(s1,s2,i+1,j);     // Delete
        return 1 + min(x,min(y,z));
    }
}



int meddp(string s1, string s2, vector<vector<int>> &dp){
    dp[0][0] = 0;
    int m = s1.size();
    int n = s2.size();
    cout<<m<<" "<<n<<endl;
    for(int i=1; i<=n; i++){
        dp[0][i] = i;
    }
    for(int i=1; i<=m; i++){
        dp[i][0] = i;
    }
    for(int i=1; i<=m; i++){
        for(int j=1; j<=n; j++){
            if(s1[i] == s2[j]){
                dp[i][j] = dp[i-1][j-1];
            }else{
                dp[i][j] = 1+min(dp[i-1][j], min(dp[i][j-1], dp[i-1][j-1]));
            }
        }
    }
    // for(int i=0; i<=m; )
    return dp[m][n];
}

int main(){
    string s1 = "SATURDAY";
    string s2 = "SUNDAY";
    int m = s1.size();
    int n = s2.size();
    vector<vector<int>>dp(m+1, vector<int>(n+1,-1));
    // int ans = med(s1,s2,0,0);
    // cout<<ans;
    int ans = meddp(s1,s2,dp);
    cout<<ans;
    return 0;
}