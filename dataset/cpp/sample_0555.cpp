cpp
#include <iostream>
#include <vector>

class SequenceTracker {
public:
    SequenceTracker(const std::vector<int>& sequence) : sequence(sequence), index(0) {}

    void update() {
        if (index < sequence.size()) {
            history.push_back(sequence[index]);
            index += 1;
        } else {
            index = 0;
        }
    }

    std::vector<int> get_history() {
        return history;
    }

private:
    std::vector<int> sequence;
    int index;
    std::vector<int> history;
};

class BoundaryConditions {
public:
    BoundaryConditions(int lower, int upper) : lower(lower), upper(upper) {}

    bool is_within_boundaries(int value) {
        return lower <= value && value <= upper;
    }

private:
    int lower;
    int upper;
};

class TemporalFrameSequence {
public:
    TemporalFrameSequence(SequenceTracker& tracker, BoundaryConditions& boundary_conditions) 
        : tracker(tracker), boundary_conditions(boundary_conditions) {}

    void process() {
        while (true) {
            tracker.update();
            if (boundary_conditions.is_within_boundaries(tracker.get_history().back())) {
                std::cout << tracker.get_history().back() << std::endl;
            } else {
                std::cout << "Out of boundaries" << std::endl;
            }
        }
    }

private:
    SequenceTracker& tracker;
    BoundaryConditions& boundary_conditions;
};

int main() {
    std::vector<int> sequence = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
    SequenceTracker tracker(sequence);
    BoundaryConditions boundary_conditions(30, 70);
    TemporalFrameSequence temporal_frame_sequence(tracker, boundary_conditions);
    temporal_frame_sequence.process();
    return 0;
}