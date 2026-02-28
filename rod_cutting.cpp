#include<iostream>
#include<vector>
using namespace std;

int maxProfit(int n, vector<int>&price){
    int maxP=INT_MIN;
    if(n==0) return 0;
    if(n==1) return price[0];
    for(int i=1; i<n; i++){
        int p = maxProfit(i,price) + maxProfit(n-i, price);
        maxP = max(maxP, p);
    }
    return maxP;
}

int maxProfitDp(int n, vector<int>& price, vector<int>& dp){
    dp[0] = 0;
    dp[1] = price[0];
    for(int i=2; i<=n; i++){
        int p=INT_MIN;
        for(int k=1; k<i; k++){
            int x = price[k] + price[i-k];
            p = max(p,x);
        }
        dp[i] = p;
    }
    return dp[n];
}

int main(){
    int n;
    cin>>n;
    vector<int>price(n,0);
    for(int i=0; i<n; i++){
        cin>>price[i];
    }
    // cout<<maxProfit(n, price);
    vector<int>dp(n+1);
    cout<<maxProfitDp(n, price, dp);
    return 0;
}