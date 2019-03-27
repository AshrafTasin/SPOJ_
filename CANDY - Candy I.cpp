/*----------------------|
/ Author : Ashraf Tasin |
/ Date   :   06.03.19   |
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


int main()
{
  flash

  ll x;

  while(cin >> x)
  {
    if(x==-1) break;
    ll sum=0;
    vector<ll> v;

    for(int i=1;i<=x;++i)
    {
      ll xx;
      cin >> xx;
      sum+=xx;
      v.pb(xx);
    }

    sort(all,greater<ll>());

    if(x==1) cout << 0 << endl;
    else if(sum%x!=0) cout << -1 << endl;
    else
    {
      ll ans=0;
      for(int i=0;i<x;++i)
      {
        if(v[i]<=sum/x) break;
        ans+=v[i]-(sum/x);
      }

      cout << ans << endl;
    }

  }

  return 0;

}

