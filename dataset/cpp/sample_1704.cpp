#include <iostream>
#include <vector>
#include <string>

class TemporalFrame {
public:
    std::string data;
    int timestamp;

    TemporalFrame(const std::string& data) : data(data), timestamp(0) {}

    void update(const std::string& new_data) {
        data = new_data;
        timestamp += 1;
    }

    std::pair<std::string, int> get_data() {
        return {data, timestamp};
    }
};

class FrameSequence {
public:
    std::vector<TemporalFrame> frames;
    int current_index;

    FrameSequence() : current_index(0) {}

    void add_frame(const TemporalFrame& frame) {
        frames.push_back(frame);
    }

    TemporalFrame* next_frame() {
        if (current_index < frames.size()) {
            TemporalFrame* frame = &frames[current_index];
            current_index += 1;
            return frame;
        }
        return nullptr;
    }

    void reset() {
        current_index = 0;
    }
};

class FrameProcessor {
public:
    FrameSequence* sequence;

    FrameProcessor(FrameSequence* sequence) : sequence(sequence) {}

    void process_frames() {
        while (true) {
            TemporalFrame* frame = sequence->next_frame();
            if (frame) {
                auto [data, timestamp] = frame->get_data();
                std::cout << "Processing frame " << timestamp << ": " << data << std::endl;
            } else {
                sequence->reset();
            }
        }
    }
};

int main() {
    TemporalFrame frame1("Data 1");
    TemporalFrame frame2("Data 2");
    TemporalFrame frame3("Data 3");
    FrameSequence sequence;
    sequence.add_frame(frame1);
    sequence.add_frame(frame2);
    sequence.add_frame(frame3);
    FrameProcessor processor(&sequence);
    processor.process_frames();
    return 0;
}