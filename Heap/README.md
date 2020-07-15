- [heapSort - achieve (主要参考)](https://github.com/TheAlgorithms/C-Plus-Plus/blob/master/sorting/heap_sort.cpp)

- [二叉堆详解实现优先级队列 - labuladong](https://labuladong.gitbook.io/algo/shu-ju-jie-gou-xi-lie/er-cha-dui-xiang-jie-shi-xian-you-xian-ji-dui-lie#wu-zui-hou-zong-jie)

- [学习堆相关算法](https://blog.csdn.net/xiaolinnulidushu/article/details/104629479)

```cpp
class HSort {
public:
    void heapSort( vector<int>& nums ) {
        int n = nums.size();

        for ( int i = n - 1; i >= 0; --i )  // 自底而上，原地建堆
            heapify( nums, n, i );
        
        for ( int i = n - 1; i >= 0; --i ) {
            swap( nums[i], nums[0] );
            heapify( nums, i, 0 );  // 自顶而下
        }
    }

    void heapify( vector<int>& nums, int n, int parent ) {
        int maxIndex = parent;
        int leftChild = parent * 2 + 1;
        int rightChild = parent * 2 + 2;

        if ( leftChild < n && nums[maxIndex] < nums[leftChild] )
            maxIndex = leftChild;
        if ( rightChild < n && nums[maxIndex] < nums[rightChild] )
            maxIndex = rightChild;
        
        if ( maxIndex != parent ) {
            swap( nums[maxIndex], nums[parent] );
            heapify( nums, n, maxIndex );
        }
    }
};
```

