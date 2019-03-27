/*----------------------|
/ Author : Ashraf Tasin |
/ Date   :   05.03.19   |
/----------------------*/

#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define ll long long
#define all v.begin(),v.end()
#define M it=m.begin(),it!=m.end(),it++
#define flash ios :: sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define db double
#define endl "\n"
#define mnm pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>
#define show for(int i=0;i<v.size();i++) cout << v[i] << " ";
#define ret return
using namespace std;

int dp[2019][2019];

int main()
{
  flash

  int tc;
  cin >> tc;

  while(tc--)
  {
    memset(dp,0,sizeof dp);
    string a,b;
    cin >> a >> b;

    int as=a.size();
    int bs=b.size();

    for(int i=0;i<=as;++i)
    {
      for(int j=0;j<=bs;++j)
      {
        if(i==0) dp[i][j]=j;
        else if(j==0) dp[i][j]=i;
        else if(a[i-1]==b[j-1]) dp[i][j]=dp[i-1][j-1];
        else dp[i][j]=1+min(min(dp[i-1][j-1],dp[i-1][j]),dp[i][j-1]);
      }
    }

    cout << dp[as][bs] << endl;
  }

  return 0;
}
