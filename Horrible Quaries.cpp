/*----------------------|
/ Author : Ashraf Tasin |
/ Date   :   29.12.18   |
/----------------------*/

#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define ll long long
#define all v.begin(),v.end()
#define M it=m.begin(),it!=m.end(),it++
#define flash ios :: sync_with_stdio(false); cin.tie(NULL);
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


const ll mx = 100011;
ll arr[mx],lazy[4*mx],tree[4*mx];
ll n;


void build(ll node=1,ll left=1, ll right=n)
{
    if(left==right)
    {
        tree[node]=arr[left];
        return;
    }

    ll mid=(left+right)/2;

    build(node<<1,left,mid);
    build((node<<1)+1,mid+1,right);

    tree[node]=tree[node<<1]+tree[(node<<1)+1];
}


void update(ll node,ll left,ll right,ll val)
{
    lazy[node]+=val;
    tree[node]+=((right-left)+1)*val;
}


void shift(ll node,ll left,ll right)
{
    ll mid=(left+right)/2;
    update(node<<1,left,mid,lazy[node]);
    update((node<<1)+1,mid+1,right,lazy[node]);
    lazy[node]=0;
}


void increase(ll left_range,ll right_range,ll val,ll node=1,ll left=1,ll right=n)
{
    if(left_range>right or right_range<left) return;

    if(left_range<=left and right_range>=right)
    {
        update(node,left,right,val);
        return;
    }

    shift(node,left,right);

    ll mid=(left+right)/2;

    increase(left_range,right_range,val,(node<<1),left,mid);
    increase(left_range,right_range,val,((node<<1)+1),mid+1,right);

    tree[node]=tree[(node<<1)]+tree[(node<<1)+1];
}


ll sum(ll left_range,ll right_range, ll node=1,ll left=1,ll right=n)
{
    if(left_range>right or right_range<left) return 0;

    if(left_range<=left and right_range>=right) return tree[node];

    shift(node,left,right);

    ll mid=(left+right)/2;

    ll l=sum(left_range,right_range,(node<<1),left,mid);
    ll r=sum(left_range,right_range,((node<<1)+1),mid+1,right);

    return l+r;
}


int main()
{
    flash
    ll tc;
    cin >> tc;

    while(tc--)
    {
        ll c;
        cin >> n >> c;

        memset(arr,0,sizeof(arr));

        for(ll i=0;i<4*mx;i++)
        {
            lazy[i]=0;
            tree[i]=0;
        }

        build();

        for(ll i=0;i<c;++i)
        {
            ll x;
            cin >> x;

            if(x==0)
            {
                ll left_range,right_range,val;
                cin >> left_range >> right_range >> val;

                increase(left_range,right_range,val);
            }

            else
            {
                ll left_range,right_range;
                cin >> left_range >> right_range;
                cout << sum(left_range,right_range) << endl;
            }
        }
    }
}


