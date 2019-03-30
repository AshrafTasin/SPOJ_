/*----------------------|
/ Author : Ashraf Tasin |
/ Date   :   30.03.19   |
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



void piTable(string pat,int *table)
{
    int n=pat.size();
    int j;
    table[0]=-1;

    for(int i=1;i<=n;++i)
    {
        j=table[i-1];

        while(j>=0 and pat[i-1]!=pat[j]) j=table[j];

        table[i]=j+1;
    }
}


void kmp(string tar,string pat,int *table)
{
    int n=tar.size();
    int m=pat.size();
    int i=0,j=0,cnt=0;
    memset(table,0,sizeof table);

    piTable(pat,table);

    while(i<n)
    {
        while(j>=0 and tar[i]!=pat[j]) j=table[j];

        ++i;
        ++j;

        if(j==m)
        {
            j=table[j];
            printf("%d\n",i-m);
            ++cnt;
        }
    }

    if(cnt==0) printf("\n");
}


int main()
{
    flash

    int n;
    string pat,tar;

    while(cin >> n)
    {
        int table[n+10];
        getline(cin,pat);
        getline(cin,pat);
        getline(cin,tar);

        kmp(tar,pat,table);
    }

    return 0;

}
