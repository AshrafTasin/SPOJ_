/*----------------------|
/ Author : Ashraf Tasin |
/ Date   :   19.12.18   |
/----------------------*/

#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define ll long long
#define all v.begin(),v.end()
#define M it=m.begin(),it!=m.end(),it++
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
    int test;
    cin >> test;

    while(test--)
    {
        int cap,n;
        cin >> cap >> n;

        int val[n+1],wt[n+1];
        val[0]=0,wt[0]=0;

        for(int i=1;i<=n;i++)
        {
            int a,b;
            cin >> a >> b;
            val[i]=b;
            wt[i]=a;
        }

        int tab[n+1][cap+1];

        for(int i=0;i<=n;i++)
        {
            for(int j=0;j<=cap;j++)
            {
                if(i==0 or j==0) tab[i][j]=0;

                else if(wt[i]<=j) tab[i][j]=max(val[i]+tab[i-1][j-wt[i]],tab[i-1][j]);

                else tab[i][j]=tab[i-1][j];
            }
        }

        cout << "Hey stupid robber, you can get " << tab[n][cap] << "." << endl;
     }

     return 0;
}



