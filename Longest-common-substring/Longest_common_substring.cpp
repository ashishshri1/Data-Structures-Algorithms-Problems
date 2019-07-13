#include<iostream>
#include<string>
using namespace std;
int main()
{
    string str1,str2;
    cin>>str1>>str2;
    int m=str1.length();
    int n=str2.length();
    int dp[m+1][n+1];
    for(int i=0;i<=m;i++)
        dp[i][0]=0;
    for(int i=0;i<=n;i++)
        dp[0][i]=0;
    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(str1[i-1]==str2[j-1])
                dp[i][j]=dp[i-1][j-1]+1;
            else
                dp[i][j]=0;
        }
    }
    int max=0;
    int imax=0,jmax=0;
    for(int i=0;i<m+1;i++)
    {
        for(int j=0;j<n+1;j++)
        {
            if(max<=dp[i][j])
                {
                    max=dp[i][j];
                    imax=i;
                    jmax=j;
                }
        }
    }
    if(max==0)
        cout<<"No common substring";
    else
    {
    string substring=str1.substr(imax-max,max);
    cout<<substring;
    }
    return 0;
}
