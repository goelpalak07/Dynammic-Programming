#include<iostream>
#include<cstring>
using namespace std;
class common{
    string x,y;
    int m,n;
public:
    common()
    {
        cout<<"Enter string 1 : ";
        cin>>x;
        cout<<"Enter string 2 : ";
        cin>>y;
        m=x.size();
        n=y.size();
    }
    void LCS();
};
void common::LCS()
{
    int i,j,dp[m+1][n+1],maxLen=0,EndingIndex;
    memset(dp,0,sizeof(dp));
    for(i=1;i<=m;i++)
    {
        for(j=1;j<=n;j++)
        {
            if(y[i-1]==x[j-1])
                dp[i][j]=dp[i-1][j-1]+1;
            if(dp[i][j]>maxLen)
            {
                maxLen=dp[i][j];
                EndingIndex=i;
            }
        }
    }
    cout<<y.substr(EndingIndex-maxLen,maxLen);
}
int main()
{
    common c;
    c.LCS();
    return 0;
}
