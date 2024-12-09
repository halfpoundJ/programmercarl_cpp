# Some notes

注：本笔记仅用于个人刷题思考记录，所有内容均来自
[代码随想录](https://programmercarl.com/%E6%95%B0%E7%BB%84%E7%90%86%E8%AE%BA%E5%9F%BA%E7%A1%80.html)
。
## Day 1
[Binary Search](https://leetcode.com/problems/binary-search/)

两种方法：左闭右闭，左闭右开

1. 左闭右闭: 核心 while 循环判断 `left <= right`

   define `middle = left + (right - left) / 2`

   (case 1)target 在输入数组范围内，且在 middle 的左边 `target < nums[middle]` --> `right = middle - 1`
--> 重新进入循环判断。这里不能写 `right = middle`，因为已经判断过 target < nums[middle], 如果 right 还等于 middle 相当于判断区间没有改变，会进入死循环，case 2 同理。 

   (case 2)target 在输入数组范围内，且在 middle 的右边: `target > nums[middle]` --> `left = middle + 1`
   --> 重新进入循环判断。

   (case 3)target 在输入数组范围内, target 和 middle 相等: `return middle`

   (case 4)target 不在输入数组范围内: `return -1`


2. 左闭右开: 核心 while 循环判断 `left < right`

   define `middle = left + (right - left) / 2`
   
   (case 1)target 在输入数组范围内，且在 middle 的左边 `target < nums[middle]` --> `right = middle`
   --> 因为此时右区间为开区间，如果像方法一 `right = middle - 1` 会导致减完之后 left = right, 此时 [left,right) 是无意义的。
   --> 重新进入循环判断。
   
   (case 2)target 在输入数组范围内，且在 middle 的右边: `target > nums[middle]` --> `left = middle + 1`
   --> 重新进入循环判断。
   
   (case 3)target 在输入数组范围内, target 和 middle 相等: `return middle`
   
   (case 4)target 不在输入数组范围内: `return -1`

[Remove Element](https://leetcode.com/problems/remove-element/description/)

数组元素是连续的，只可覆盖不可以简单删除其中一个值。

1. 暴力解法: 核心两个 for 循环，一个遍历数组，另一个将剩余的部分向前移。

   注意第二个 for 循环每次移动后 i 都要减1，数组的 size 也要相应的减1。

2. 双指针法: 核心一个快指针用来寻找原数组中需要保留的元素值，一个慢指针用指向更新后的新数组下标值。核心是当 value 和 当前块指针指向内容不一致时候，数组保留，否则不保留 value 所对应的值，相当于数组向前移动。

## Day 2
[Squares of a Sorted Array](https://leetcode.com/problems/squares-of-a-sorted-array/)

1. 暴力解法：for 循环先把数组每个元素平方，在用sort 函数快排。时间复杂度为 O(n + nlogn)
2. 双指针法：
![双指针法图解](https://code-thinking.cdn.bcebos.com/gifs/977.%E6%9C%89%E5%BA%8F%E6%95%B0%E7%BB%84%E7%9A%84%E5%B9%B3%E6%96%B9.gif)

核心： 由于数组有序且含有负数，则最大值一定在数组的两端--> 定义两个分别指向数组两端的指针，比较大小再放入新数组里面。如何放入新数组？--> 定义一个指向新数组尾端的指针，当左边平方值大于右边平方值的时候，将左边的平方值放入新数组的最后，并且由于左边的值已经放入新数组了，需要将左边指针向后移，即 i++。

[Minimum Size Subarray Sum](https://leetcode.com/problems/minimum-size-subarray-sum/description/)

1. 暴力解法：两个 for 循环遍历所有集合的情况，如果集合内所有元素和大于 target ，取集合长度并且更新 result，不断取最小的 result。
2. 滑动窗口法：核心一个 for 循环，j 表示滑动窗口终止位置。当集合内元素和大于 target ，取集合长度，移动滑窗起始位置 i 。其中需要用 while 而不是 if 来判断 sum 是否大于目标值，因为需要持续的向后滑窗。结果 result 应该初始为最大值 INT32_MAX, 然后不断与当前 result 值比较，达到取到最小的数组长度的目的。
![滑动窗口图解](https://code-thinking.cdn.bcebos.com/gifs/209.%E9%95%BF%E5%BA%A6%E6%9C%80%E5%B0%8F%E7%9A%84%E5%AD%90%E6%95%B0%E7%BB%84.gif)

[Spiral Matrix II](https://leetcode.com/problems/spiral-matrix-ii/description/)

核心思路：遍历每一边遵循左闭右开原则，逆时针旋转填充，从外向里

## Day 3
链表基本定义
```cpp
// 单链表
struct ListNode {
   int val;  // 节点上存储的元素
   ListNode *next;  // 指向下一个节点的指针
   ListNode(int x) : val(x), next(NULL) {}  // 节点的构造函数
};
```
构造函数可以在创建ListNode节点时候同时初始化。

![数组和链表的对比](https://code-thinking-1253855093.file.myqcloud.com/pics/20200806195200276.png)

[Remove Linked List Elements](https://leetcode.com/problems/remove-linked-list-elements/description/)

1. 不使用虚拟节点：需要判断 target 是不是头节点。cur 指针一定指向要删除的节点的上一个节点。
2. 使用虚拟节点 dummyHead 核心：
`ListNode* dummyHead = new ListNode(0);` 设置了一个指向 head 的指针。不需要判断 target 是否是头节点
，最后返回的是 dummyHead 的下一个节点。

[Design Linked List](https://leetcode.com/problems/design-linked-list/description/)

核心查找 index 所在链表位置的方式：

```
while(index--) {
    cur = cur->next;
}
```

[Reverse Linked List](https://leetcode.com/problems/reverse-linked-list/description/)

1. 双指针法核心：定义两个指针 prev 指向 NULL 和 cur 指向 head。再定义
一个 temp 临时指针用来存储 cur->next 以便之后 cur->next 翻转。通过将
temp 赋值给 cur 即将 cur 移动到 temp 的位置，将 prev 移动到 cur 位置
来实现遍历。
2. 递归法核心：将双指针法中 prev 和 cur 赋值放在函数输入中。