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


int solve(int item,int maxcap)
{
	int table[2][cap+2];
	memset(table,0,sizeof table);
	int i=0;

	while(i<N)
	{
		int j=0;
		if(i%2==0)
		{
			while(++j<=cap)
			{
				if(wt[i]<=j) table[0][j]=max(cost[i]+table[1][j-wt[i]],table[1][j]);
				else table[0][j]=table[1][j];
			}
		}

		else
		{
			while(++j<=cap)
			{
				if(wt[i]<=j) table[1][j]=max(cost[i]+table[0][j-wt[i]],table[0][j]);
				else table[1][j]=table[0][j];
			}			
		}

		++i;
	}

	if(N%2==0) return table[1][cap];
	else return table[0][cap];
}


int main()
{
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif

	flash

	cin >> cap >> N;

	for(int i=0;i<N;++i) cin >> cost[i] >> wt[i];

	cout << solve(N,cap) << endl;

	return 0;

}

