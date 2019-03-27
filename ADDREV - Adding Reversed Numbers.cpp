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
    string a,b,t;
    cin >> a >> b;
    reverse(a.begin(),a.end());
    reverse(b.begin(),b.end());
    ll x,y,ans;

    stringstream s1,s2,s3,s4;
    s1 << a;
    s1 >> x ;
    s2 << b;
    s2 >> y;

    x+=y;

    s3 << x;
    t=s3.str();
    reverse(t.begin(),t.end());
    s4 << t;
    s4 >> ans;
    cout << ans << endl;
  }

  return 0;
}
