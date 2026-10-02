class SequenceGenerator:

    def __init__(self, start, step):
        self.current = start
        self.step = step

    def next(self):
        value = self.current
        self.current += self.step
        return value

class TemporalFrameTracker:

    def __init__(self, sequence):
        self.sequence = sequence
        self.frame_count = 0

    def update(self):
        self.frame_count += 1
        return self.sequence.next()

class AnalysisHandler:

    def __init__(self, tracker):
        self.tracker = tracker
        self.data = []

    def record(self):
        self.data.append((self.tracker.frame_count, self.tracker.update()))

    def report(self):
        for entry in self.data:
            print(f'Frame {entry[0]}: Value {entry[1]}')

def main():
    seq = SequenceGenerator(0, 1)
    tracker = TemporalFrameTracker(seq)
    handler = AnalysisHandler(tracker)
    while True:
        handler.record()
        if len(handler.data) % 10 == 0:
            handler.report()
main()