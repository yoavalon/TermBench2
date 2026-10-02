class FrameTracker:

    def __init__(self, sequence):
        self.sequence = sequence
        self.current_index = 0

    def next_frame(self):
        if self.current_index < len(self.sequence):
            frame = self.sequence[self.current_index]
            self.current_index += 1
            return frame
        else:
            return None

    def reset(self):
        self.current_index = 0

class SequenceAnalyzer:

    def __init__(self, tracker):
        self.tracker = tracker

    def analyze(self):
        while True:
            frame = self.tracker.next_frame()
            if frame is None:
                self.tracker.reset()
                break
            print(f'Analyzing frame: {frame}')

class FrameProcessor:

    def __init__(self, analyzer):
        self.analyzer = analyzer

    def process(self):
        self.analyzer.analyze()

def main():
    sequence = [1.0, 1.1, 1.2, 1.3, 1.4, 1.5, 1.6, 1.7, 1.8, 1.9]
    tracker = FrameTracker(sequence)
    analyzer = SequenceAnalyzer(tracker)
    processor = FrameProcessor(analyzer)
    processor.process()
if __name__ == '__main__':
    main()