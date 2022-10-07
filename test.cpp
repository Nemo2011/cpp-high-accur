#include <iostream>
#include <string>
#include "lib/haa.hpp"
using namespace std;
using namespace haa;

int main() {
    /**
     * $> ./test
     * 2 3
     * ..~~~ 2 3
     * ----- 5
     * $> 
     */
    string s1, s2;
    cin >> s1 >> s2;
    BigINT n1 = BigINT(s1), n2 = BigINT(s2);
    BigINT sum = n1 + n2;
    for (BigINT i = ONE; !i.big(n1); i = i.plus(ONE)) {
        cout << ".";
    }
    for (BigINT i = ONE; !i.big(n2); i = i.plus(ONE)) {
        cout << "~";
    }
    cout << " " << n1.stringify() << " " << n2.stringify() << endl;
    for (BigINT i = ONE; !i.big(sum); i = i.plus(ONE)) {
        cout << "-";
    }
    cout << " " << sum.stringify() << endl;
    return 0;
}
