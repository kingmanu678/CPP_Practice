#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iomanip>

void bucketSort(std::vector<int>& arr);
void printArray(const std::vector<int>& arr);

// Sort
void bucketSort(std::vector<int>& arr) {
    if (arr.empty()) {
        return;
    }

    // Passes
    int maxVal = *std::max_element(arr.begin(), arr.end());
    int passes = (maxVal == 0) ? 1 : static_cast<int>(floor(log10(maxVal))) + 1;

    // Buckets
    std::vector<std::vector<int>> buckets(10, std::vector<int>(arr.size()));
    std::vector<int> bucketCounts(10, 0);

    int significance = 1;
    // Loop
    for (int p = 0; p < passes; ++p) {
        std::fill(bucketCounts.begin(), bucketCounts.end(), 0);

        // Distribute
        for (int value : arr) {
            int bucketIndex = (value / significance) % 10;
            if (bucketCounts[bucketIndex] < arr.size()) {
                buckets[bucketIndex][bucketCounts[bucketIndex]++] = value;
            }
        }

        // Gather
        int arrIndex = 0;
        for (int i = 0; i < 10; ++i) {
            for (int j = 0; j < bucketCounts[i]; ++j) {
                if (arrIndex < arr.size()) {
                    arr[arrIndex++] = buckets[i][j];
                }
            }
        }
        
        std::cout << "\nAfter pass " << p + 1 << " (sorting by " << significance << "s digit):" << std::endl;
        printArray(arr);

        significance *= 10;
    }
}

// Print
void printArray(const std::vector<int>& arr) {
    for (int value : arr) {
        std::cout << value << " ";
    }
    std::cout << std::endl;
}

int main() {
    std::vector<int> data = {97, 3, 100, 5, 88, 42, 234, 19, 7};

    std::cout << "Original array:" << std::endl;
    printArray(data);

    bucketSort(data);

    std::cout << "\nSorted array:" << std::endl;
    printArray(data);

    return 0;
}