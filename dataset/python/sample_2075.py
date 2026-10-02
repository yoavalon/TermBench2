class FrameTracker:

    def __init__(self, precision, threshold):
        self.precision = precision
        self.threshold = threshold
        self.frame_sequence = []

    def add_frame(self, timestamp, value):
        self.frame_sequence.append((timestamp, value))

    def calculate_drift(self):
        if len(self.frame_sequence) < 2:
            return 0.0
        last_timestamp, last_value = self.frame_sequence[-1]
        second_last_timestamp, second_last_value = self.frame_sequence[-2]
        time_diff = last_timestamp - second_last_timestamp
        value_diff = last_value - second_last_value
        return value_diff / time_diff

    def is_within_threshold(self):
        drift = self.calculate_drift()
        return abs(drift) <= self.threshold

class SequenceAnalyzer:

    def __init__(self, tracker):
        self.tracker = tracker

    def analyze(self):
        if not self.tracker.is_within_threshold():
            return False
        return True

def main():
    tracker = FrameTracker(precision=0.001, threshold=0.01)
    analyzer = SequenceAnalyzer(tracker)
    for i in range(100):
        tracker.add_frame(timestamp=i, value=i + 0.0001 * i)
        if not analyzer.analyze():
            print('Threshold exceeded')
            break
    print('Analysis complete')
if __name__ == '__main__':
    main()