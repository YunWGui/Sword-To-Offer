## 模板

- Bubble Sort
- Merge Sort
- Insertion Sort
- Selection Sort
- Quick Sort
- Heap Sort

----

####  Bubble Sort

> 起泡排序，P60
>
> 平均时间复杂度：$O(n^2)$，最好情况：$O(n)$，最坏情况：$O(n^2)$
>
> 空间复杂度：$O(1)$
>
> In-place 排序，稳定

```cpp
void bubbleSort( vector<int>& nums, int low, int high ) {  // [low, high)
    if ( high <= 1 )
        return;

    for ( int i = 0; i < high; ++i ) {
        bool flag = false;  // 提前退出冒泡循环的标志位
        for ( int j = 0; j < high - i - 1; ++j ) {
            if ( nums[j] > nums[j+1] ) {
                swap( nums[j], nums[j+1] );
                flag = true;  // 表示「有」数据交换
            }
        }
        if ( flag == false )
            break;  // 「没有」数据交换，提前退出
    }
}
```

#### Merge Sort

> 归并排序，P61
>
> 平均时间复杂度：$O(nlogn)$，最好情况：$O(nlogn)$，最坏情况：$O(nlogn)$
>
> 空间复杂度：$O(n)$
>
> Out-place 排序，稳定

是第一个在最坏情况下依然保持 $O(nlogn)$ 运行时间的确定性排序算法

```cpp
class MSort {
public:
    void mergeSort( vector<int>& nums, int low, int high ) {  // [low, high]
        if ( high - low < 1 )
            return;
        
        int mid = low + ( ( high - low ) >> 1 );
        mergeSort( nums, low, mid );
        mergeSort( nums, mid + 1, high );
        
        merge( nums, low, mid, high );
    }

    void merge( vector<int>& nums, int low, int mid, int high ) {
        int n1 = mid - low + 1;
        int n2 = high - mid;
        vector<int> Left( n1 ), Right( n2 );

        for ( int i = 0; i < n1; ++i )
            Left[i] = nums[low + i];
        for ( int j = 0; j < n2; ++j )
            Right[j] = nums[mid + 1 + j];
        // 排序
        int i = 0, j = 0, k = low;
        while ( i < n1 && j < n2 ) {
            if ( Left[i] <= Right[j] )
                nums[k++] = Left[i++];
            else 
                nums[k++] = Right[j++];
        }
        while ( i < n1 )
            nums[k++] = Left[i++];
        while ( j < n2 )
            nums[k++] = Right[j++];
    }
};
```

#### Insertion Sort

> 插入排序，P79
>
> 平均时间复杂度：$O(n^2)$，最好情况：$O(n)$，最坏情况：$O(n^2)$
>
> 空间复杂度：$O(1)$
>
> 排序方式：In-place 排序，稳定

将数组中的数据分为两个区间，**已排序区间**和**未排序区间**。**初始**已排序区间只有一个元素，即数组的第一个元素。

**核心思想：**取未排序区间中的元素，在已排序区间中找到合适的插入位置将其插入，并保证已排序区间数据一定有序。重复这个过程，直到未排序区间中元素为空，算法结束。

```cpp
void insertionSort( vector<int>& nums, int low, int high ) {  // [low, high)
    for ( int i = 1; i < high; ++i ) {  // 默认数组第一个元素「已排序」
        int value = nums[i];
        int j = i - 1;
        for ( ; j >= 0; --j ) {
            if ( value < nums[j] ) 
                nums[j+1] = nums[j];  // 移动数据
            else
                break;  
        }   
        nums[j+1] = value;  // 插入数据            
    }
}
```

#### Selection Sort

> 选择排序，P80
>
> 平均时间复杂度：$O(n^2)$，最好情况：$O(n^2)$，最坏情况：$O(n^2)$
>
> 空间复杂度：$O(1)$
>
> In-place 排序，不稳定

**实现思路：**类似插入排序，也分**已排序区间**和**未排序区间**。但是：选择排序每次会从未排序区间中找到最小的元素，将其放到已排序区间的末尾。

```cpp
void selectionSort( vector<int>& nums, int low, int high ) {  // [low, high]
    for ( int i = 0; i < high-1; ++i ) {
        int minIndex = i;
        for ( int j = i+1; j < high; ++j ) {
            if ( nums[j] < nums[minIndex] )
                minIndex = j;
        }
        swap( nums[i], nums[minIndex] );
    }
}
```

#### Quick Sort 

> 快速排序，P334
>
> 平均时间复杂度：$O(nlogn)$，最好情况：$O(nlogn)$，最坏情况：$O(n^2)$
>
> 空间复杂度：$O(logn)$
>
> In-place 排序，不稳定
>
> 「随机」快排

在实际应用中**首选**的排序算法

> 易于实现，代码结构紧凑简练
>
> 对于按通常规律随机分布的输入序列，快速排序算法实际的平均运行时间较之同类算法更少

```cpp
class QSort {
public:
    void quickSort( vector<int>& nums, int low, int high ) {  // [low, high]
        if ( high - low < 1 )  // 单元素区间
            return;
        
        int mid = partition( nums, low, high );  // [low, high]
        quickSort( nums, low, mid );  
        quickSort( nums, mid + 1, high );
    }

    int partition( vector<int>& nums, int low, int high ) {
        swap( nums[low], nums[low + rand() % (high - low + 1)] );
        int pivot = nums[low];

        while ( low < high ) {
            while ( ( low < high ) && ( pivot <= nums[high] ) )
                --high;
            nums[low] = nums[high];
            
            while ( ( low < high ) && ( nums[low] <= pivot ) )
                ++low;
            nums[high] = nums[low];
        }
        nums[low] = pivot;

        return low;
    }
};
```

#### Heap Sort

[heapSort - achieve (主要参考)](https://github.com/TheAlgorithms/C-Plus-Plus/blob/master/sorting/heap_sort.cpp)

[二叉堆详解实现优先级队列 - labuladong](https://labuladong.gitbook.io/algo/shu-ju-jie-gou-xi-lie/er-cha-dui-xiang-jie-shi-xian-you-xian-ji-dui-lie#wu-zui-hou-zong-jie)

[学习堆相关算法](https://blog.csdn.net/xiaolinnulidushu/article/details/104629479)

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