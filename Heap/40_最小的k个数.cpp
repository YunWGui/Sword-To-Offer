/*
地址：
	acwing : https://www.acwing.com/problem/content/49/
	牛客 : https://www.nowcoder.com/practice/6a296eb82cf844ca8539b57c23e6e9bf
	LeetCode : https://leetcode-cn.com/problems/zui-xiao-de-kge-shu-lcof/
题目：
	40. 最小的 K 个数  P209
描述：
	输入 n 个整数，找出其中最小的 k 个数。
*/


#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>  // priority
#include <functional>  // greater
using namespace std;


// 方法四：最小堆 - STL 容器
class Solution_4 {
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        vector<int> res;
        priority_queue<int, vector<int>, greater<int>> pq;

        for ( int i = 0; i < (int)arr.size(); ++i )
            pq.push( arr[i] );
        
        for ( int i = 0; i < k; ++i ) {
            res.push_back( pq.top() );
            pq.pop();
        }

        return res;
    }
};

// 方法二：堆排序 - 最小堆
class Solution_2 {
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {  
        int n = arr.size();
        vector<int> res;
        
        for ( int i = n - 1; i >= 0; --i )
            heapify( arr, n, i );
        
        for ( int i = n - 1; i >= 0; --i ) {
            if ( k < 1 )
                break;

            res.push_back( arr[0] );
            --k;
            
            swap( arr[i], arr[0] );
            heapify( arr, i, 0 );
        }

        return res;
    }

    void heapify( vector<int>& arr, int n, int parent ) {  // 最小堆
        int minIndex = parent;
        int leftChild = parent * 2 + 1;
        int rightChild = parent * 2 + 2;

        if ( leftChild < n && arr[leftChild] < arr[minIndex])
            minIndex = leftChild;
        
        if ( rightChild < n && arr[rightChild] < arr[minIndex] )
            minIndex = rightChild;

        if ( minIndex != parent ) {
            swap( arr[minIndex], arr[parent] );
            heapify( arr, n, minIndex );
        }
    }
};

// 方法三：快速排序
class Solution_3 {
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        vector<int> res;

        quickSort( arr, 0, arr.size() - 1 );

        for ( int i = 0; i < k; ++i )
            res.push_back( arr[i] );
        
        return res;
    }

    void quickSort( vector<int>& arr, int left, int right ) {
        if ( right - left < 1 ) 
            return;
        
        int mid = partition( arr, left, right );
        quickSort( arr, left, mid );
        quickSort( arr, mid + 1, right );
    }

    int partition( vector<int>& arr, int left, int right ) {
        swap( arr[left], arr[left + rand() % ( right - left + 1 )] );
        int pivot = arr[left];

        while ( left < right ) {
            while ( (left < right ) && ( pivot <= arr[right] ) )
                --right;
            arr[left] = arr[right];

            while ( ( left < right ) && ( arr[left] <= pivot ) )
                ++left;
            arr[right] = arr[left];
        }
        arr[left] = pivot;

        return left;
    }
};

// 方法一：排序
class Solution {
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        sort( arr.begin(), arr.end() );

        return vector<int> ( arr.begin(), arr.begin()+k );
    }
};


int main()
{

	return 0;
}
