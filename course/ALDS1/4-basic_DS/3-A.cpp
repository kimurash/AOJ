/*
    テーマ: スタック
    問題: RPN計算機
*/
#include <bits/stdc++.h>

#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

using namespace std;

bool is_number(const string& str) {
    for (char const& c : str) {
        if (isdigit(c) == 0) {
            return (false);
        }
    }
    return (true);
}

int main() {
    stack<int32_t> config;

    string exp, symbol;
    getline(cin, exp);
    stringstream ss(exp);

    while (getline(ss, symbol, ' ')) {
        if (is_number(symbol)) {  // 数字であればプッシュ
            config.push(stoi(symbol));
            // cout << symbol << endl;
        } else {  // 数字でなければ演算
            int32_t opA = config.top();
            config.pop();
            int32_t opB = config.top();
            config.pop();
            // cout << opA << symbol << opB << "=";

            switch (symbol[0]) {
                case '+':
                    opA = opB + opA;
                    break;
                case '-':
                    opA = opB - opA;
                    break;
                case '*':
                    opA = opB * opA;
                    break;
                case '/':
                    opA = opB / opA;
                    break;
                default:
                    cout << "Unknown Operation." << endl;
                    exit(-1);
            }

            // 計算結果をプッシュ
            config.push(opA);
            // cout << opA << endl;
        }
    }

    cout << config.top() << endl;
    return (0);
}