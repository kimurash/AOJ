/* 素数判定(エラトステネスの篩) */
#include <bits/stdc++.h>
#include <stdint.h>

#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

using namespace std;

// エラトステネスの篩にかける
uint16_t sieve_eratos(int *nums, int n, int max) {
    bool isprime[max + 1];  // 素数表
    // [XXX]: テストケース#4の最大値が大きすぎてSegmentation fault

    fill_n(isprime, max + 1, true);

    isprime[0] = isprime[1] = false;  // 0と1を消去
    // iを残してiの倍数を消去していく
    for(int i = 2; i * i <= max; i++){
        // 以前のループで消去されている可能性
        if(isprime[i]){
            int j = i + i;
            while (j <= max) {
                isprime[j] = false;
                j += i;
            }
        }
    }

    uint16_t count = 0;
    rep(i, n) {
        if (isprime[nums[i]]) {
            count++;
        }
    }
    return (count);
}

int main() {
    int n;
    cin >> n;

    int max = 2;
    int nums[n];
    rep(i, n) {
        cin >> nums[i];
        if (max < nums[i]) {
            max = nums[i];
        }
    }
    printf("max:%d\n", max);

    cout << sieve_eratos(nums, n, max) << endl;
    return (0);
}