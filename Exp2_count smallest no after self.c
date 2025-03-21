// Function to merge two halves and count the smaller elements
void merge_and_count(int* nums, int* indexes, int* result, int left, int mid, int right) {
    int temp[right - left + 1];
    int count = 0;
    int i = left, j = mid + 1, k = 0;
    
    while (i <= mid || j <= right) {
        if (j > right || (i <= mid && nums[indexes[i]] <= nums[indexes[j]])) {
            result[indexes[i]] += count;
            temp[k++] = indexes[i++];
        } else {
            count++;
            temp[k++] = indexes[j++];
        }
    }
    
    // Copy the temp array back to indexes
    for (int i = 0; i < k; i++) {
        indexes[left + i] = temp[i];
    }
}

// Function to perform merge sort and count smaller elements to the right
void merge_sort(int* nums, int* indexes, int* result, int left, int right) {
    if (left == right) return;
    
    int mid = (left + right) / 2;
    
    merge_sort(nums, indexes, result, left, mid);
    merge_sort(nums, indexes, result, mid + 1, right);
    
    merge_and_count(nums, indexes, result, left, mid, right);
}

// Main function to solve the problem
int* countSmaller(int* nums, int numsSize, int* returnSize) {
    *returnSize = numsSize;
    int* result = (int*)malloc(sizeof(int) * numsSize);
    int* indexes = (int*)malloc(sizeof(int) * numsSize);
    
    for (int i = 0; i < numsSize; i++) {
        indexes[i] = i;
        result[i] = 0; // Initialize result array to 0
    }
    
    merge_sort(nums, indexes, result, 0, numsSize - 1);
    
    free(indexes);
    return result;
}
