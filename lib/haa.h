/**
 * @file haa.hpp
 * @author Nemo2011 (yimoxia@outlook.com)
 * @brief C++ 高精度算法
 * @version 2022.10.07
 * @date 2022-10-07
 * 
 * @copyright Copyright (c) 2022 Nemo2011
 * 
 * This is a C++ LIBRARY. You can't use it in C! 
 * 
 */

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

#define MAX_SIZE 10000
#define __MAX_SIZE MAX_SIZE + 5

/**
 * @brief 高精度算法命名空间
 * 
 */
namespace haa
{
    /**
     * @brief 高精度正整数
     */
    struct BigINT
    {
        // __num[0] 是长度，其他位是数值
        int __num[__MAX_SIZE];
        /**
         * @brief 构造器
         *
         * @param s 初始数值
         */
        BigINT(string s = "")
        {
            for (int i = 0; i < __MAX_SIZE; i++)
            {
                __num[i] = 0;
            }
            while (true) {
                if (s[0] == '0') 
                {
                    s.erase(0, 1);
                    continue;
                }
                else 
                {
                    break;
                }
            }
            __num[0] = s.length();
            for (int i = 1; i <= s.length(); i++)
            {
                __num[i] = s[__num[0] - i] - '0';
            }
            if (s == "") {
                __num[0] = 1;
                __num[1] = 0;
            }
        }
        /**
         * @brief 清空
         *
         */
        void clear()
        {
            for (int i = 0; i < __MAX_SIZE; i++)
            {
                __num[i] = 0;
            }
        }
        /**
         * @brief 获取长度
         *
         * @return int
         */
        int length()
        {
            return __num[0];
        }
        /**
         * @brief 输出
         *
         */
        void print_line()
        {
            for (int i = __num[0]; i >= 1; i--)
            {
                cout << __num[i];
            }
            cout << endl;
        }
        /**
         * @brief 输入
         *
         */
        void put_line()
        {
            clear();
            string s;
            cin >> s;
            while (true) {
                if (s[0] == '0') 
                {
                    s.erase(0, 1);
                    continue;
                }
                else 
                {
                    break;
                }
            }
            __num[0] = s.length();
            for (int i = 1; i <= s.length(); i++)
            {
                __num[i] = s[__num[0] - i] - '0';
            }
        }
        /**
         * @brief 转换为 string
         *
         * @return string
         */
        string stringify()
        {
            string s = "";
            for (int i = __num[0]; i >= 1; i--)
            {
                s = s + (char)(__num[i] + '0');
            }
            return s;
        }
        /**
         * @brief 转换为 long long
         *
         * @return long long
         */
        long long long_long()
        {
            long long l = 0;
            long long val = 1;
            for (int i = 1; i <= length(); i++)
            {
                l += val * __num[i];
                val *= 10;
            }
            return l;
        }
        /**
         * @brief 拷贝
         *
         * @return BigINT
         */
        BigINT copy()
        {
            return BigINT(stringify());
        }
        /**
         * @brief 加法
         *
         * @param a 加数
         * @return BigINT
         */
        BigINT plus(BigINT a)
        {
            BigINT b;
            int m = max(length(), a.length());
            for (int i = 1; i <= m; i++)
            {
                b.__num[i] += __num[i] + a.__num[i];
                b.__num[i + 1] += b.__num[i] / 10;
                b.__num[i] = b.__num[i] % 10;
            }
            int l = m + 1;
            while (b.__num[l] == 0 && l > 1)
            {
                l--;
            }
            b.__num[0] = l;
            return b;
        }
        /**
         * @brief 是否比一个数大
         *
         * @param a 比较的数
         * @return bool
         */
        bool big(BigINT a)
        {
            if (a.length() != length())
            {
                return length() > a.length();
            }
            for (int i = length(); i >= 1; i--)
            {
                if (a.__num[i] > __num[i])
                {
                    return 0;
                }
                if (a.__num[i] < __num[i])
                {
                    return 1;
                }
            }
            return 0;
        }
        /**
         * @brief 比较是否与一个数相等
         *
         * @param a 比较的数
         * @return bool
         */
        bool equal(BigINT a)
        {
            if (a.length() != length())
            {
                return 0;
            }
            for (int i = 1; i <= length(); i++)
            {
                if (a.__num[i] != __num[i])
                {
                    return 0;
                }
            }
            return 1;
        }
        /**
         * @brief 减法
         *
         * @param a 减数
         * @return BigINT
         */
        BigINT minus(BigINT a)
        {
            if (big(a) || equal(a))
            {
                BigINT result;
                int self_copy[__MAX_SIZE];
                self_copy[0] = length();
                for (int i = 1; i <= length(); i++)
                {
                    self_copy[i] = __num[i];
                }
                for (int i = 1; i <= __num[0]; i++)
                {
                    if (__num[i] < a.__num[i])
                    {
                        self_copy[i] += 10;
                        self_copy[i + 1]--;
                    }
                    result.__num[i] = self_copy[i] - a.__num[i];
                }
                int l = length();
                while (result.__num[l] == 0 && l > 1)
                {
                    l--;
                }
                result.__num[0] = l;
                return result;
            }
            else
            {
                // 结果为负数
                return BigINT();
            }
        }
        /**
         * @brief 乘法
         *
         * @param a 乘数
         * @return BigINT
         */
        BigINT times(BigINT a)
        {
            BigINT result;
            for (int i = 1; i <= length(); i++)
            {
                for (int j = 1; j <= a.length(); j++)
                {
                    result.__num[i + j - 1] += __num[i] * a.__num[j];
                    result.__num[i + j] += result.__num[i + j - 1] / 10;
                    result.__num[i + j - 1] %= 10;
                }
            }
            int l = length() + a.length();
            while (result.__num[l] == 0 && l > 1)
            {
                l--;
            }
            result.__num[0] = l;
            return result;
        }
        /**
         * @brief 除法
         *
         * @param a 除数
         * @return BigINT
         */
        BigINT divide(BigINT a)
        {
            BigINT result;
            int l = __num[0] - a.__num[0] + 1;
            BigINT temp;
            BigINT self_cpy = copy();
            for (int i = l; i > 0; i--)
            {
                temp.clear();
                for (int j = 1; j <= a.length(); j++)
                {
                    temp.__num[i + j - 1] = a.__num[j];
                }
                temp.__num[0] = a.__num[0] + i - 1;
                while (self_cpy.big(temp) || self_cpy.equal(temp))
                {
                    result.__num[i]++;
                    self_cpy = self_cpy.minus(temp);
                }
            }
            while (result.__num[l] == 0 && l > 1)
            {
                l--;
            }
            result.__num[0] = l;
            return result;
        }
        /**
         * @brief 取余
         *
         * @param a 除数
         * @return BigINT
         */
        BigINT mod(BigINT a)
        {
            int l = __num[0] - a.__num[0] + 1;
            BigINT temp;
            BigINT self_cpy = copy();
            for (int i = l; i > 0; i--)
            {
                temp.clear();
                for (int j = 1; j <= a.length(); j++)
                {
                    temp.__num[i + j - 1] = a.__num[j];
                }
                temp.__num[0] = a.__num[0] + i - 1;
                while (self_cpy.big(temp) || self_cpy.equal(temp))
                {
                    self_cpy = self_cpy.minus(temp);
                }
            }
            return self_cpy;
        }
        /**
         * @brief 乘方
         * 
         * @param a 次方数
         * @return BigINT 
         */
        BigINT power(BigINT a)
        {
            BigINT result = BigINT("1");
            for (BigINT i = BigINT("1"); !i.big(a); i = i.plus(BigINT("1"))) {
                result = result.times(copy());
            }
            return result;
        }
    };
    /**
     * @brief 设置一个数字的最长长度
     * 
     * @param len 长度
     */
    void MAX_LENGTH(int len) {
        #ifdef __MAX_SIZE
        #undef __MAX_SIZE
        #undef MAX_SIZE
        #endif
        #define MAX_SIZE len
        #define __MAX_SIZE MAX_SIZE + 5
    }
    // 常用常量
    const BigINT ZERO = BigINT("0");
    const BigINT ONE = BigINT("1");
}


haa::BigINT operator+(haa::BigINT a, haa::BigINT b)
{
    return a.plus(b);
}
haa::BigINT operator-(haa::BigINT a, haa::BigINT b)
{
    return a.minus(b);
}
bool operator<(haa::BigINT a, haa::BigINT b)
{
    return (!a.big(b)) && (!a.equal(b));
}
bool operator<=(haa::BigINT a, haa::BigINT b)
{
    return !a.big(b);
}
bool operator>(haa::BigINT a, haa::BigINT b)
{
    return a.big(b);
}
bool operator>=(haa::BigINT a, haa::BigINT b)
{
    return a.big(b) || a.equal(b);
}
bool operator==(haa::BigINT a, haa::BigINT b)
{
    return a.equal(b);
}
haa::BigINT operator*(haa::BigINT a, haa::BigINT b)
{
    return a.times(b);
}
haa::BigINT operator/(haa::BigINT a, haa::BigINT b)
{
    return a.divide(b);
}
haa::BigINT operator%(haa::BigINT a, haa::BigINT b)
{
    return a.mod(b);
}
