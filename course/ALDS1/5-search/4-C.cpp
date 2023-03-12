/* ハッシュがテーマの問題を集合を用いて解く */
#include <bits/stdc++.h>
#include <stdint.h>

#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
// #define MAX_CMD_LEN 6

using namespace std;

typedef enum cmd_type { INSERT, FIND, UNKNOWN } CmdType;

CmdType discern_cmd(const string& cmd) {
    if (cmd == "insert") {
        return (INSERT);
    } else if (cmd == "find") {
        return (FIND);
    } else {
        return (UNKNOWN);
    }
}

int main() {
    uint32_t n;
    cin >> n;

    string cmd, DNA;
    set<string> baseseq;
    rep(i, n) {
        cin >> cmd >> DNA;
        switch (discern_cmd(cmd)) {
            case INSERT:
                baseseq.insert(DNA);
                break;
            case FIND:
                if (baseseq.find(DNA) != baseseq.end()) {
                    cout << "yes" << endl;
                } else {
                    cout << "no" << endl;
                }
                break;
            case UNKNOWN:
                cout << "Unknown Command" << endl;
                exit(-1);
        }
    }

    return (0);
}