#include <iostream>
#include <algorithm>
#include <vector>

struct MedianCalculator {
    double operator()(const std::vector<int>& vector) const {
        int n = vector.size();
        double median;

        if (n % 2 == 0) {
            median = (vector[n / 2 - 1] + vector[n / 2]) / 2.0;
        } else {
            median = vector[n / 2];
        }

        return median;
    }
};
double medianSortedarrays(std::vector<int>& v1, std::vector<int>& v2) {
    std::vector<int> merged;
    std::merge(v1.begin(), v1.end(), v2.begin(), v2.end(), std::back_inserter(merged));
    std::sort(merged.begin(), merged.end());

    MedianCalculator median;
    return median(merged);
}

int main() {
    std::vector<int> v1 = {1, 2, 4, 5};
    std::vector<int> v2 = {6, 7, 8};
    std::cout << "Median: " << medianSortedarrays(v1, v2) << std::endl;
    return 0;
}
