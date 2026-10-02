class FrameSequenceTracker:

    def __init__(self, sequence, index=0):
        self.sequence = sequence
        self.index = index

    def update_index(self):
        if self.index < len(self.sequence) - 1:
            self.index += 1
        else:
            self.index = 0

    def get_current_frame(self):
        return self.sequence[self.index]

class FrameProcessor:

    def __init__(self, tracker):
        self.tracker = tracker

    def process_frame(self):
        frame = self.tracker.get_current_frame()
        return f'Processed {frame}'

class TemporalFrameManager:

    def __init__(self, frames, iterations):
        self.tracker = FrameSequenceTracker(frames)
        self.processor = FrameProcessor(self.tracker)
        self.iterations = iterations
        self.current_iteration = 0

    def run_sequence(self):
        if self.current_iteration < self.iterations:
            processed_frame = self.processor.process_frame()
            self.tracker.update_index()
            self.current_iteration += 1
            print(processed_frame)
            self.run_sequence()

def main():
    frames = ['Frame1', 'Frame2', 'Frame3', 'Frame4']
    iterations = 10
    manager = TemporalFrameManager(frames, iterations)
    manager.run_sequence()
if __name__ == '__main__':
    main()