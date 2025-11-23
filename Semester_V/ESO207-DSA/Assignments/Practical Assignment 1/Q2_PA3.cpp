#include <iostream>

using namespace std;

struct Edge{
    int to;
    Edge* next;
    Edge(): to(0), next(0) {}
    Edge(int _to, Edge* _next): to(_to), next (_next) {}
};

int N, M;
Edge** head;
int *par, *depth, *tin, *tout;
int timer = 0;

void add_edge(int u, int v)
{
    head[u] = new Edge(v, head[u]);
    head[v] = new Edge(u, head[v]);
}

void dfs(int v, int p)
{
    par[v] = p;
    tin[v] = ++timer;
    for(Edge* e = head[v]; e; e = e->next)
    {
        int u = e-> to;
        if(u == p) continue;
        depth[u] = depth[v] + 1;
        dfs(u, v);
    }
    tout[v] = ++timer;
}

inline bool is_ancestor(int a, int b)
{
    return (tin[a] <= tin[b]) && (tout[b] <= tout[a]);
}

int main(void)
{
    cin >> N >> M;
    head = new Edge*[N+1];
    par = new int[N+1];
    depth = new int[N+1];
    tin = new int[N+1];
    tout = new int[N+1];

    for (int i = 1; i <= N; i++)
    {
        head[i] = 0; par[i] = 0; depth[i] = 0; tin[i] = 0; tout[i] = 0;
    }
    for (int i = 0; i < N-1; i++)
    {
        int a, b;
        cin >> a >> b;
        add_edge(a, b);
    }
    depth[1] = 0;
    dfs(1,0);

    while(M--)
    {
        int k; //number of elements in set
        cin >> k;

        int* v = new int[k];
        for (int i = 0; i < k; i++)
        {
            cin >> v[i];
        }
        for (int i = 0; i < k; i++)
        {
            if(v[i] != 1) v[i] = par[v[i]];
        }
        int w = v[0];
        for (int i = 1; i < k; i++)
        {
            if (depth[w] < depth[v[i]]) {w = v[i];}
        }

        bool ok = true;
        for(int i = 0; i <k; i++)
        {
            if(!is_ancestor(v[i], w)){ok = false; break;}
        }
        if (ok)
        {
            cout << "YES\n";
        }
        else {cout << "NO\n";}

        delete[] v;
    }

    return 0;
}