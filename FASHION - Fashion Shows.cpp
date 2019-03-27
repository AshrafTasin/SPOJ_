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

  int tc;
  cin >> tc;

  while(tc--)
  {
    ll x;
    cin >> x;
    vector<ll> v1,v2;

    for(int i=1;i<=x;++i)
    {
      int xx;
      cin >> xx;
      v1.pb(xx);
    }

    for(int i=1;i<=x;++i)
    {
      ll xx;
      cin >> xx;
      v2.pb(xx);
    }

    sort(v1.begin(),v1.end(),greater<ll>());
    sort(v2.begin(),v2.end(),greater<ll>());

    ll z= inner_product(v1.begin(),v1.end(),v2.begin(),0);
    cout << z << endl;
  }

  return 0;

}
