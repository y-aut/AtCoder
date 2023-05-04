#include <iostream>
#include <queue>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

// メニュー情報
struct Menu {
    int id, stock, price;

    Menu() {}
    Menu(int _id, int _stock, int _price) : id(_id), stock(_stock), price(_price) {}
};

// メニュー情報を取得
unordered_map<int, Menu> get_menus(const int count) {
    // メニュー番号からメニュー情報への辞書
    unordered_map<int, Menu> menus;
    for (int i = 0; i < count; i++) {
        int D, S, P;
        cin >> D >> S >> P;
        menus.emplace(D, Menu(D, S, P));
    }
    return menus;
}

void step_1() {
    int M;
    cin >> M;

    auto menus = get_menus(M);

    string cmd;
    while (cin >> cmd) {
        int T, D, N;
        cin >> T >> D >> N;
        if (menus[D].stock < N) {
            cout << "sold out " << T << endl;
            continue;
        }
        menus[D].stock -= N;
        for (int i = 0; i < N; i++) {
            cout << "received order " << T << " " << D << endl;
        }
    }
}

void step_2() {
    int M, K;
    cin >> M >> K;

    auto menus = get_menus(M);

    // 使用中の電子レンジの数
    int mw_used = 0;

    // 調理待ちの料理番号
    queue<int> wait_list;
    // 各料理番号について，調理中のものが何個あるか
    unordered_map<int, int> cook_list;

    string cmd;
    while (cin >> cmd) {
        if (cmd == "received") {
            // 注文受理情報
            cin >> cmd; // "order"
            int T, D;
            cin >> T >> D;

            // 電子レンジが空いているか
            if (mw_used < K) {
                cout << D << endl;
                cook_list[D]++;
                mw_used++;
            } else {
                cout << "wait" << endl;
                wait_list.push(D);
            }
        } else {
            // 料理の完成情報
            int D;
            cin >> D;

            if (cook_list[D] == 0) {
                cout << "unexpected input" << endl;
                continue;
            }
            cook_list[D]--;

            if (!wait_list.empty()) {
                auto next = wait_list.front();
                wait_list.pop();

                cout << "ok " << next << endl;
                cook_list[next]++;
            } else {
                cout << "ok" << endl;
                mw_used--;
            }
        }
    }
}

void step_3() {
    int M;
    cin >> M;

    auto menus = get_menus(M);

    // 各料理に対応する席番号
    unordered_map<int, queue<int>> cook_list;

    string cmd;
    while (cin >> cmd) {
        if (cmd == "received") {
            // 注文受理情報
            cin >> cmd; // "order"
            int T, D;
            cin >> T >> D;

            cook_list[D].push(T);

        } else {
            // 料理の完成情報
            int D;
            cin >> D;

            auto seat = cook_list[D].front();
            cook_list[D].pop();

            cout << "ready " << seat << " " << D << endl;
        }
    }
}

void step_4() {
    int M;
    cin >> M;

    auto menus = get_menus(M);

    // 各席番号における，未提供の料理の数
    unordered_map<int, int> unserved;
    // 各席番号における，料理の合計価格
    unordered_map<int, int> total;

    string cmd;
    while (cin >> cmd) {
        if (cmd == "received") {
            // 注文受理情報
            cin >> cmd; // "order"
            int T, D;
            cin >> T >> D;

            unserved[T]++;
            total[T] += menus[D].price;

        } else if (cmd == "ready") {
            // 注文提供情報
            int T, D;
            cin >> T >> D;

            unserved[T]--;

        } else {
            // 会計申請情報
            int T;
            cin >> T;

            if (unserved[T]) {
                cout << "please wait" << endl;
            } else {
                cout << total[T] << endl;
                total.erase(T);
            }
        }
    }
}

int main(int argc, char *argv[]) {
    int step;
    cin >> step;

    switch (step) {
        case 1: step_1(); break;
        case 2: step_2(); break;
        case 3: step_3(); break;
        default: step_4(); break;
    }

    return 0;
}
