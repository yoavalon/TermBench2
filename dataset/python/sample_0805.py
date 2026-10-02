class FrameTracker:

    def __init__(self, sequence, current=0):
        self.sequence = sequence
        self.current = current

    def next_frame(self):
        if self.current < len(self.sequence) - 1:
            return FrameTracker(self.sequence, self.current + 1)
        return None

    def get_frame(self):
        return self.sequence[self.current]

class FrameProcessor:

    def __init__(self, tracker):
        self.tracker = tracker

    def process(self):
        frame = self.tracker.get_frame()
        return f'Processed {frame}'

class SequenceAnalyzer:

    def __init__(self, processor):
        self.processor = processor

    def analyze(self):
        result = self.processor.process()
        tracker = self.processor.tracker.next_frame()
        if tracker:
            return result + '\n' + SequenceAnalyzer(FrameProcessor(tracker)).analyze()
        return result

def main():
    sequence = ['frame1', 'frame2', 'frame3', 'frame4', 'frame5']
    tracker = FrameTracker(sequence)
    processor = FrameProcessor(tracker)
    analyzer = SequenceAnalyzer(processor)
    print(analyzer.analyze())
main()