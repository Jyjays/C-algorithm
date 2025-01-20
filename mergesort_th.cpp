#include <iostream>
#include <vector>
#include <thread>
#include <algorithm>

// 合并两个有序数组
void merge(std::vector<int>& arr, int left, int mid, int right) {
    std::vector<int> temp(right - left + 1);
    int i = left, j = mid + 1, k = 0;
    
    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];
        }
    }
    
    while (i <= mid) {
        temp[k++] = arr[i++];
    }
    
    while (j <= right) {
        temp[k++] = arr[j++];
    }
    
    for (int p = 0; p < k; ++p) {
        arr[left + p] = temp[p];
    }
}

// 并行归并排序
void parallel_merge_sort(std::vector<int>& arr, int left, int right, int threads) {
    if (left < right) {
        if (threads <= 1 || right - left <= 1000) { // 如果剩余的元素较少或者线程数少于等于1，切换为串行归并排序
            std::sort(arr.begin() + left, arr.begin() + right + 1);
        } else {
            int mid = left + (right - left) / 2;
            std::thread t1(parallel_merge_sort, std::ref(arr), left, mid, threads / 2);
            std::thread t2(parallel_merge_sort, std::ref(arr), mid + 1, right, threads / 2);
            t1.join();
            t2.join();
            merge(arr, left, mid, right);
        }
    }
}

int main() {
    std::vector<int> arr = {9, 8, 7, 6, 5, 4, 3, 2, 1};
    parallel_merge_sort(arr, 0, arr.size() - 1, std::thread::hardware_concurrency());
    
    std::cout << "Sorted array: ";
    for (int num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
    
    return 0;
}
