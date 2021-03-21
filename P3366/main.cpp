//#include <iostream>
//#include <vector>
//#include <queue>
//using namespace std;
//
//struct Edge {
//    int u, v, w;
//    Edge(int u, int v, int w): u(u), v(v), w(w){}
//    bool operator<(const Edge & e)const {
//        return w > e.w;
//    }
//};
//
//int N, M, sum;
//long long ans;
//vector<int> height;
//vector<int> father;
//
//void init() {
//    height.resize(N);
//    father.resize(N);
//    for (int i = 0; i < father.size(); i++)
//        father[i] = i;
//}
//
//int findFather(int a) {
//    if (a != father[a]) {
//        father[a] = findFather(a);
//    }
//
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
//
//    if (height[a]<height[b])
//        father[a] = b;
//    else {
//        father[b] = a;
//        if (height[a] == height[b])
//            height[a]++;
//    }
//}
//
//
//
//
//int main() {
//    int u,v,w;
//
//    cin>>N>>M;
//
//    init();
//    vector<Edge> edges;
//    for (int i = 0; i < M; i++) {
//        cin >> u >> v >>w;
//        edges.emplace_back(u-1,v-1,w);
//    }
//
//    for (auto& e: edges) {
//        if (!isSame(e.u, e.v)){
//            ans += e.w;
//            sum++;
//            unite(e.u,e.v);
//        }
//        if (sum == N-1)
//            break;
//    }
//    if (sum == N-1)
//        cout << ans << endl;
//    else
//        cout <<"orz"<<endl;
//
//    return 0;
//}


#include <iostream>
#include <vector>
using namespace std;

const int INF = 0xffffff;

struct Edge {
    int v, w;

    Edge(int v, int w) : v(v), w(w) {}
};

int N, M;
int ans;

void prim(vector<Edge> edges[]) {
    vector<int> visited(N);
    vector<int> dist(N, INF);
    dist[0] = 0;

    while (true) {
        int u = -1, MIN=INF;

        for(int i = 0; i < N; i++)
        {
            if (!visited[i] && dist[i] < MIN) {
                MIN = dist[i];
                u = i;
            }
        }
        if (u==-1)
            break;
        visited[u]=true;
        ans+=dist[u];

        for (int i = 0; i < edges[u].size(); i++) {
            Edge e = edges[u][i];

            if (!visited[e.v] && dist[e.v] > e.w)
                dist[e.v] = e.w;
        }
    }
    for (int i = 0; i < N; i++)
        if (!visited[i]) {
            cout << "orz"<< endl;
            return;
        }
    cout << ans << endl;
}

int main() {
    int u, v, w;
    cin >> N >> M;

    vector<Edge> edges[N];
    for (int i = 0; i < M; i++) {
        cin >> u >> v >> w;
        edges[u - 1].push_back(Edge(v - 1, w));
        edges[v - 1].push_back(Edge(u - 1, w));
    }
    prim(edges);

    return 0;
}
