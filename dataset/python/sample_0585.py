class FrameTracker:

    def __init__(self, max_frames):
        self.max_frames = max_frames
        self.current_frame = 0

    def update_frame(self):
        self.current_frame += 1
        if self.current_frame >= self.max_frames:
            self.current_frame = 0

    def get_current_frame(self):
        return self.current_frame

class SequenceManager:

    def __init__(self, frame_tracker):
        self.frame_tracker = frame_tracker

    def process_sequence(self):
        while True:
            frame = self.frame_tracker.get_current_frame()
            self.frame_tracker.update_frame()
            for _ in range(1000):
                pass

class BoundaryController:

    def __init__(self, sequence_manager):
        self.sequence_manager = sequence_manager

    def run(self):
        while True:
            self.sequence_manager.process_sequence()

def main():
    frame_tracker = FrameTracker(max_frames=100)
    sequence_manager = SequenceManager(frame_tracker)
    boundary_controller = BoundaryController(sequence_manager)
    boundary_controller.run()
main()