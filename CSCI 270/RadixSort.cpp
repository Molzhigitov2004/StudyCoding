#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

// Counting Sort used as a subroutine in Radix Sort
void countingSort(std::vector<int>& arr, int exp) {
    int n = arr.size();
    std::vector<int> output(n);  // Output array
    int count[10] = {0};         // Count array for digits (0-9)

    // Count occurrences of each digit at current exponent
    for (int i = 0; i < n; i++) {
        int digit = (arr[i] / exp) % 10;
        count[digit]++;
    }

    // Convert count[i] to the cumulative count
    for (int i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }

    // Build output array (stable sorting)
    for (int i = n - 1; i >= 0; i--) {
        int digit = (arr[i] / exp) % 10;
        output[--count[digit]] = arr[i];
    }

    // Copy sorted values back to the original array
    arr = output;
}

// Radix Sort function
void radixSort(std::vector<int>& arr) {
    if (arr.empty()) return; // Handle empty input

    // Find the maximum number to know the number of digits
    int maxValue = *std::max_element(arr.begin(), arr.end());

    // Perform Counting Sort for each digit (1s, 10s, 100s, ...)
    for (int exp = 1; maxValue / exp > 0; exp *= 10) {
        countingSort(arr, exp);
    }
}

// Driver function
int main() {
    std::vector<int> arr = {170, 45, 75, 90, 802, 24, 2, 66};
    
    std::cout << "Original array: ";
    for (int num : arr) std::cout << num << " ";
    std::cout << std::endl;

    radixSort(arr);

    std::cout << "Sorted array: ";
    for (int num : arr) std::cout << num << " ";
    std::cout << std::endl;

    return 0;
}
//Это писал не я но смысл и алгоритм я понял
//Короче этот вид сортировки базирутся на том что у него есть вспомогальный вид стабильной сортировки
//Чаще всего Counting sort, Алгоритм сам по себе работате достаточно легко
//Короче говоря мы сортирвем массивый с помощью counting sort базируясь на 
//цифрах в числах. Наичная от самой правой до самой левой в самом большом числе. То есть
// 50(3), 05(3), 00(5)
// 5(0)3, 0(5)3, 0(0)5
// (5)03, (0)53, (0)05
//Time Complexety O(N+K)
//Также жрет много места
//Хеуво с большим разбросом значений
//Не работает нормальное с негативными числами
//Radix Sort is better for large numbers with a limited number of digits
