/*
题目：
	13. 机器人的运动范围
描述：
	地上有一个 m 行 n 列的方格。
	一个机器人从坐标(0, 0)的格子开始移动，它每次可以向左、右、上、下移动一格，但不能进入
	行坐标和列坐标的数位之和大于 k 的格子。
	例如：当 k 为 18 时，机器人能够进入方格(35, 37)，因为 3 + 5 + 3 + 7 = 18。但不能
	进入方格(35, 38)，因为 3 + 5 + 3 + 8 = 19.
	请问该机器人能够到达多少个格子？
地址：
    https://leetcode-cn.com/problems/ji-qi-ren-de-yun-dong-fan-wei-lcof/
*/


#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// 方法三：BFS / 广度优先搜索
// https://www.acwing.com/solution/acwing/content/730/
/*
思路：
    这是一个典型的「广度优先搜索」问题，从 (0, 0) 开始，每次朝上、下、左、右四个方向
    扩展新的节点即可。
    扩展时，需要注意新的节点需要满足如下条件：
        - 之前没有遍历过，这个可以用 bool 数组来判断
        - 没有越界
        - 横纵坐标的各位数字之后小于 k
    最后，答案就是所有遍历过的合法的节点个数

时间复杂度：O(nm)
    每个节点最多只会「入队」一次，所以时间复杂度不会超过方格中的节点个数。
    最坏情况下，会遍历方格中的所有点，所以时间复杂度为 O(nm)
*/
class Solution_3 {
public:
    int movingCount(int m, int n, int k) {
		if ( m == 0 || n == 0 )
			return 0;
		
		queue<pair<int, int>> Q;
		vector<vector<bool>> visited( m, vector<bool>( n, false ) );

		int dx[2] = { 0, 1 };
		int dy[2] = { 1, 0 };
		int count = 0;

		Q.push( { 0, 0 } );
		while ( !Q.empty() ) {
			auto temp = Q.front(); Q.pop();
			
            // 已经被访问 || 行坐标和列坐标的数位之和大于k
			if ( visited[temp.first][temp.second] || get_sum( temp ) > k )
				continue;
			
			++count;
			visited[temp.first][temp.second] = true;  // 标记为「已访问」 
			for ( int i = 0; i < 2; ++i ) {
				int x = temp.first + dx[i];
				int y = temp.second + dy[i];
				
				if ( x >= 0 && x < m && y >= 0 && y < n )
					Q.push( { x, y } );
			}
		}
		
		return count;		
    }

	int get_sum( pair<int, int> P ) {
		int res = 0;
		while ( P.first ) {
			res += P.first % 10;
			P.first /= 10;
		}
		while ( P.second ) {
			res += P.second % 10;
			P.second /= 10;
		}

		return res;
	}
};


// 方法一：DFS
class Solution {
public:
    int movingCount(int m, int n, int k) {
        vector<vector<int>> vec ( m, vector<int>( n, 0 ) );
        int count = 0;
        
        dfs( 0, 0, m, n, k, count, vec );

        return count;
    }

    void dfs( int row, int col, int m, int n, int k, int& count, vector<vector<int>>& vec ) {
        if ( row < 0 || row >= m || col < 0 || col >= n )  // 越界
            return;
        if ( row / 10 + row % 10 + col / 10 + col % 10 > k )  // 行坐标和列坐标的数位之和大于k
            return;
        if ( vec[row][col] == 1 )  // 该格子「已访问」
            return;
        
        vec[row][col] = 1;  // 标记为「已访问」
        ++count;
        
        // 只需判断右、下两个方向即可
        dfs( row + 1, col, m, n, k, count, vec );
        dfs( row, col + 1, m, n, k, count, vec );
    }
};


// 方法二：深度优先搜索
// https://leetcode-cn.com/problems/ji-qi-ren-de-yun-dong-fan-wei-lcof/solution/c-di-gui-jia-jian-zhi-by-he-fei-si-tuo-si-r/
class Solution_2 {
private:
    int M, N, K;
    vector<vector<int>> vec;
public:
    int movingCount(int m, int n, int k) {
        M = m;
        N = n;
        K = k;
        vec.resize( m, vector<int>( n, 0 ) );

        return dfs( 0, 0 );
    }

    int dfs ( int row, int col ) {
        if ( row < 0 || row >= M || col < 0 || col >= N )  // 越界
            return 0;
        if ( row / 10 + row % 10 + col / 10 + col % 10 > K )
            return 0;
        if ( vec[row][col] == 1 )
            return 0;
        
        vec[row][col] = 1;
        // 只需判断右、下两个方向即可
        return 1 + dfs( row + 1, col ) + dfs( row, col + 1 );  
    }
};


int main()
{
	

	return 0;
}