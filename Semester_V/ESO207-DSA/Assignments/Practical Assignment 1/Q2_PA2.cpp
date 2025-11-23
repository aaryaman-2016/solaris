#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;

        vector<vector<int>> dist(n+1, vector<int>(n+1, INT_MAX));
        queue<pair<int, int>> q;

        for (int i = 0; i < k; i++)
        {
            int x,y;
            if (dist[x][y] !=0)
            {
                dist[x][y] = 0;
                q.push({x,y});
            }
        }

        const int dx[8] = {-1,-1,-1, 0, 0, 1, 1, 1};
        const int dy[8] = {-1, 0, 1,-1, 1,-1, 0, 1};
        
        while(!q.empty)
        {
            auto [x,y] = q.front();
            q.pop();
            for (int dir = 0; dir < 8; dir++)
            {
                int nx = x + dx[dir];
                int ny = y + dy[dir];
                if (nx >= 1 && nx <= n && ny >= 1 && ny <= n)
                {
                    if(dist[nx][ny] > dist[x][y]+1)
                    {
                        dist[nx][ny] = dist[x][y] + 1;
                        q.push({nx, ny});
                    }
                }
            }

        }

        int ans = 0; 
        for(int i = 1; i <= n; i ++)
        {
            for (int j = 1; j <= n; )
            {
                ans = max(ans, dist[i][j]);
            }
        }

        cout << ans << "\n";
    }
    return 0;
}