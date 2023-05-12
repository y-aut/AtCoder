#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <string.h>
#include <string>
#include <time.h>
#include <unordered_set>
#include <vector>
using namespace std;

// 入札の情報
struct Bid {
    time_t time;
    string user_id;
    int price;

    Bid(time_t _time, string &_user_id, int _price) : time(_time), user_id(_user_id), price(_price) {}
};

// 出品された商品の情報
struct Item {
    time_t time;
    string id;
    string user_id;
    int min_price;
    // 指定しないときは -1 となる
    int bin_price;
    time_t etime;

private:
    // 現在の入札一覧．処理が行われた順番で格納される
    vector<Bid> bids;
    // 現在の最高額の入札へのイテレータ
    vector<Bid>::iterator highest_bid;

public:
    Item(time_t _time, string &_id, string &_user_id, int _min_price, int _bin_price, time_t _etime)
        : time(_time), id(_id), user_id(_user_id), min_price(_min_price), bin_price(_bin_price), etime(_etime) {}

    int get_current_price() const {
        if (bids.empty()) return 0;
        return highest_bid->price;
    }

    string get_highest_bidder() const {
        if (bids.empty()) return "";
        return highest_bid->user_id;
    }

    void bid(time_t time, string &user_id, int price) {
        auto current = get_current_price();
        bids.emplace_back(time, user_id, price);
        if (price > current) {
            highest_bid = bids.end() - 1;
        }
    }

    // 入札を取り消す．ユーザーが入札していない場合，false を返す
    bool bid_cancel(string &user_id) {
        auto itr = remove_if(bids.begin(), bids.end(), [&user_id](Bid &b) { return b.user_id == user_id; });
        if (itr == bids.end()) {
            return false;
        }
        bids.erase(itr, bids.end());
        // 最高額入札を更新
        int max_price = 0;
        for (auto itr = bids.begin(); itr != bids.end(); itr++) {
            if (itr->price > max_price) {
                max_price = itr->price;
                highest_bid = itr;
            }
        }
        return true;
    }
};

// 出品中の商品のリスト
map<string, Item> items;
// 出品されたことがある商品 ID のリスト
unordered_set<string> item_ids;

// 時刻をパースする
inline time_t parse_time(string &s) {
    tm tm;
    memset(&tm, 0, sizeof(struct tm));
    strptime(s.c_str(), "%Y-%m-%dT%H:%M", &tm);
    return mktime(&tm);
}

// 時刻を文字列に変換する
inline string time_to_string(time_t time) {
    auto tm = localtime(&time);
    char buf[128];
    strftime(buf, sizeof(buf), "%Y-%m-%dT%H:%M", tm);
    return buf;
}

// current_price, bin_price, highest_bidder の順に出力する
void output_info(Item &item) {
    if (item.get_current_price() == 0) {
        cout << "-";
    } else {
        cout << item.get_current_price();
    }
    cout << " ";
    if (item.bin_price == -1) {
        cout << "-";
    } else {
        cout << item.bin_price;
    }
    cout << " ";
    if (item.get_current_price() == 0) {
        cout << "-";
    } else {
        cout << item.get_highest_bidder();
    }
    cout << endl;
}

// オークションを終了する
void finish_auction(time_t finished_time, Item &item) {
    cout << "AUCTION_FINISHED: " << time_to_string(finished_time) << " " << item.id << " ";
    output_info(item);
}

// 出品リクエストを処理する
void sell_request(time_t time, string &user_id, string &item_id) {
    int min_price, bin_price;
    string bin_price_s, etime_s;
    cin >> min_price >> bin_price_s >> etime_s;
    auto etime = parse_time(etime_s);

    if (bin_price_s == "-") {
        bin_price = -1;
    } else {
        bin_price = stoi(bin_price_s);
    }

    if (item_ids.count(item_id)) {
        cout << "SELL: this item_id is already in use" << endl;
        return;
    }

    items.emplace(item_id, Item(time, item_id, user_id, min_price, bin_price, etime));
    item_ids.emplace(item_id);
    cout << "SELL: accepted" << endl;
}

// 出品取り消しリクエストを処理する
void sell_cancel_request(time_t time, string &user_id, string &item_id) {
    auto itr = items.find(item_id);
    if (itr == items.end()) {
        cout << "SELL_CANCEL: this item is currently not for sale" << endl;
        return;
    }
    if (itr->second.user_id != user_id) {
        cout << "SELL_CANCEL: user is not the seller of this item" << endl;
        return;
    }

    items.erase(item_id);
    cout << "SELL_CANCEL: accepted" << endl;
}

// 入札リクエストを処理する
void bid_request(time_t time, string &user_id, string &item_id) {
    int price;
    cin >> price;

    auto itr = items.find(item_id);
    if (itr == items.end()) {
        cout << "BID: this item is currently not for sale" << endl;
        return;
    }
    auto &item = itr->second;
    if (item.user_id == user_id) {
        cout << "BID: user is the seller of this item" << endl;
        return;
    }
    if (price < item.min_price) {
        cout << "BID: the bid is lower than the minimum price" << endl;
        return;
    }
    if (item.bin_price != -1 && price > item.bin_price) {
        cout << "BID: the bid is higher than the BIN price" << endl;
        return;
    }
    if (price <= item.get_current_price()) {
        cout << "BID: the price must higher than the user's previous highest bid" << endl;
        return;
    }

    item.bid(time, user_id, price);
    cout << "BID: " << item.get_current_price() << " ";
    if (item.bin_price == -1) {
        cout << "-";
    } else {
        cout << item.bin_price;
    }
    cout << " " << item.get_highest_bidder() << endl;

    if (price == item.bin_price) {
        // 即落札
        finish_auction(time, item);
        items.erase(item_id);
    }
}

// 入札取り消しリクエストを処理する
void bid_cancel_request(time_t time, string &user_id, string &item_id) {
    auto itr = items.find(item_id);
    if (itr == items.end()) {
        cout << "BID_CANCEL: this item is currently not for sale" << endl;
        return;
    }
    auto &item = itr->second;
    if (!item.bid_cancel(user_id)) {
        cout << "BID_CANCEL: user has not bid on the item" << endl;
        return;
    }

    cout << "BID_CANCEL: ";
    output_info(item);
}

// 終了時刻となった出品を終了する
void update_items(time_t time) {
    map<time_t, set<string>> list;
    for (auto i : items) {
        if (i.second.etime < time) {
            list[i.second.etime].insert(i.first);
        }
    }
    for (auto i : list) {
        for (auto j : i.second) {
            finish_auction(i.first, items.find(j)->second);
            items.erase(j);
        }
    }
}

// 全商品の出品を終了する
void finish_all() {
    map<time_t, set<string>> list;
    for (auto i : items) {
        list[i.second.etime].insert(i.first);
    }
    for (auto i : list) {
        for (auto j : i.second) {
            finish_auction(i.first, items.find(j)->second);
        }
    }
    items.clear();
}

#include <fstream>
int main() {
    ifstream in("/home/y_aut/AtCoder/in.txt");
    cin.rdbuf(in.rdbuf());

    string time_s;
    while (cin >> time_s) {
        auto time = parse_time(time_s);

        // 終了時刻となった出品を終了
        update_items(time);

        string cmd, user_id, item_id;
        cin >> cmd >> user_id >> item_id;

        if (cmd == "SELL") {
            sell_request(time, user_id, item_id);
        } else if (cmd == "SELL_CANCEL") {
            sell_cancel_request(time, user_id, item_id);
        } else if (cmd == "BID") {
            bid_request(time, user_id, item_id);
        } else if (cmd == "BID_CANCEL") {
            bid_cancel_request(time, user_id, item_id);
        } else {
            cout << "Unsupported command: " << cmd << endl;
            return 1;
        }
    }

    // 全商品の出品を終了
    finish_all();

    return 0;
}
