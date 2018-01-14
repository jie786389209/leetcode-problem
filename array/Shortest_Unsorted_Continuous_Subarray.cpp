Given an integer array, you need to find one continuous subarray that if you only sort this subarray in ascending order, then the whole array will be sorted in ascending order, too.

You need to find the shortest such subarray and output its length.

Example 1:
Input: [2, 6, 4, 8, 10, 9, 15]
Output: 5
Explanation: You need to sort [6, 4, 8, 10, 9] in ascending order to make the whole array sorted in ascending order.


/////////////////
Well, you’ve probably already seen the O(n) solution here. If you’ve ever wondered how it is done, here is a detailed explanation. It will begin with the naive O(nlogn) solution by sorting, then transition to the O(n) two-pass solution and eventually the O(n) one-pass solution.

I -- Naive solution by sorting
先排序再对比
///////////////////

public int findUnsortedSubarray(int[] nums) {
    int[] nums_sorted = Arrays.copyOf(nums, nums.length);
    Arrays.sort(nums_sorted);
        
    int i = 0, j = nums.length - 1;
        
    while (i < nums.length && nums[i] == nums_sorted[i]) i++;
    while (i < j && nums[j] == nums_sorted[j]) j--;
        
    return j - i + 1;
}

////////////////////////
II -- O(n) time two-pass solution
前后遍历，找出逆序数（前面递增，后面递减），因为要找最短，所以要找出中间逆序段
的最大最小值，

It turns out that the two boundary indices i and j can be found in linear time, if we take advantage of the following three properties:

nums[0, i - 1] and nums[j + 1, n - 1] are both sorted.

nums[i] != nums_sorted[i] and nums[j] != nums_sorted[j].

nums[i - 1] <= min and max <= nums[j + 1], where min and max are the minimum and maximum values of subarray nums[i, j].

The first and third properties guarantee that the subarray nums[0, i - 1] will be exactly the same as subarray nums_sorted[0, i - 1], and the subarray nums[j + 1, n - 1] exactly the same as nums_sorted[j + 1, n - 1], while the second property ensures that i will be the first index at which the two elements of nums and nums_sorted are different and j be the last such index.

Since we aim at the shortest subarrays, from the first property alone, we need to find the two longest sorted subarrays starting at index 0 and ending at index n - 1, respectively. Assume the two subarrays are nums[0, l] and nums[r, n - 1]. If there is overlapping between these two subarrays, i.e.l >= r, then the whole array is sorted so 0 will be returned. Otherwise, the input array is not sorted. However, we cannot say sorting nums[l, r] will leave the whole array sorted, because at this moment the third property may not be satisfied.

To guarantee the third property, assume min and max are the minimum and maximum values of subarray nums[l, r], then we need to decrease l as long as nums[l] > min, and increase r as long as nums[r] < max. After this is done, it can be shown that the second property will be met automatically, and nums[l + 1, r - 1] will be the shortest subarray we are looking for (that is, i = l + 1 and j = r - 1).

Finding the longest subarrays and the maximum and minimum values of the middle subarray takes one-pass. Ensuring the third property requires a second pass. Therefore we have this two-pass solution:

///////////////////////

public int findUnsortedSubarray(int[] nums) {
    int l = 0, r = nums.length - 1, max = Integer.MIN_VALUE, min = Integer.MAX_VALUE;
        
    while (l < r && nums[l] <= nums[l + 1]) l++;
        
    if (l >= r) return 0;
        
    while (nums[r] >= nums[r - 1]) r--;
    
    for (int k = l; k <= r; k++) {
        max = Math.max(max, nums[k]);
        min = Math.min(min, nums[k]);
    }
    
    while (l >= 0 && min < nums[l]) l--;
    while (r < nums.length && nums[r] < max) r++;
        
    return (r - l - 1);
}

////////////////
III -- O(n) time one-pass solution

To understand this one-pass solution, we need to introduce some equivalent mathematical models for describing a sorted array (assuming in ascending order). Suppose the given array is nums with length n, these models are as follows:

nums[k] <= nums[k + 1] for all 0 <= k < n - 1.

nums[k] == max[k] for all 0 <= k <= n - 1, where max[k] is the maximum value of subarray nums[0, k].

nums[k] == min[k] for all 0 <= k <= n - 1, where min[k] is the minimum value of subarray nums[k, n - 1].

The first model is the most common one (and probably the most familiar one) while the last two are less common. It’s easy to show that the second model is equivalent to the first by noting that for any index k < n - 1, we have max[k] <= max[k + 1], then nums[k] = max[k] <= max[k + 1] = nums[k + 1]. Similar results hold for the third model: nums[k] = min[k] <= min[k + 1] = nums[k + 1].

With these models in place, we can show that if indices i and j satisfy the following conditions, then nums[i, j] will be the shortest subarray we are looking for:

i is the smallest index such that nums[i] != min[i];
j is the largest index such that nums[j] != max[j].
The proof proceeds by showing that the two conditions above are equivalent to the three properties in part II.

Firstly we will show that the first property in part II is held true. From condition 1, we have nums[k] == min[k] for all 0 <= k < i. Then nums[k] = min[k] <= min[k + 1] = nums[k + 1] for all k < i - 1. By definition, nums[0, i - 1] is sorted. Similarly from condition 2, nums[k] == max[k] for all j < k <= n - 1. Then nums[k] = max[k] <= max[k + 1] = nums[k + 1] for all j < k < n - 1. By definition, nums[j + 1, n - 1] is sorted.

Then we will show the third property is satisfied. Let min_m and max_m be the minimum and maximum values of subarray nums[i, j], respectively, then we have min_m >= min[i] >= min[i - 1] = nums[i - 1] and max_m <= max[j] <= max[j + 1] = nums[j + 1].

Lastly we will show that the second property is also valid. Note that if the first and third properties are both true, then we know the subarray nums[0, i - 1] will be exactly the same as subarray nums_sorted[0, i - 1], and the subarray nums[j + 1, n - 1] exactly the same as nums_sorted[j + 1, n - 1]. In this case just suppose we have nums[i] == nums_sorted[i] and nums[j] == nums_sorted[j], let’s see what will happen. Since the subarrays nums[i, n - 1] and nums_sorted[i, n - 1] contain exactly the same elements (though the order may be different), then the minimum element of the former will be the same as the latter. Since nums_sorted[i, n - 1] is sorted in ascending order, we will have min[i] = nums_sorted[i] = nums[i], which contradicts the assumption that nums[i] != min[i]. Similarly we can show that nums[j] == nums_sorted[j] implies nums[j] == max[j], which contradicts the assumption that nums[j] != max[j].

Finding the smallest index i such that nums[i] != min[i] and the largest index j such that nums[j] != max[j] can be done in one-pass, as shown below. Note that we don’t really need arrays to hold values for min[r] and max[l], by taking advantage of the recurrence relation min[r] = Math.min(min[r + 1], nums[r]) and max[l] = Math.max(max[l - 1], nums[l]). Also we initialized the indices i and j such that correct results will be returned even if the input array is already sorted (which requires initially j - i + 1 = 0).

//////////////////////
public int findUnsortedSubarray(int[] nums) {
    int i = 0, j = -1, max = Integer.MIN_VALUE, min = Integer.MAX_VALUE;
    
    for (int l = 0, r = nums.length - 1; r >= 0; l++, r--) {
        max = Math.max(max, nums[l]);
        if (nums[l] != max) j = l;
        
        min = Math.min(min, nums[r]);
        if (nums[r] != min) i = r;
    }
    
    return (j - i + 1);
}
