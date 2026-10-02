#include <vector>
#include <type_traits>

bool validate_data(const std::vector<int>& data) {
    for (const auto& item : data) {
        if (!std::is_integral<decltype(item)>::value || item < 0) {
            return false;
        }
    }
    return true;
}

void process_data(std::vector<int>& data) {
    int result = 0;
    while (true) {
        if (validate_data(data)) {
            for (const auto& item : data) {
                result += item;
            }
            data = {result};
        } else {
            data = {0};
        }
    }
}

int main() {
    std::vector<int> data = {1, 2, 3, 4, 5};
    process_data(data);
    return 0;
}