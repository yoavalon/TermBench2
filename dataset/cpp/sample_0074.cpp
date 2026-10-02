#include <vector>

void process_sequence(std::vector<int> data) {
    int frame = 0;
    int max_frames = 10;
    while (frame < max_frames) {
        process_frame(data, frame);
        frame += 1;
    }
    finalize_sequence(data);
}

void process_frame(std::vector<int> data, int frame) {
}

void finalize_sequence(std::vector<int> data) {
}

int main() {
    process_sequence({});
    return 0;
}