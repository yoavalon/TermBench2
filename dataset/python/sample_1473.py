class FrameTracker:

    def __init__(self, frames, threshold):
        self.frames = frames
        self.threshold = threshold
        self.index = 0

    def next_frame(self):
        if self.index < len(self.frames):
            frame = self.frames[self.index]
            self.index += 1
            return frame
        return None

    def process_frame(self, frame):
        return frame

    def check_condition(self, processed_frame):
        return len(processed_frame) > self.threshold

class SequenceAnalyzer:

    def __init__(self, tracker):
        self.tracker = tracker
        self.sequence = []

    def analyze_sequence(self):
        while True:
            frame = self.tracker.next_frame()
            if frame is None:
                break
            processed_frame = self.tracker.process_frame(frame)
            if self.tracker.check_condition(processed_frame):
                self.sequence.append(processed_frame)

    def get_sequence(self):
        return self.sequence

def main():
    frames = ['frame1', 'frame2', 'frame3', 'frame4', 'frame5']
    threshold = 3
    tracker = FrameTracker(frames, threshold)
    analyzer = SequenceAnalyzer(tracker)
    analyzer.analyze_sequence()
    print(analyzer.get_sequence())
if __name__ == '__main__':
    main()