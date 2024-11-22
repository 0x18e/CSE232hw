// WRITE YOUR CODE HERE
#include <vector>
#include <algorithm>

template<typename T>
std::vector<T> MaxVector(const std::vector<T>& a, const std::vector<T>& b) {
    size_t size_a = a.size();
    size_t size_b = b.size();
    size_t min_size = std::min(size_a, size_b);
    size_t max_size = std::max(size_a, size_b);

    std::vector<T> result(max_size);

    // Transform overlapping elements by taking the maximum
    std::transform(a.begin(), a.begin() + min_size, b.begin(), result.begin(),
        [](const T& x, const T& y) { return std::max(x, y); });

    // Copy remaining elements from the longer vector
    if (size_a > size_b) {
        std::copy(a.begin() + min_size, a.end(), result.begin() + min_size);
    }
    else if (size_b > size_a) {
        std::copy(b.begin() + min_size, b.end(), result.begin() + min_size);
    }

    return result;
}