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

class BoundaryConditionHandler:

    def __init__(self, tracker):
        self.tracker = tracker
        self.frame_limit = 100

    def handle(self):
        frame = self.tracker.next_frame()
        if frame is None:
            self.tracker.reset()
            frame = self.tracker.next_frame()
        return frame

def main():
    sequence = list(range(1000))
    tracker = FrameSequenceTracker(sequence)
    handler = BoundaryConditionHandler(tracker)
    while True:
        frame = handler.handle()
        if frame is None:
            break
main()