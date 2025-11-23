#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    int n;
    long long d, t;
    cin >> n >> d >> t;

    vector<pair<long long, long long>> v(n);
    //for ai, pi
    for (int i = 0; i < n;i++)
    {
        cin >> v[i].first >> v[i].second;
    }

    vector<long long> a(n);
    for (int i = 0; i < n; i++)
    {
        a[i] = v[i].first;
    }

    long long ans = 0;
    int j = 0;
    const long long INF = (LLONG_MAX / 4);

    for (int i = 0; i < n; i++)
    {
        long long ai = v[i].first;
        long long pi = v[i].second;

        if (j < i) j = i;
        while (j < n && a[j] <= ai + d) j++;
        long long nextLeave = (j < n ? a[j] : LLONG_MAX/4);

        long long endTime = min(t, nextLeave);
        long long play = endTime - ai;

        if (play >= pi){ans++;}
    }
    cout << ans << "\n";
    return 0;
}