//#include <iostream>
//#include <vector>
//#include <iomanip>
//#include <cmath>
//using namespace std;
//
//const int INF = 20000000;
//
//int N, M;
//vector<pair<int, int> >coordinates;
//vector<bool> visited;
//vector<double> dist;
//double ans;
//
//int main() {
//    int u, v;
//
//    cin >> N >> M;
//    vector<vector<double> > edges(N, vector<double>(N));
//    coordinates.resize(N);
//    visited.resize(N);
//    dist.resize(N, INF);
//
////    输入坐标
//    for (int i = 0; i < N; i++) {
//        cin >> coordinates[i].first >> coordinates[i].second;
//    }
//
////    输入边
//    for (int i = 0; i < M; i++) {
//        cin >> u >> v;
//        visited[u - 1] = visited[v - 1] = true;
//        dist[u - 1] = dist[v - 1] = 0;
//    }
//
////    prim算法
////    初始化
//    for (int i = 0; i < N; i++)
//        for (int j = i; j < N; j++) {
//            edges[j][i] = edges[i][j] = (double)sqrt((double)pow(coordinates[i].first - coordinates[j].first, 2) +
//                                                             (double)pow(coordinates[i].second - coordinates[j].second, 2));
//        }
//
//    for (int i = 0; i < N; i++)
//        if (visited[i]) {
//            for (int j = 0; j < N; j++)
//                if (!visited[j])
//                    dist[j] = min(dist[j], edges[i][j]);
//        }
//
//    while (true) {
//        int t = -1, MIN = INF;
//        for (int i = 0; i < N; i++)
//            if (!visited[i] && dist[i] < MIN) {
//                t = i;
//                MIN = dist[i];
//            }
//        if (t == -1)
//            break;
//        visited[t] = true;
//        ans += dist[t];
//
//        for (int i = 0; i < N; i++)
//            if (!visited[i] && dist[i] > edges[t][i])
//                dist[i] = edges[t][i];
//    }
//    cout << fixed << setprecision(2) << ans << endl;
//
//    return 0;
//}



#include <iostream>
#include <cmath>
#include <algorithm>
#include <iomanip>
using namespace std;
const int MAXN = 1001;

struct Edge {
    int u, v;
    double w;
    Edge(){}
    Edge(int u, int v,  double w): u(u), v(v), w(w){}
    bool operator<(const Edge & e)const {
        return w < e.w;
    }
};

int N, M, sum;
double ans;
int father[MAXN];
int x[MAXN], y[MAXN];

void init() {
    for (int i = 0; i < N; i++)
        father[i] = i;
}

int findFather(int a) {
    return father[a] == a ? a : father[a] =findFather(father[a]);
}

bool isSame(int a, int b) {
    return findFather(a) == findFather(b);
}

void unite(int a, int b) {
    a = findFather(a);
    b = findFather(b);
    if (a < b)
        father[a] = b;
    else
        father[b] = a;
}


int main() {
    cin>>N>>M;

    init();
    Edge edges[N *(N-1)/2];
    int idx=0;
    for (int i = 0; i< N; i++)
        cin >> x[i] >> y[i];

    for (int i = 0; i < N; i++)
        for (int j = i+1; j < N; j++) {
            auto w = (double)sqrt((double)pow(x[i] - x[j], 2) +
                    (double)pow(y[i] - y[j], 2));
            edges[idx++] = Edge(i, j, w);
        }

    for (int i = 0; i <M;i++) {
        int u, v;
        cin >> u >> v;
        unite(u-1,v-1);
    }

    sort(edges, edges+idx);

    for (int i = 0; i < idx; i++) {
        Edge e = edges[i];
        if (!isSame(e.u, e.v)) {
            ans += e.w;
//            cout << e.w<<' ';
            sum++;
            unite(e.u, e.v);
        }
        if (sum == N - M - 1)
            break;
    }

    cout << fixed << setprecision(2) << ans << endl;

    return 0;
}
