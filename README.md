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

2. 双指针法: 核心一个快指针用来寻找数组中需要保留的元素值，一个慢指针用指向更新后的数组下标值。
