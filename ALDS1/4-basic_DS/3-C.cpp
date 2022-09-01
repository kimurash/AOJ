/*
    テーマ: 双方向連結リスト
*/
#include <bits/stdc++.h>

#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

#define CMD_MAXLEN 16

using namespace std;

typedef enum cmd_type {
    INSERT,
    DELETE,
    DELETE_FIRST,
    DELETE_LAST,
    UNKNOWN
} CmdType;

CmdType discern_cmd(const char *cmd) {
    if (strncmp(cmd, "insert", CMD_MAXLEN) == 0) {
        return (INSERT);
    } else if (strncmp(cmd, "delete", CMD_MAXLEN) == 0) {
        return (DELETE);
    } else if (strncmp(cmd, "deleteFirst", CMD_MAXLEN) == 0) {
        return (DELETE_FIRST);
    } else if (strncmp(cmd, "deleteLast", CMD_MAXLEN) == 0) {
        return (DELETE_LAST);
    } else {
        return (UNKNOWN);
    }
}

void dump_list(list<int32_t> lst) {
    list<int32_t>::iterator iter = lst.begin();
    while (iter != --lst.end()) {
        cout << *iter << " ";
        iter++;
    }
    cout << *iter << endl;

    return;
}

int main() {
    int n;
    cin >> n;

    list<int32_t> lst;
    char cmd[16] = "";
    int32_t key;
    rep(i, n) {
        scanf("%s", cmd);
        switch (discern_cmd(cmd)) {
            case INSERT:
                scanf("%d", &key);
                lst.push_front(key);
                break;
            case DELETE:
                scanf("%d", &key);
                for (list<int32_t>::iterator iter = lst.begin();
                     iter != lst.end(); iter++) {
                    if (*iter == key) {
                        lst.erase(iter);
                        break;
                    }
                }
                break;
            case DELETE_FIRST:
                lst.pop_front();
                break;
            case DELETE_LAST:
                lst.pop_back();
                break;
            case UNKNOWN:
                cout << "Unknown Command." << endl;
                exit(-1);
        }
        // dump_list(lst);
    }

    dump_list(lst);
    return (0);
}