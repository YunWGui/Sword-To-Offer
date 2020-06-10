/*
题目：
    67. 把字符串转换成整数
备注：
    同 LeetCode-8 题
    https://leetcode-cn.com/problems/string-to-integer-atoi/
*/

#include <iostream>
using namespace std;

class Solution {
  public:
    int strToInt(string str) {
        int num = 0;
        int i = 0;
        bool isMinus = false;
        // 1. 检查空格
        while (str[i] == ' ') 
            ++i;
        
        // 2. 检查符号
        if (str[i] == '-') 
            isMinus = true;
        if (str[i] == '+' || str[i] == '-')  // 存在正、负号
            ++i;
        
        // 3. 计算数字
        while ( i < str.size() && '0' <= str[i] && str[i] <= '9' ) {
            int temp = str[i] - '0';
            // ------ 4. 处理溢出，这是关键步骤 ------
            if (num > INT_MAX / 10 || (num == INT_MAX / 10 && temp > 7)) 
                return isMinus ? INT_MIN : INT_MAX;            
            // --------------------------------------
            num = num * 10 + temp;
            ++i;
        }
        return isMinus ? -num : num;
    }
};

int main()
{
    

    return 0;
}