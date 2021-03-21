
/*
#include <iostream>
#include <vector>
#include <set>
#include <queue>
using namespace std;

int N, M;
int dir[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
int nex[4][4] = {{-2, -1, -2, 0}, {-1, 1, 0, 1}, {1, -1, 1, 0}, {0, -2, -1, -2}};

struct Node {
    int cor;
    int step;
    int dir;
    Node(int cor, int s, int dir): cor(cor), step(s), dir(dir){}
};

int sx, sy, tx, ty, d;

bool valid(int x, int y){
    return x < N && x >= 0 && y >= 0 && y < M;
}

void bfs(vector<vector<int> > & map) {
    queue<Node> que;
    set<pair<int, int> > visited;
    if ((valid(sx, sy) && map[sx][sy]) || (valid(sx-1,sy)&&map[sx-1][sy])
    || (valid(sx, sy-1) && map[sx][sy-1] )|| (valid(sx-1,sy-1) && map[sx-1][sy-1])) {
        printf("%d\n", -1);
        return;
    }
    que.push(Node(sx * M + sy, 0, d));


    while (!que.empty()) {
        Node temp = que.front();
        que.pop();


        if (visited.count(make_pair(temp.cor, temp.dir)))
            continue;

        visited.insert(make_pair(temp.cor, temp.dir));

        if (temp.cor / M == tx && temp.cor % M == ty) {
            printf("%d\n", temp.step);
            return;
        }

//        前进

        int x0 = temp.cor / M;
        int y0 = temp.cor % M;

        int x1 = x0 + nex[temp.dir][0];
        int y1 = y0 + nex[temp.dir][1];
        int x2 = x0 + nex[temp.dir][2];
        int y2 = y0 + nex[temp.dir][3];
        x0 += dir[temp.dir][0];
        y0 += dir[temp.dir][1];

        if (valid(x1, y1) && valid(x2, y2) && valid(x0, y0) && !map[x1][y1] && !map[x2][y2]) {
            que.push(Node(x0 * M + y0, temp.step + 1, temp.dir));
            x1 += dir[temp.dir][0];
            y1 += dir[temp.dir][1];
            x2 += dir[temp.dir][0];
            y2 += dir[temp.dir][1];
            x0 += dir[temp.dir][0];
            y0 += dir[temp.dir][1];
            if (valid(x1, y1) && valid(x2, y2) && valid(x0, y0) && !map[x1][y1] && !map[x2][y2]) {
                que.push(Node(x0 * M + y0, temp.step + 1, temp.dir));

                x1 += dir[temp.dir][0];
                y1 += dir[temp.dir][1];
                x2 += dir[temp.dir][0];
                y2 += dir[temp.dir][1];
                x0 += dir[temp.dir][0];
                y0 += dir[temp.dir][1];
                if (valid(x1, y1) && valid(x2, y2) && valid(x0, y0) && !map[x1][y1] && !map[x2][y2])
                    que.push(Node(x0 * M + y0, temp.step + 1, temp.dir));
            }
        }

//turn left

        que.push(Node(temp.cor, temp.step + 1, (temp.dir - 1 + 4) % 4));

//turn right

        que.push(Node(temp.cor, temp.step + 1, (temp.dir + 1) % 4));
    }

    printf("%d\n", -1);
}

int main() {
    char ch;

    scanf("%d %d", &N, &M);
    vector<vector<int> > map(N, vector<int>(M));

    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            scanf("%d", &map[i][j]);
    scanf("%d %d %d %d %c", &sx, &sy, &tx, &ty, &ch);
    switch (ch) {
        case 'N':
            d = 0;
            break;
        case 'E':
            d = 1;
            break;
        case 'S':
            d = 2;
            break;
        case 'W':
            d = 3;
            break;
        default:
            break;
    }
    bfs(map);

    return 0;
}
*/
/*
#include <iostream>
using namespace std;

int main() {
    int n;
    int pre = -1;
    int sum = 0;

    while (cin >> n && n) {
        if (n == 1) {
            sum++;
            pre = 1;
        }
        else if (n == 2) {
            if (pre == -1 || pre == 1) {
                sum += 2;
                pre = 2;
            }
            else
            {
                pre += 2;
                sum += pre;
            }

        }
    }
    cout << sum<< endl;
    return 0;
}*/

#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> v(n);
    vector<int> newV(n);

    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    newV[0] = (v[0]+v[1])/2;
    newV[n-1] = (v[n-1]+v[n-2])/2;
    for (int i = 1; i < n-1; i++)
        newV[i] = (v[i-1]+v[i]+v[i+1])/3;
    for (int i = 0; i < n; i++)
        cout << newV[i] << ' ';
    cout << endl;

    return 0;
}