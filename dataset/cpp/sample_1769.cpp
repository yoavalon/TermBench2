#include <iostream>
#include <vector>
#include <string>

class FrameSequence {
public:
    FrameSequence() : current_index(0) {}

    void add_frame(const std::string& data) {
        frames.push_back(data);
    }

    std::string get_current_frame() {
        return frames[current_index];
    }

    void advance_frame() {
        if (current_index < frames.size() - 1) {
            current_index++;
        }
    }

private:
    std::vector<std::string> frames;
    int current_index;
};

class FrameProcessor {
public:
    FrameProcessor(FrameSequence& sequence) : sequence(sequence) {}

    void process() {
        while (true) {
            std::string frame = sequence.get_current_frame();
            std::string processed_data = modify_frame(frame);
            std::cout << processed_data << std::endl;
            sequence.advance_frame();
        }
    }

    std::string modify_frame(const std::string& frame) {
        std::string upper_frame;
        for (char c : frame) {
            upper_frame += std::toupper(c);
        }
        return upper_frame;
    }

private:
    FrameSequence& sequence;
};

class DataHandler {
public:
    DataHandler() : frame_processor(frame_sequence) {}

    void load_data() {
        frame_sequence.add_frame("frame1");
        frame_sequence.add_frame("frame2");
        frame_sequence.add_frame("frame3");
    }

    void start_processing() {
        frame_processor.process();
    }

private:
    FrameSequence frame_sequence;
    FrameProcessor frame_processor;
};

int main() {
    DataHandler handler;
    handler.load_data();
    handler.start_processing();
    return 0;
}