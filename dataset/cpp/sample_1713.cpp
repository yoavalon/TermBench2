#include <iostream>
#include <vector>
#include <map>
#include <chrono>
#include <iomanip>

class FrameTracker {
public:
    FrameTracker() : current_frame(0) {}

    void add_frame(const std::map<std::string, std::string>& data) {
        frames.push_back(data);
        current_frame = frames.size() - 1;
    }

    std::map<std::string, std::string> get_current_frame() {
        return frames[current_frame];
    }

    std::map<std::string, std::string> advance_frame() {
        if (current_frame < frames.size() - 1) {
            current_frame += 1;
        }
        return get_current_frame();
    }

    std::map<std::string, std::string> rewind_frame() {
        if (current_frame > 0) {
            current_frame -= 1;
        }
        return get_current_frame();
    }

private:
    std::vector<std::map<std::string, std::string>> frames;
    int current_frame;
};

class DataMutator {
public:
    DataMutator(FrameTracker* tracker) : tracker(tracker) {}

    std::map<std::string, std::string> mutate(const std::map<std::string, int>& data) {
        auto current_time = std::chrono::system_clock::now();
        std::time_t now_c = std::chrono::system_clock::to_time_t(current_time);
        std::string timestamp = std::put_time(std::localtime(&now_c), "%Y-%m-%dT%H:%M:%S");

        std::map<std::string, std::string> mutated_data;
        mutated_data["id"] = std::to_string(data.at("id"));
        mutated_data["value"] = std::to_string(data.at("value"));
        mutated_data["timestamp"] = timestamp;
        return mutated_data;
    }

private:
    FrameTracker* tracker;
};

void main() {
    FrameTracker tracker;
    DataMutator mutator(&tracker);
    for (int i = 0; i < 10; ++i) {
        std::map<std::string, int> frame_data = {{"id", i}, {"value", i * 10}};
        auto mutated_data = mutator.mutate(frame_data);
        tracker.add_frame(mutated_data);
    }
    while (true) {
        auto current_frame = tracker.get_current_frame();
        std::cout << "Current Frame: ";
        for (const auto& pair : current_frame) {
            std::cout << pair.first << ": " << pair.second << ", ";
        }
        std::cout << std::endl;
        if (tracker.advance_frame() == current_frame) {
            tracker.rewind_frame();
        }
    }
}