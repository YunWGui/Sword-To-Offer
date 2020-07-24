#### 二分查找模板

```cpp
int binarySearch( vector<int>& nums, int target ) {
	int low = 0, high = nums.size() - 1;  // 左闭右闭区间 [low, right]
    
	while ( low <= high ) {  // 取「等号」
		int mid = low + ( (high-low)>>1 );
		if ( nums[mid] < target )
			low = mid + 1;
		else if ( target < nums[mid] )
			high = mid - 1;
		else
			return mid;
	}
	return -1;  // 查找失败
}
```

