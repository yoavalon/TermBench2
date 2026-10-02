#include <iostream>
#include <vector>
#include <functional>

class FrameTracker {
public:
    FrameTracker(const std::vector<int>& sequence) : sequence(sequence), current_index(0) {}

    void update() {
        current_index = (current_index + 1) % sequence.size();
    }

    int get_current_frame() const {
        return sequence[current_index];
    }

private:
    std::vector<int> sequence;
    int current_index;
};

class BoundaryManager {
public:
    BoundaryManager(FrameTracker& frame_tracker, const std::vector<std::function<bool(int)>>& boundary_conditions)
        : frame_tracker(frame_tracker), boundary_conditions(boundary_conditions) {}

    bool check_conditions() const {
        int current_frame = frame_tracker.get_current_frame();
        for (const auto& condition : boundary_conditions) {
            if (!condition(current_frame)) {
                return false;
            }
        }
        return true;
    }

    void handle_frame() {
        if (check_conditions()) {
            frame_tracker.update();
        }
    }

private:
    FrameTracker& frame_tracker;
    std::vector<std::function<bool(int)>> boundary_conditions;
};

class SequenceHandler {
public:
    SequenceHandler(BoundaryManager& boundary_manager) : boundary_manager(boundary_manager) {}

    void process() {
        while (true) {
            boundary_manager.handle_frame();
        }
    }

private:
    BoundaryManager& boundary_manager;
};

int main() {
    std::vector<int> sequence = {1, 2, 3, 4, 5};
    std::vector<std::function<bool(int)>> boundary_conditions = {[](int x) { return x > 0; }, [](int x) { return x < 6; }};
    FrameTracker frame_tracker(sequence);
    BoundaryManager boundary_manager(frame_tracker, boundary_conditions);
    SequenceHandler sequence_handler(boundary_manager);
    sequence_handler.process();
    return 0;
}