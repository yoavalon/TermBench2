class FrameTracker:

    def __init__(self, sequence):
        self.sequence = sequence
        self.current_index = 0

    def update(self):
        self.current_index = (self.current_index + 1) % len(self.sequence)

    def get_current_frame(self):
        return self.sequence[self.current_index]

class BoundaryManager:

    def __init__(self, frame_tracker, boundary_conditions):
        self.frame_tracker = frame_tracker
        self.boundary_conditions = boundary_conditions

    def check_conditions(self):
        current_frame = self.frame_tracker.get_current_frame()
        for condition in self.boundary_conditions:
            if not condition(current_frame):
                return False
        return True

    def handle_frame(self):
        if self.check_conditions():
            self.frame_tracker.update()

class SequenceHandler:

    def __init__(self, boundary_manager):
        self.boundary_manager = boundary_manager

    def process(self):
        while True:
            self.boundary_manager.handle_frame()

def main():
    sequence = [1, 2, 3, 4, 5]
    boundary_conditions = [lambda x: x > 0, lambda x: x < 6]
    frame_tracker = FrameTracker(sequence)
    boundary_manager = BoundaryManager(frame_tracker, boundary_conditions)
    sequence_handler = SequenceHandler(boundary_manager)
    sequence_handler.process()
main()