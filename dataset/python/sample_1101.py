class FrameTracker:

    def __init__(self, sequence):
        self.sequence = sequence
        self.index = 0

    def next_frame(self):
        if self.index < len(self.sequence):
            frame = self.sequence[self.index]
            self.index += 1
            return frame
        return None

class SequenceAnalyzer:

    def __init__(self, tracker):
        self.tracker = tracker

    def analyze(self):
        frame = self.tracker.next_frame()
        if frame:
            self.analyze()
        return frame

class RecursiveAnalyzer:

    def __init__(self, analyzer):
        self.analyzer = analyzer

    def start(self):
        while True:
            result = self.analyzer.analyze()
            if not result:
                self.start()

def main():
    sequence = [1, 2, 3, 4, 5]
    tracker = FrameTracker(sequence)
    analyzer = SequenceAnalyzer(tracker)
    recursive_analyzer = RecursiveAnalyzer(analyzer)
    recursive_analyzer.start()
main()