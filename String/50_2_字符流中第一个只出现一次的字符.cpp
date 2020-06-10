/*
地址：
	acwing :
	牛客 :
题目：
    50.2 字符流中第一个只出现一次的字符  P247
描述：
    请实现一个函数，用来找出字符流中第一个只出现一次的字符。
    例如，当从字符流中只读出前两个字符 "go" 时，第一个只出现一次的字符是 'g'；当从该
字符流中读出前 6 个字符 "google" 时，第一个只出现一次的字符是 "l"。
*/

#include <iostream>
#include <queue>
#include <unordered_map>
using namespace std;

class Solution{
public:
    //Insert one char from stringstream

    queue<char> Q;
    unordered_map<char,int> M;
    void insert(char ch){
        if (M[ch] == 0) {
            Q.push(ch);
        }
        M[ch] += 1;
    }
    //return the first appearence once char in current stringstream
    char firstAppearingOnce(){
        while (!Q.empty() && M[Q.front()] >= 2) {
            Q.pop();
        }
        return Q.empty() ? '#' : Q.front();
    }
};


int main()
{


	return 0;
}
