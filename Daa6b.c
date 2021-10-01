//Activity selection using dynamic programming approach
#include<stdio.h>
#include <string.h>
int n;
int st[1000], en[1000];
int dp[1000][1000];

int solve(int index, int currentFinishTime){
    if(index == n) return 0;
    int v1 = 0, v2 = 0;
    if(dp[index][currentFinishTime] != -1) return dp[index][currentFinishTime];

    //do not choose the current activity
    v1 = solve(index+1, currentFinishTime);

    //try to choose the current activity
    if(st[index] >= currentFinishTime){
        v2 = solve(index+1, en[index]) + 1;
    }
    return dp[index][currentFinishTime] = max(v1, v2);
}

int main(){
    scanf(n);
    for(int i = 0;i < n;i++) 
    scanf(st[i],en[i]);
    memset(dp, -1, sizeof dp);

    printf(solve(0, 0));
return 0;
}
