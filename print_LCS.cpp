#include<iostream>
using namespace std;

void LCS(string x,string y,int m,int n)
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

    int Count=dp[m][n];
    char res[dp[m][n]];
    i=m;j=n;
    while(Count)
    {
        if(dp[i][j]==dp[i-1][j])
            i--;
        else if(dp[i][j]==dp[i][j-1])
            j--;
        else
        {
            res[Count-1]=x[i-1];
            i--;    j--;    Count--;
        }
    }
    for(i=0;i<dp[m][n];i++)
        cout<<res[i];
}

int main()
{
    string x,y;
    cout<<"Enter string 1 : ";
    cin>>x;
    cout<<"Enter string 2 : ";
    cin>>y;
    LCS(x,y,x.size(),y.size());
    return 0;
}
