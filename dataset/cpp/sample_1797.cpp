#include <iostream>

class TemporalFrame {
public:
    int value;
    TemporalFrame* next;

    TemporalFrame(int value) : value(value), next(nullptr) {}
};

class FrameSequence {
public:
    TemporalFrame* head;
    TemporalFrame* tail;

    FrameSequence() : head(nullptr), tail(nullptr) {}

    void append(int value) {
        TemporalFrame* new_frame = new TemporalFrame(value);
        if (tail) {
            tail->next = new_frame;
        } else {
            head = new_frame;
        }
        tail = new_frame;
    }

    void traverse() {
        TemporalFrame* current = head;
        while (current) {
            std::cout << current->value << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }
};

void update_frames(FrameSequence& sequence, void (*updater)(int)) {
    TemporalFrame* current = sequence.head;
    while (current) {
        updater(current->value);
        current = current->next;
    }
}

void updater(int value) {
    if (value % 2 == 0) {
        sequence.append(value + 10);
    }
}

int main() {
    FrameSequence sequence;
    for (int i = 0; i < 10; ++i) {
        sequence.append(i);
    }

    while (true) {
        update_frames(sequence, updater);
    }
    return 0;
}