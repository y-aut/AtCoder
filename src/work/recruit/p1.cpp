#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;

        int state = 0;
        if (b <= 60) state++;
        if (a + b <= 100) state++;

        if (state == 0) cout << "pass" << endl;
        else if (state == 1) cout << "reexamination" << endl;
        else cout << "fail" << endl;
    }

    return 0;
}
