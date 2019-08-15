/*----------------------|
/ Author : Ashraf Tasin |
/ Date   :   08.04.19   |
/----------------------*/

#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define ll long long
#define all v.begin(),v.end()
#define flash ios :: sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define db double
#define endl "\n"
#define mnm pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>
#define show for(int i=0;i<v.size();i++) cout << v[i] << " ";
#define eps 1e-6
#define mx  2020
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

int cap,N;
int cost[mx],wt[mx];
int dp[mx][mx];

int solve(int index,int w)
{
	if(index==N+1) return 0;
	if(dp[index][w]!=-1) return dp[index][w];

	int p1=0,p2=0;
	if(w+wt[index]<=cap) p1=cost[index]+solve(index+1,w+wt[index]);
	p2=solve(index+1,w);

	return dp[index][w]=max(p1,p2);

}


int main()
{
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif

	flash
	memset(dp,-1,sizeof dp);

	cin >> cap >> N;

	for(int i=0;i<N;++i) cin >> wt[i] >> cost[i];

	cout << solve(0,0) << endl;

	return 0;

}

