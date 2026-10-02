class SequenceGenerator:

    def __init__(self, start, end, step):
        self.current = start
        self.end = end
        self.step = step

    def generate(self):
        sequence = []
        while self.current <= self.end:
            sequence.append(self.current)
            self.current += self.step
        return sequence

class FrameTracker:

    def __init__(self, sequence):
        self.sequence = sequence
        self.index = 0

    def next_frame(self):
        if self.index < len(self.sequence):
            value = self.sequence[self.index]
            self.index += 1
            return value
        return None

class TemporalAnalysis:

    def __init__(self, tracker):
        self.tracker = tracker

    def analyze(self):
        result = []
        while True:
            frame = self.tracker.next_frame()
            if frame is None:
                break
            result.append(frame)
        return result

def main():
    start = 1
    end = 100
    step = 5
    generator = SequenceGenerator(start, end, step)
    sequence = generator.generate()
    tracker = FrameTracker(sequence)
    analysis = TemporalAnalysis(tracker)
    result = analysis.analyze()
    print(result)
main()