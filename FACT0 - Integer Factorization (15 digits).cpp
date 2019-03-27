/*----------------------|
/ Author : Ashraf Tasin |
/ Date   :   19.01.19   |
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
#define mx 1000000000000008
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
    while(true)
    {
        ll x;
        scanf("%lld",&x);

        if(x==0) break;

        vector< pair<ll,ll> > vp;

        int cnt=0;

        while(x%2==0)
        {
            x/=2;
            cnt++;
        }

        if(cnt!=0) vp.pb({2,cnt});

        ll sz=sqrt(mx)+1;

        for(ll i=3;i<sz;i+=2)
        {
            cnt=0;

            if(x%i==0)
            {
                while(x%i==0)
                {
                    x/=i;
                    cnt++;
                }

                vp.pb({i,cnt});
            }
        }

        if(x>2) vp.pb({x,1});

        for(ll i=0;i<vp.size();i++) printf("%lld^%lld ",vp[i].first,vp[i].second);
        printf(endl);
    }

    return 0;

}
