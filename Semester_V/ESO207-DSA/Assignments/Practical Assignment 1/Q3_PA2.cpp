#include<bits/stdc++.h>

using namespace std;


static const long long MOD = 998244353LL;

void count(const vector<long long>& v, int l, int r, set<long long>& s)
{
    if ( l <= r)
    {
        long long prod = 1;
        for (int i = l; i <= r; i++)
        {
            prod = (prod * v[i]) % MOD;
        }
        s.insert(prod);
    }
    if (l == r){return;}

    long long mid = (v[l] + v[r]) /2;
    int x = l - 1;
    for (int i = l; i <= r; i++)
    {
        if (v[i] <= mid)
        {
            x = i;
        }
        else{break;}
    } 
    if (x < l || x >= r) return;
    count(v, l, x, s);
    count(v, x + 1,r, s);

}

int main(void)
{
    int t;
    cin >> t;
    while(t--)
    {
        int n, q;
        cin >> n >> q;
        vector<long long> v(n);
        for (int i = 0; i < n; i++) {cin >> v[i];}
        set<long long> s;
        sort(v.begin(), v.end());
        count(v, 0, n - 1, s);
        while(q--)
        {
            long long p;
            cin >> p; 
            if(s.count(p)){cout << "Yes\n";}
            else {cout << "No\n";}
        }
    }
    return 0;
}


