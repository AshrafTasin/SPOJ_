/*----------------------|
/ Author : Ashraf Tasin |
/ Date   :   04.01.19   |
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
#define show for(int i=0;i<v.size();i++) cout << v[i];
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

    map<char,int> m;

    m.insert(pair<char,int>('+',1));
    m.insert(pair<char,int>('-',1));
    m.insert(pair<char,int>('*',2));
    m.insert(pair<char,int>('/',2));
    m.insert(pair<char,int>('^',3));

    int tc;
    cin >> tc;

    while(tc--)
    {
        string a,b="(",c=")";
        vector<char> v;
        stack<char> s;
        cin >> a;

        if(a[0]!='(')
        {
            a=b+a;
            a=a+c;
        }

        for(int i=0;i<a.size();i++)
        {
            char x=a[i];

            if(x=='(') s.push(x);

            else if(x=='+' || x== '-' || x=='*' || x=='/'|| x=='^')
            {
                char y=s.top();

                if(y=='(' || s.empty()==true || m[y]<m[x]) s.push(x);

                else
                {
                    while(s.top()!='(' || m[s.top()]>=m[x])
                    {
                        v.pb(s.top());
                        s.pop();
                    }

                    s.push(x);
                }
            }

            else if(x== ')')
            {
                while(s.top()!='(')
                {
                    v.pb(s.top());
                    s.pop();
                }
                s.pop();

            }

            else v.pb(x);
        }

       show;
       cout << endl;
    }

    return 0;
}
