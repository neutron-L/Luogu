#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


bool cmp(pair<int, int>& a, pair<int, int>& b) {
    return a.first * a.second < b.first * b.second;
}

int main() {
    int n;
    int a, b;
    vector<pair<int, int>> minister;

    cin >> n;
    cin >> a >> b;
    minister.resize(n);
    for (int i = 0; i < n; i++)
        cin >> minister[i].first >> minister[i].second;

//    sort(minister.begin(), minister.end(), [](pair<int, int>a, pair<int, int>b) {
//        return a.first*a.second<b.first*b.second;
//    });
    long ans = 0;
    long tmp = a;
    for (int i = 0; i < n; i++) {
        ans = max(ans, tmp / minister[i].second);
        tmp *= minister[i].first;
    }


    std::cout << ans << std::endl;
    return 0;
}
