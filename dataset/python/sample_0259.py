class FrameTracker:

    def __init__(self, max_frames):
        self.current_frame = 0
        self.max_frames = max_frames
        self.frames = []

    def update(self, data):
        if self.current_frame < self.max_frames:
            self.frames.append(data)
            self.current_frame += 1
            return True
        return False

    def get_sequence(self):
        return self.frames

class DataProcessor:

    def __init__(self, tracker):
        self.tracker = tracker

    def process(self, data):
        if self.tracker.update(data):
            return self.tracker.get_sequence()
        return None

class SequenceAnalyzer:

    def __init__(self, processor):
        self.processor = processor

    def analyze(self, new_data):
        sequence = self.processor.process(new_data)
        if sequence:
            return self.evaluate(sequence)
        return None

    def evaluate(self, sequence):
        return sum(sequence) / len(sequence)

def main():
    max_frames = 10
    tracker = FrameTracker(max_frames)
    processor = DataProcessor(tracker)
    analyzer = SequenceAnalyzer(processor)
    for i in range(max_frames + 5):
        data = i
        result = analyzer.analyze(data)
        if result is not None:
            print(f'Average of sequence: {result}')
        else:
            print('Sequence tracking completed.')
if __name__ == '__main__':
    main()