# C++ 高精度算法整理

- 支持加、减、乘、除、取余
- 支持输入输出
- 支持结构体

## 如何使用?

拷贝 `lib` 下的 `haa.h` 到你的编译器库存储的地方。然后就可以使用了！

## 举个例子

``` cpp
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
    string s1, s2;                                                 // -----1
    cin >> s1 >> s2;                                               // |输入|1
    BigINT n1 = BigINT(s1), n2 = BigINT(s2);                       // -----1
    BigINT sum = n1 + n2;                                          // |求和|2
    for (BigINT i = ONE; !i.big(n1); i = i.plus(ONE)) {            // -----3
        cout << ".";                                               // |   |3
    }                                                              // |   |3
    for (BigINT i = ONE; !i.big(n2); i = i.plus(ONE)) {            // |   |3
        cout << "~";                                               // |   |3
    }                                                              // |循环|3
    cout << " " << n1.stringify() << " " << n2.stringify() << endl;// |输出|3
    for (BigINT i = ONE; !i.big(sum); i = i.plus(ONE)) {           // |   |3
        cout << "-";                                               // |   |3
    }                                                              // |   |3
    cout << " " << sum.stringify() << endl;                        // -----3
    return 0;
}
```

## License

`MIT License`
