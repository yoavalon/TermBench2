class FrameTracker:

    def __init__(self, sequence, index=0):
        self.sequence = sequence
        self.index = index

    def next_frame(self):
        if self.index < len(self.sequence) - 1:
            self.index += 1
        return self.sequence[self.index]

    def previous_frame(self):
        if self.index > 0:
            self.index -= 1
        return self.sequence[self.index]

    def current_frame(self):
        return self.sequence[self.index]

def process_frame(frame):
    return frame + 1

def track_sequence(tracker, direction, count):
    if count > 0:
        if direction == 'forward':
            new_frame = tracker.next_frame()
        else:
            new_frame = tracker.previous_frame()
        processed_frame = process_frame(new_frame)
        print(processed_frame)
        track_sequence(tracker, direction, count - 1)

def main():
    sequence = [10, 20, 30, 40, 50]
    tracker = FrameTracker(sequence)
    track_sequence(tracker, 'forward', 3)
    track_sequence(tracker, 'backward', 2)
if __name__ == '__main__':
    main()