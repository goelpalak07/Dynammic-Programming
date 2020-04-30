#include<iostream>
using namespace std;
int LRS(string str, int n)
{
    int i,j,dp[n+1][n+1];
    for(i=0;i<=n;i++)
        dp[i][0]=0;
    for(i=0;i<=n;i++)
        dp[0][i]=0;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            if(i!=j && str[i-1]==str[j-1])
                dp[i][j]=dp[i-1][j-1]+1;
            else
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        }
    }
    return dp[n][n];
}
int main()
{
    string str;
    cout<<"Enter the string : ";
    cin>>str;
    cout<<"Length of Longest Repeated Subsequence of "<<str<<" is : "<<LRS(str,str.size());
    return 0;
}
