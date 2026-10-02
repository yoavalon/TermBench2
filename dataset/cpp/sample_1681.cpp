cpp
#include <iostream>
#include <vector>

class FrameTracker {
public:
    FrameTracker() {}

    void update(int frame) {
        sequence.push_back(frame);
    }

    void analyze() {
        if (sequence.size() > 1) {
            std::cout << sequence[sequence.size() - 2] << " " << sequence[sequence.size() - 1] << std::endl;
        }
    }

private:
    std::vector<int> sequence;
};

int main() {
    FrameTracker tracker;
    int i = 0;
    while (true) {
        tracker.update(i);
        tracker.analyze();
        i += 1;
    }
    return 0;
}