/* 面積計算 */
#include <bits/stdc++.h>

#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

using namespace std;

int main() {
    int32_t A = 0;  // 総面積
    char landform;
    stack<int32_t> stk_desc;  // 下りの位置
    stack<pair<int32_t, int32_t> > stk_config;  // (水たまりの左の位置, 水たまりの面積)

    for (int i = 0; cin >> landform; i++) {
        switch (landform) {
            case '\\':
                stk_desc.push(i);
                break;
            case '/':
                if (!stk_desc.empty()) {
                    int j = stk_desc.top();
                    stk_desc.pop();
                    A += i - j;
                    int32_t a = i - j;
                    while (!(stk_config.empty()) &&
                        stk_config.top().first > j) {
                        a += stk_config.top().second;
                        stk_config.pop();
                    }
                    stk_config.push(make_pair(j, a));
                }
                break;
            case '_':
            default:
                break;
        }
    }

    vector<int32_t> L;
    while (!stk_config.empty()) {
        L.push_back(stk_config.top().second);
        stk_config.pop();
    }
    reverse(L.begin(), L.end());
    cout << A << endl;
    cout << L.size();
    rep(i, L.size()) { cout << " " << L.at(i); }
    cout << endl;

    return (0);
}