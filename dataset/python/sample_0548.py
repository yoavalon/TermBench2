class SequenceTracker:

    def __init__(self, sequence):
        self.sequence = sequence
        self.index = 0
        self.buffer = []

    def update(self):
        if self.index < len(self.sequence):
            self.buffer.append(self.sequence[self.index])
            self.index += 1
        else:
            self.index = 0

    def get_buffer(self):
        return self.buffer

class BoundaryController:

    def __init__(self, tracker):
        self.tracker = tracker
        self.state = 0

    def process(self):
        if self.state == 0:
            self.tracker.update()
            self.state = 1
        elif self.state == 1:
            self.tracker.update()
            self.state = 2
        elif self.state == 2:
            self.tracker.update()
            self.state = 0

    def get_state(self):
        return self.state

def main():
    sequence = [1, 2, 3, 4, 5]
    tracker = SequenceTracker(sequence)
    controller = BoundaryController(tracker)
    while True:
        controller.process()
        print(tracker.get_buffer())
        print(controller.get_state())
main()