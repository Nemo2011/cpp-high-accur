#include <iostream>
#include "lib/haa.h"
using namespace std;
using namespace haa;

int main() {
    string sa, sb;
    cin >> sa >> sb;
    BigINT a = BigINT(sa);
    BigINT b = BigINT(sb);
    cout << (a + b).stringify();
}