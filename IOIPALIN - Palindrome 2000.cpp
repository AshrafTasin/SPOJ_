/*----------------------|
/ Author : Ashraf Tasin |
/ Date   :   13.02.19   |
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
#define mx 5050
using namespace std;


/*King  Moves

int dx[]={-1,1,-1,0,1,-1,0,1};
int dy[]={0,0,-1,-1,-1,1,1,1};    */

/*Knight Moves

int dx[] = { 2, 1, -1, -2, -2, -1, 1, 2 };
int dy[] = { 1, 2, 2, 1, -1, -2, -2, -1 }; */

/*Normal Moves

int x[] = {0, 1, 0, -1};
int y[] = {-1, 0, 1, 0}; */

string s1,s2;
int n;
int dp[mx][mx];

int lcs()
{
    for(int i=0;i<=n;++i) dp[i][0]=0;
    for(int i=0;i<=n;++i) dp[0][i]=0;

    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=n;++j)
        {
            if(s1[i-1]==s2[j-1]) dp[i][j]=1+dp[i-1][j-1];
            else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        }
    }

    return dp[n][n];
}


int main()
{
    cin >> n >> s1;
    s2=s1;
    reverse(s2.begin(),s2.end());

    cout << n-lcs() << endl;
}

