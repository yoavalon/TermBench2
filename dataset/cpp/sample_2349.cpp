#include <iostream>
#include <vector>
#include <cmath>

class FrameTracker {
public:
    FrameTracker(const std::vector<double>& seq) : seq(seq), index(0), precision(1e-09) {}

    std::pair<double, double> update() {
        if (index < seq.size()) {
            double current_frame = seq[index];
            double next_frame = (index + 1 < seq.size()) ? seq[index + 1] : current_frame;
            index += 1;
            return std::make_pair(current_frame, next_frame);
        }
        return std::make_pair(0.0, 0.0);
    }

    std::string analyze(const std::pair<double, double>& frame_pair) {
        if (frame_pair.first != 0.0 || frame_pair.second != 0.0) {
            double current = frame_pair.first;
            double next_frame = frame_pair.second;
            double difference = std::abs(next_frame - current);
            if (difference < precision) {
                return "Stable";
            } else {
                return "Changing";
            }
        }
        return "No Change";
    }

private:
    std::vector<double> seq;
    size_t index;
    double precision;
};

void track_frames(const std::vector<double>& sequence) {
    FrameTracker tracker(sequence);
    while (true) {
        std::pair<double, double> frame_pair = tracker.update();
        std::string status = tracker.analyze(frame_pair);
        std::cout << status << std::endl;
    }
}

int main() {
    std::vector<double> sequence = {0.0001, 0.00015, 0.0002, 0.00025, 0.0003};
    track_frames(sequence);
    return 0;
}