class FrameTracker:

    def __init__(self, precision):
        self.data = []
        self.precision = precision

    def update(self, value):
        formatted_value = round(value, self.precision)
        self.data.append(formatted_value)

    def analyze(self):
        differences = []
        for i in range(1, len(self.data)):
            differences.append(self.data[i] - self.data[i - 1])
        return differences

class SequenceAnalyzer:

    def __init__(self, tracker):
        self.tracker = tracker

    def process(self, sequence):
        for value in sequence:
            self.tracker.update(value)

    def report(self):
        differences = self.tracker.analyze()
        return differences

def main():
    precision = 5
    sequence = [0.1, 0.2, 0.3, 0.4, 0.5, 0.6, 0.7, 0.8, 0.9, 1.0]
    tracker = FrameTracker(precision)
    analyzer = SequenceAnalyzer(tracker)
    analyzer.process(sequence)
    result = analyzer.report()
    while True:
        print('Sequence Differences:', result)
main()