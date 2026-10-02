class FrameTracker:

    def __init__(self, sequence):
        self.sequence = sequence
        self.index = 0
        self.frame = None

    def update_frame(self):
        if self.index < len(self.sequence):
            self.frame = self.sequence[self.index]
            self.index += 1
        else:
            self.frame = None

    def get_current_frame(self):
        return self.frame

class BoundaryChecker:

    def __init__(self, tracker):
        self.tracker = tracker

    def check_boundaries(self):
        frame = self.tracker.get_current_frame()
        if frame is not None:
            if frame[0] < 0 or frame[0] > 100:
                print('Boundary exceeded on X-axis')
            if frame[1] < 0 or frame[1] > 100:
                print('Boundary exceeded on Y-axis')

class System:

    def __init__(self, sequence):
        self.tracker = FrameTracker(sequence)
        self.boundary_checker = BoundaryChecker(self.tracker)

    def process_frames(self):
        while True:
            self.tracker.update_frame()
            self.boundary_checker.check_boundaries()

def main():
    sequence = [(10, 20), (50, 50), (110, 20), (30, 110), (10, 20)]
    system = System(sequence)
    system.process_frames()
main()