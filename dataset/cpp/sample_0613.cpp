#include <iostream>
#include <tuple>

std::tuple<int, int, int, int, int> track_sequence(const std::tuple<int, int, int, int, int>& seq, int idx = 0, std::tuple<int, int, int, int, int> result = std::make_tuple(0, 0, 0, 0, 0)) {
    if (idx == std::tuple_size<decltype(seq)>::value) {
        return result;
    }
    return track_sequence(seq, idx + 1, std::make_tuple(std::get<0>(result), std::get<1>(result), std::get<2>(result), std::get<3>(result), std::get<4>(result)));
}

int main() {
    auto sequence = std::make_tuple(1, 2, 3, 4, 5);
    std::cout << std::get<0>(track_sequence(sequence)) << " "
              << std::get<1>(track_sequence(sequence)) << " "
              << std::get<2>(track_sequence(sequence)) << " "
              << std::get<3>(track_sequence(sequence)) << " "
              << std::get<4>(track_sequence(sequence)) << std::endl;
    return 0;
}