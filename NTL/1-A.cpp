/* 素因数分解 */
#include <bits/stdc++.h>

#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

using namespace std;

void prime_factorize(int n) {
    for (int i = 2; i * i <= n; i++) {
        // 割り切れなければ無視
        if ((n % i) != 0) { continue; }

        while (n % i == 0) {  // 割り切れる限り
            cout << " " << i;
            n /= i;
        }
    }

    if (n != 1) { cout << " " << n; }
    return;
}

int main() {
    int n;
    cin >> n;
    
    cout << n << ":";
    prime_factorize(n);
    cout << endl;
    
    return(0);
}