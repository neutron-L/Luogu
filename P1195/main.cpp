//#include <cstdio>
//#include <algorithm>
//using namespace std;
//
//struct Edge {
//    int u, v, w;
//
//    bool operator<(const Edge & e)const {
//        return w < e.w;
//    }
//}edges[10050];
//
//int N, M, K;
//int ans;
//int sum;
//int father[1005];
//
//
//void init() {
//    for (int i = 1; i <= N; i++)
//        father[i] = i;
//}
//
//int findFather(int a) {
//    if (a != father[a]) {
//        father[a] = findFather(a);
//    }
//    return father[a];
//}
//
//bool isSame(int a, int b) {
//    return findFather(a) == findFather(b);
//}
//
//void unite(int a, int b) {
//    a = findFather(a);
//    b = findFather(b);
//    father[a] = b;
//}
//
//int main() {
//    scanf("%d %d %d", &N, &M, &K);
//
//    init();
//    for (int i = 0; i < M; i++) {
//        scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].w);
//    }
//
//    sort(edges, edges+M);
//
//    for (int i = 0; i < M; i++) {
//        Edge e = edges[i];
//        if (isSame(e.u, e.v))
//            continue;
//        ans += e.w;
//        sum++;
//        unite(e.u, e.v);
//
//        if (sum == N - K) {
//            printf("%d", ans);
//            return 0;
//        }
//    }
//
//    printf("No Answer\n");
//
//    return 0;
//}

#include <cstdio>
#include <algorithm>

const int N = 1005;
int n, m, k, x, y, l, sum, ans;
int fa[N];

struct Edge {
    int u, v, w;
    bool operator<(Edge a) const
    {
        return w < a.w;
    }
}edges[N*10];

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
    scanf("%d %d %d", &n, &m, &k);

    for (int i = 1; i <= n; i++)
        fa[i] = i;
    for (int i = 1; i <= m; i++)
        scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].w);
    std::sort(edges+1, edges+m+1);

    for (int i = 1;i  <= m; i++){
//        int fx = find(edges[i].u), fy = find(edges[i].v);
        if (!isSame(edges[i].u, edges[i].v)) {
//            fa[fx] = fy;
unite(edges[i].u, edges[i].v);
            sum++;
            ans += edges[i].w;
        }
        if (sum == n - k)
        {
            printf("%d", ans);
            return 0;
        }
    }
    printf("No Answer\n");
    return 0;
}