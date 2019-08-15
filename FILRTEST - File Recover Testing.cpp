/*----------------------|
/ Author : Ashraf Tasin |
/ Date   :   01.04.19   |
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
#define mx 100004
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

int n;
ll x;

void solve(string s)
{
    int table[n+10];
    int j;
    table[0]=-1;

    for(int i=1;i<=n;++i)
    {
        j=table[i-1];
        while(j>=0 and s[i-1]!=s[j]) j=table[j];
        table[i]=j+1;
    }

    if(table[n]==0) cout << x/n << endl;
    else cout << (x-n)/(n-table[n])+1 << endl;
    return;

}

int main()
{
    string s;

    while(cin >> x >> s)
    {
        if(x==-1 and s=="*") break;
        n=s.size();
        if(n>x) cout << 0 << endl;
        else solve(s);
    }

    return 0;
}

