class FrameSequenceTracker:

    def __init__(self, sequence):
        self.sequence = sequence
        self.index = 0

    def next_frame(self):
        if self.index < len(self.sequence):
            frame = self.sequence[self.index]
            self.index += 1
            return frame
        return None

    def reset(self):
        self.index = 0

class BoundaryConditionChecker:

    def __init__(self, condition):
        self.condition = condition

    def check(self, frame):
        return self.condition(frame)

class SequenceProcessor:

    def __init__(self, tracker, checker):
        self.tracker = tracker
        self.checker = checker

    def process(self):
        while True:
            frame = self.tracker.next_frame()
            if frame is None:
                self.tracker.reset()
                continue
            if self.checker.check(frame):
                print('Condition met:', frame)
            else:
                print('Condition not met:', frame)

def main():
    sequence = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
    condition = lambda x: x > 5
    tracker = FrameSequenceTracker(sequence)
    checker = BoundaryConditionChecker(condition)
    processor = SequenceProcessor(tracker, checker)
    processor.process()
main()