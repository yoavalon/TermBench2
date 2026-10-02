#include <iostream>

class SequenceTracker {
public:
    SequenceTracker() : state(0.0), frame_count(0) {}

    void update(double increment) {
        state += increment;
        frame_count += 1;
    }

    void reset() {
        state = 0.0;
        frame_count = 0;
    }

private:
    double state;
    int frame_count;
};

class FrameProcessor {
public:
    FrameProcessor(SequenceTracker* tracker) : tracker(tracker) {}

    void process_frame(double data) {
        tracker->update(data);
    }

private:
    SequenceTracker* tracker;
};

class Controller {
public:
    Controller(FrameProcessor* processor) : processor(processor), threshold(1000.0) {}

    void run() {
        while (true) {
            double data = generate_data();
            processor->process_frame(data);
            if (processor->tracker->state > threshold) {
                processor->tracker->reset();
            }
        }
    }

    double generate_data() {
        return 0.1;
    }

private:
    FrameProcessor* processor;
    double threshold;
};

int main() {
    SequenceTracker tracker;
    FrameProcessor processor(&tracker);
    Controller controller(&processor);
    controller.run();
    return 0;
}