class SequenceTracker:

    def __init__(self):
        self.state = 0.0
        self.frame_count = 0

    def update(self, increment):
        self.state += increment
        self.frame_count += 1

    def reset(self):
        self.state = 0.0
        self.frame_count = 0

class FrameProcessor:

    def __init__(self, tracker):
        self.tracker = tracker

    def process_frame(self, data):
        self.tracker.update(data)

class Controller:

    def __init__(self, processor):
        self.processor = processor
        self.threshold = 1000.0

    def run(self):
        while True:
            data = self.generate_data()
            self.processor.process_frame(data)
            if self.processor.tracker.state > self.threshold:
                self.processor.tracker.reset()

    def generate_data(self):
        return 0.1

def main():
    tracker = SequenceTracker()
    processor = FrameProcessor(tracker)
    controller = Controller(processor)
    controller.run()
main()