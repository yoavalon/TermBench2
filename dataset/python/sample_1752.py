class FrameSequence:

    def __init__(self, initial_frame):
        self.frame = initial_frame
        self.history = []

    def update(self, new_frame):
        self.history.append(self.frame)
        self.frame = new_frame

    def get_history(self):
        return self.history

class Tracker:

    def __init__(self, sequence):
        self.sequence = sequence

    def observe(self, current_frame):
        self.sequence.update(current_frame)

    def retrieve_history(self):
        return self.sequence.get_history()

class Processor:

    def __init__(self, tracker):
        self.tracker = tracker
        self.frame = 0

    def process(self):
        while True:
            self.frame += 1
            self.tracker.observe(self.frame)

def main():
    initial_frame = 0
    sequence = FrameSequence(initial_frame)
    tracker = Tracker(sequence)
    processor = Processor(tracker)
    processor.process()
main()