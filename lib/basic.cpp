#include "../tpl/template.cpp"

#pragma region "天井・床関数"

ll llceil(ll a, ll b) {
    if (a % b == 0) return a / b;

    if (a >= 0) return (a / b) + 1;
    else return -((-a) / b);
}

ll llfloor(ll a, ll b) {
    if (a % b == 0) return a / b;

    if (a >= 0) return (a / b);
    else return -((-a) / b) - 1;
}

#pragma endregion
