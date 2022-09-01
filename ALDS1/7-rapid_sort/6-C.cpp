/* クイックソート */
#include <bits/stdc++.h>
#include <stdint.h>

#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

using namespace std;

int partition(vector<pair<char, int32_t> >& A, int p, int r) {
    int32_t x = A.at(r).second;
    int i = p - 1;
    pair<char, int32_t> temp;
    rep2(j, p, r) {
        if (A.at(j).second <= x) {
            i += 1;
            temp = A.at(i);
            A.at(i) = A.at(j);
            A.at(j) = temp;
        }
    }
    temp = A.at(++i);
    A.at(i) = A.at(r);
    A.at(r) = temp;

    return (i);
}

void quick_sort(vector<pair<char, int32_t> >& A, int p, int r) {
    if (p < r) {
        int q = partition(A, p, r);
        quick_sort(A, p, q - 1);
        quick_sort(A, q + 1, r);
    }
}

void show_all(vector<pair<char, int32_t> > A) {
    for (pair<char, int32_t> i : A) {
        cout << i.first << " " << i.second << endl;
    }
    return;
}

int main() {
    int n;
    cin >> n;

    vector<pair<char, int32_t> > A;
    // [FIXME]: 要素数が決まっているから単なる配列の方が速い
    char ch;
    int32_t num;
    rep(i, n) {
        cin >> ch >> num;
        A.push_back(make_pair(ch, num));
    }

    quick_sort(A, 0, A.size() - 1);
    show_all(A);
    return (0);
}