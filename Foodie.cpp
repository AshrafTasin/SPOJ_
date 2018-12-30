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
        int n,cap;
        cin >> n >> cap;

        int wt[n+1];
        wt[0]=0;

        for(int k=1;k<=n;k++)
        {
            int l;
            cin >> l;
            int sum=0;

            while(l--)
            {
                int r;
                cin >> r;
                sum+=r;
            }

            //cout << sum << endl;

            wt[k]=sum;
        }

        int tab[n+1][cap+1];

       //for(int i=0;i<=n;i++) cout << wt[i] << endl;

       for(int i=0;i<=n;i++)
       {
           for(int j=0;j<=cap;j++)
           {
               if(i==0 or j==0) tab[i][j]=0;

               else if (wt[i]<=j) tab[i][j]=max(wt[i]+tab[i-1][j-wt[i]],tab[i-1][j]);

               else tab[i][j]=tab[i-1][j];
           }
       }

       cout << tab[n][cap] << endl;


        /*for(int i=0;i<n+1;i++)
        {
            for(int j=0;j<cap+1;j++)
                cout << tab[i][j] << " ";
                cout << endl;
        }*/
    }

    return 0;
}



