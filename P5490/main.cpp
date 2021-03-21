//#include <iostream>
//#include <algorithm>
//
//using namespace std;
//
//typedef long long ll;
//
//struct Segment {
//    ll l, r, h;
//    int val;
//    bool operator<(const Segment & k) const {
//        return h < k.h;
//    }
//}Seg[800010];
//
//struct SegTree {
//    int l, r;
//    int sum;
//    ll len;
//}Tree[1600010];
//
//ll X[800010];
//ll n, x1, x2, yy, y2, ans;
//
//
//void build(int k, ll l, ll r) {
//    Tree[k].l = l;
//    Tree[k].r = r;
//    Tree[k].sum = 0;
//    Tree[k].len = 0;
//    if (l == r)
//        return;
//    int mid = l+r>>1;
//    build(k<<1, l, mid);
//    build(k<<1|1, mid+1, r);
//}
//
//void pushUp(int k) {
//    int l = Tree[k].l;
//    int r = Tree[k].r;
//
//    if (Tree[k].sum) {
//        Tree[k].len = X[r+1] - X[l];
//    }
//    else
//        Tree[k].len = Tree[k<<1].len + Tree[k<<1|1].len;
//}
//
//void update(int k, ll L, ll R, int val) {
//    int l = Tree[k].l;
//    int r = Tree[k].r;
//    if (X[r+1] <= L || R <= X[l])
//        return;
//    else if (L <= X[l] && X[r+1]<=R)
//    {
//        Tree[k].sum += val;
//        pushUp(k);
//        return;
//    }
//    update(k<<1, L, R, val);
//    update(k<<1|1, L, R, val);
//    pushUp(k);
//}
//
//int main() {
//    scanf("%d", &n);
//
//    for (int i = 1; i <= n; i++) {
//        scanf("%lld %lld %lld %lld",&x1,&yy,&x2,&y2);
//        X[2 * i - 1] = x1, X[2 * i] = x2;
//        Seg[2*i-1] = (Segment){x1, x2, yy, 1};
//        Seg[2*i] = (Segment) {x1, x2, y2, -1};
//    }
//
//    n <<=1;
//    sort(Seg+1, Seg+n+1);
//    sort(X+1, X+n+1);
//    int cnt = unique(X+1, X+n+1)-X-1;
//    build(1,1,cnt-1);
//
//    for (int i = 1; i<n; i++) {
//        update(1, Seg[i].l, Seg[i].r, Seg[i].val);
//        ans += Tree[1].len * (Seg[i + 1].h - Seg[i].h);
//    }
//    printf("%lld", ans);
//
//    return 0;
//}

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

struct Segment{
    int u;
    int d;
    int x;
    int val;
}Seg[800010];

struct SegTree{
    int l;
    int r;
    int cover;
    int len;
}Tree[1600010];

ll Y[800010];
ll n, ans, x_1, y_1, x_2, y_2;

void build(int idx, int l, int r) {
    Tree[idx].l = l;
    Tree[idx].r = r;
    Tree[idx].cover = 0;
    Tree[idx].len = 0;
    if (l == r)
        return;
    else {
        int mid = (l + r) << 1;
        build((idx << 1), l, mid);
        build((idx << 1) | 1, mid + 1, r);
    }
}

void pushUp(int idx) {
    int l = Tree[idx].l;
    int r = Tree[idx].r;
    if (Tree[idx].cover)
        Tree[idx].len = Y[l + 1] - Y[r];
    else
        Tree[idx].len = Tree[idx << 1].len + Tree[idx << 1 | 1].len;
}

void update(int idx, ll L, ll R, int val) {
    int l = Tree[idx].l;
    int r = Tree[idx].r;
    if (L <= Y[r] || R >= Y[l+1])
        return;
    else if (L >= Y[l+1] && R <= Y[r]) {
        Tree[idx].cover+=val;
        pushUp(idx);
    }
    else {
        int mid = (l+r)>>1;
        update(idx<<1, L, R, val);
        update(idx<<1|1, L, R, val);
        pushUp(idx);
    }
}

int main() {
    scanf("%lld", &n);

    for (int i = 1; i <= n; i++) {
        scanf("%lld %lld %lld %lld", &x_1, &y_1, &x_2, &y_2);
        Seg[i * 2 - 1] = (Segment) {y_2, y_1, x_1, 1};
        Seg[i * 2] = (Segment) {y_2, y_1, x_2, -1};
    }
}





