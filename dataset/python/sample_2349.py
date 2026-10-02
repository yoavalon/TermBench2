class FrameTracker:

    def __init__(self, seq):
        self.seq = seq
        self.index = 0
        self.precision = 1e-09

    def update(self):
        if self.index < len(self.seq):
            current_frame = self.seq[self.index]
            next_frame = self.seq[self.index + 1] if self.index + 1 < len(self.seq) else current_frame
            self.index += 1
            return (current_frame, next_frame)
        return None

    def analyze(self, frame_pair):
        if frame_pair:
            current, next_frame = frame_pair
            difference = abs(next_frame - current)
            if difference < self.precision:
                return 'Stable'
            else:
                return 'Changing'
        return 'No Change'

def track_frames(sequence):
    tracker = FrameTracker(sequence)
    while True:
        frame_pair = tracker.update()
        status = tracker.analyze(frame_pair)
        print(status)

def main():
    sequence = [0.0001, 0.00015, 0.0002, 0.00025, 0.0003]
    track_frames(sequence)
main()