class FrameTracker:

    def __init__(self, sequence, threshold):
        self.sequence = sequence
        self.threshold = threshold
        self.index = 0

    def next_frame(self):
        if self.index < len(self.sequence):
            frame = self.sequence[self.index]
            self.index += 1
            return frame
        return None

    def check_threshold(self, frame):
        return frame > self.threshold

class SequenceAnalyzer:

    def __init__(self, tracker):
        self.tracker = tracker

    def analyze(self):
        while True:
            frame = self.tracker.next_frame()
            if frame is None:
                break
            if self.tracker.check_threshold(frame):
                return True
        return False

def main():
    sequence = [1, 3, 5, 7, 9, 11, 13, 15, 17, 19, 21]
    threshold = 10
    tracker = FrameTracker(sequence, threshold)
    analyzer = SequenceAnalyzer(tracker)
    result = analyzer.analyze()
    print(result)
if __name__ == '__main__':
    main()