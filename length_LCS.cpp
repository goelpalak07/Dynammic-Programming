#include<iostream>
using namespace std;

int LCS(string x,string y,int m,int n)
{
    int i,j;
    int dp[m+1][n+1];
    for(i=0;i<=n;i++)
        dp[0][i]=0;
    for(i=0;i<=m;i++)
        dp[i][0]=0;

    for(i=1;i<=m;i++)
    {
        for(j=1;j<=n;j++)
        {
            if(x[i-1]==y[j-1])
                dp[i][j]=dp[i-1][j-1]+1;
            else
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        }
    }
    for(i=0;i<=m;i++)
    {
        for(j=0;j<=n;j++)
            cout<<dp[i][j]<<" ";
        cout<<endl;
    }
    return dp[m][n];
}

int main()
{
    string x,y;
    cout<<"Enter string 1 : ";
    cin>>x;
    cout<<"Enter string 2 : ";
    cin>>y;
    cout<<"Length of Longest Common Subsequence in these strings is : "<<LCS(x,y,x.size(),y.size());
    return 0;
}
