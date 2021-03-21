#include <cstdio>
#include <algorithm>

const int N = 500;
int A,B;
int sum, ans;
int fa[N];

struct Edge {
    int u, v, w;
    Edge(){}
    Edge(int u, int v, int w):u(u), v(v), w(w){}
    bool operator<(Edge a) const
    {
        return w < a.w;
    }
};

int find(int a) {
    return fa[a] == a? a: fa[a] = find(fa[a]);
}

bool isSame(int x, int y) { return find(x) == find(y); }

void unite(int x, int y) {
    x = find(x);
    y = find(y);
    fa[x] = y;
}

int main() {
    scanf("%d %d", &A, &B);

    Edge edges[N * (N - 1) / 2+1];
    int idx = 0;
    for (int i = 0; i <= B; i++)
        fa[i] = i;

    for (int i = 1; i <= B; i++)
        for (int j = 1; j <= B; j++) {
            int w;
            scanf("%d", &w);
            if (i < j && w)
                edges[idx++] = Edge(i, j, w);
        }
    for (int i = 1; i <= B; i++)
        edges[idx++] = Edge(0, i, A);
    std::sort(edges, edges + idx);

    for (int i = 0; i < idx; i++) {
        if (!isSame(edges[i].u, edges[i].v)) {
            unite(edges[i].u, edges[i].v);
            sum++;
            ans += edges[i].w;
        }
    }

    printf("%d\n", ans);
    return 0;
}