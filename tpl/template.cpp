// !ifdef NOLIB
// #define USE_MODINT

// !endif
#pragma region "Template"

#ifdef DEBUG
#include "template.hpp"
#else
// !template
#endif

// clang-format on

void solve();
int main() {
    cout << fixed << setprecision(16);
    solve();
    return 0;
}

#pragma endregion

DEFINE_MOD(MOD2);

void solve() {
}
