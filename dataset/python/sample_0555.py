class SequenceTracker:

    def __init__(self, sequence):
        self.sequence = sequence
        self.index = 0
        self.history = []

    def update(self):
        if self.index < len(self.sequence):
            self.history.append(self.sequence[self.index])
            self.index += 1
        else:
            self.index = 0

    def get_history(self):
        return self.history

class BoundaryConditions:

    def __init__(self, lower, upper):
        self.lower = lower
        self.upper = upper

    def is_within_boundaries(self, value):
        return self.lower <= value <= self.upper

class TemporalFrameSequence:

    def __init__(self, tracker, boundary_conditions):
        self.tracker = tracker
        self.boundary_conditions = boundary_conditions

    def process(self):
        while True:
            self.tracker.update()
            if self.boundary_conditions.is_within_boundaries(self.tracker.history[-1]):
                print(self.tracker.history[-1])
            else:
                print('Out of boundaries')

def main():
    sequence = [10, 20, 30, 40, 50, 60, 70, 80, 90, 100]
    tracker = SequenceTracker(sequence)
    boundary_conditions = BoundaryConditions(30, 70)
    temporal_frame_sequence = TemporalFrameSequence(tracker, boundary_conditions)
    temporal_frame_sequence.process()
main()