//#include <iostream>
//
//int main() {
//    std::cout << "Hello, World!" << std::endl;
//    return 0;
//}

#include <cstdio>
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int N, d;
vector<int> father;
vector<int>ran;

void init() {
    father.resize(N + 1);
    ran.resize(N + 1, 0);
    for (int i = 1; i <= N; i++)
        father[i] = i;
}

int find(int x) {
    if (x != father[x]) {
        father[x] = find(father[x]);
    }
    return father[x];
}

bool same(int x, int y) {
    return find(x) == find(y);
}

void unite(int x, int y) {
    x = find(x);
    y = find(y);
    if (ran[x] < ran[y])
        father[x] = y;
    else {
        father[y] = x;
        if (ran[x] == ran[y])
            ran[x]++;
    }
}

int main()
{
    char op;
    int a, b;
    cin >> N >> d;
    vector<bool>repaired(N + 1,false);
    vector<pair<int, int>> coordinate(N + 1);

    for (int i = 1; i <= N; i++)
        cin >> coordinate[i].first >> coordinate[i].second;

    init();
    while (~scanf("%c",&op)) {
        if (op == 'O') {
            cin >> a;
            repaired[a] = true;
            for (int i = 1; i <= N; i++) {
                if (i != a && repaired[i] && pow(coordinate[i].first - coordinate[a].first, 2) +
                                             pow(coordinate[i].second - coordinate[a].second, 2) <= d * d) {
                    unite(a, i);
                }
            }
        }
        else {
            cin >> a >> b;
            if (same(a, b))
                cout << "SUCCESS\n";
            else
                cout << "FAIL\n";

        }
    }

    return 0;
}

/*
#include <stdio.h>
#include <iostream>
#include <string.h>
using namespace std;

int f[1010];
int N, d;
bool rep[1010];
int q, p, n;

int st[1010];
int en[1010];

void init() {
    for(int i = 1; i <= N; i ++) {
        f[i] = i;
        rep[i] = false;
    }
}

int Find(int x) {
    if(f[x] != x) f[x] = Find(f[x]);
    return f[x];
}

void Merge(int x, int y) {
    int fx = Find(x);
    int fy = Find(y);
    if(fx != fy)
        f[fx] = fy;
}

int main() {
    scanf("%d%d", &N, &d);
    init();
    for(int i = 1; i <= N; i ++)
        scanf("%d%d", &st[i], &en[i]);

    int f1, f2;
    char op;
    while(~scanf("%c", &op)) {
        if(op == 'O') {
            scanf("%d", &n);
            rep[n] = true;
            for(int i = 1; i <= N; i ++) {
                if(i != n && rep[i] && (en[i] - en[n]) * (en[i] - en[n]) + (st[i] - st[n]) * (st[i] - st[n]) <= d * d) {
                    f1 = Find(n);
                    f2 = Find(i);
                    f[f1] = f2;
                }
            }
        }
        else if(op == 'S'){
            scanf("%d%d", &q, &p);
            f1 = Find(p);
            f2 = Find(q);

            if(f1 == f2) printf("SUCCESS\n");
            else printf("FAIL\n");
        }
    }
    return 0;
}

*/