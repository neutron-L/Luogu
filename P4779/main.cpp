#include <iostream>
#include <vector>
#include <queue>
//using namespace std;
using std::vector;
using std::endl;
using std::cin;
using std::cout;


int N, M,S;
const int INF=1e9+7;

struct Edge{
    int v;
    int cost;
    Edge(int v, int cost): v(v), cost(cost){}
    bool operator<(const Edge& e) const {
        return cost > e.cost;
    }
};

void Dijsktra(vector<vector<Edge> > & g, int s) {
    vector<int>dist(N, INF);
    vector<bool> visited(N,false);
    std::priority_queue<Edge> q;
    q.push(Edge(s,0));
    dist[s] = 0;
    while (!q.empty()) {
        Edge e = q.top();
        q.pop();
        if (visited[e.v])
            continue;
        visited[e.v] = true;
        for (int i = 0; i < g[e.v].size(); i++) {
            Edge temp = g[e.v][i];
            if (!visited[temp.v] && dist[temp.v] > dist[e.v] + temp.cost)
            {
                dist[temp.v] = dist[e.v] + temp.cost;
                temp.cost = dist[temp.v];
                q.push(temp);
            }
        }
    }
    for (int i = 0; i < N; i++)
        cout<< dist[i] << ' ';
    cout << endl;
}


int main() {
    int u,v,w;
    cin >> N>>M>>S;
    vector<vector<Edge> >g(N);

    while (M--) {
        cin >> u >> v >> w;
        g[u - 1].push_back(Edge(v - 1, w));
    }

    Dijsktra(g,S-1);

    return 0;
}

//#include <iostream>
//#include <vector>
//#include <algorithm>
//#include <queue>
//#include <cstring>
//
//using namespace std;
//const int INF = 1000005;
//typedef long long ll;
//
//ll dis[INF], vis[INF];
//ll n, m;
//int s;
//
//struct node{
//    int v;
//    ll d;
//    node (int a, ll b) {
//        v = a;
//        d = b;
//    }
//
//    bool operator<(const node & n) const {
//        return d > n.d;
//    }
//};
//
//vector<node> vec[INF];
//
//void Dijskrua() {
//    priority_queue<node> q;
//    memset(vis, 0, sizeof(vis));
//    for (int i = 1; i <= n; i++) {
//        dis[i] = 1e18;
//    }
//    dis[s] = 0;
//    q.push(node(s, 0));
//    while (!q.empty()) {
//        int x = q.top().v;
//        q.pop();
//        if (vis[x])
//            continue;
//        vis[x] = 1;
//        for (int i = 0; i < vec[x].size(); i++) {
//            node t = vec[x][i];
//            if (!vis[t.v] && dis[t.v] > dis[x] + t.d) {
//                dis[t.v] = dis[x] + t.d;
//                t.d = dis[t.v];
//                q.push(t);
//            }
//        }
//    }
//}
//
//int main() {
//    cin >> n >> m >> s;
//    for (int i = 0; i < m; i++) {
//        int x, y, v;
//        cin >> x >> y >> v;
//        vec[x].push_back(node(y, v));
//    }
//    Dijskrua();
//    for (int i = 1; i <= n; i++) {
//        if (i != n)
//            cout << dis[i] << " ";
//        else
//            cout << dis[i] << endl;
//    }
//}
//
//

