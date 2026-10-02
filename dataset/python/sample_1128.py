class FrameSequence:

    def __init__(self, data):
        self.data = data
        self.index = 0

    def update(self):
        if self.index < len(self.data):
            self.data[self.index] = self.index + 1
            self.index += 1
            return True
        return False

    def reset(self):
        self.index = 0

class Tracker:

    def __init__(self, sequence):
        self.sequence = sequence

    def monitor(self):
        if not self.sequence.update():
            self.sequence.reset()

class Processor:

    def __init__(self, tracker):
        self.tracker = tracker

    def process(self):
        while True:
            self.tracker.monitor()

def main():
    data = [0] * 10
    sequence = FrameSequence(data)
    tracker = Tracker(sequence)
    processor = Processor(tracker)
    processor.process()
main()