#include <iostream>
#include <vector>
#include <tuple>

class FrameTracker {
public:
    FrameTracker(const std::vector<std::tuple<int, int>>& sequence) : sequence(sequence), index(0), frame(nullptr) {}

    void update_frame() {
        if (index < sequence.size()) {
            frame = &sequence[index];
            index++;
        } else {
            frame = nullptr;
        }
    }

    std::tuple<int, int>* get_current_frame() {
        return frame;
    }

private:
    const std::vector<std::tuple<int, int>>& sequence;
    size_t index;
    std::tuple<int, int>* frame;
};

class BoundaryChecker {
public:
    BoundaryChecker(FrameTracker* tracker) : tracker(tracker) {}

    void check_boundaries() {
        auto frame = tracker->get_current_frame();
        if (frame != nullptr) {
            int x, y;
            std::tie(x, y) = *frame;
            if (x < 0 || x > 100) {
                std::cout << 'Boundary exceeded on X-axis' << std::endl;
            }
            if (y < 0 || y > 100) {
                std::cout << 'Boundary exceeded on Y-axis' << std::endl;
            }
        }
    }

private:
    FrameTracker* tracker;
};

class System {
public:
    System(const std::vector<std::tuple<int, int>>& sequence) : tracker(sequence), boundary_checker(&tracker) {}

    void process_frames() {
        while (true) {
            tracker.update_frame();
            boundary_checker.check_boundaries();
        }
    }

private:
    FrameTracker tracker;
    BoundaryChecker boundary_checker;
};

int main() {
    std::vector<std::tuple<int, int>> sequence = {{10, 20}, {50, 50}, {110, 20}, {30, 110}, {10, 20}};
    System system(sequence);
    system.process_frames();
    return 0;
}