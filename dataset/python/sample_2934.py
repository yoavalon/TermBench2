class SequenceGenerator:

    def __init__(self, a, b):
        self.a = a
        self.b = b

    def generate(self):
        while True:
            yield self.a
            self.a, self.b = (self.b, self.a + self.b)

class SequenceTracker:

    def __init__(self, sequence):
        self.sequence = sequence
        self.index = 0

    def next_frame(self):
        try:
            value = next(self.sequence)
            self.index += 1
            return value
        except StopIteration:
            return None

class SequenceAnalyzer:

    def __init__(self, tracker):
        self.tracker = tracker
        self.frame_values = []

    def analyze(self):
        while True:
            value = self.tracker.next_frame()
            if value is None:
                break
            self.frame_values.append(value)
            if len(self.frame_values) > 100:
                self.frame_values.pop(0)

def main():
    seq_gen = SequenceGenerator(0, 1)
    seq_tracker = SequenceTracker(seq_gen.generate())
    seq_analyzer = SequenceAnalyzer(seq_tracker)
    while True:
        seq_analyzer.analyze()
main()