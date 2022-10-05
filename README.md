# C++ 高精度算法整理

- 支持加、减、乘、除、取余
- 支持输入输出
- 支持结构体

## 如何使用?

拷贝 `lib` 下的 `haa.h` 到你的编译器库存储的地方。然后就可以使用了！

## 举个例子

1. 引入

``` cpp
#include <haa.h>
using namespace haa;
```

2. 声明高精度数字

``` cpp
// 空的数字
BigINT num;
// 直接赋值
BigINT num = BigINT("11111");
```

3. 输入输出

``` cpp
// 输入
num.put_line();
// 输出
num.print_line();
```

4. 加法

``` cpp
BigINT a, b;
a.put_line();
b.put_line();
cout << a.plus(b).stringify() << endl;
```

## License

`MIT License`
