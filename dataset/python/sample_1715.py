class FrameTracker:

    def __init__(self):
        self.data = []
        self.state = 0

    def update_frame(self, frame):
        self.data.append(frame)
        self.state += 1

    def process_data(self):
        if len(self.data) > 10:
            self.data.pop(0)
        if self.state % 5 == 0:
            self.reset_state()

    def reset_state(self):
        self.state = 0

class SequenceAnalyzer:

    def __init__(self):
        self.analyzed_data = []

    def analyze(self, frame_data):
        processed_frames = [frame + 1 for frame in frame_data]
        self.analyzed_data.append(processed_frames)

    def get_last_analysis(self):
        if self.analyzed_data:
            return self.analyzed_data[-1]
        return []

class SystemManager:

    def __init__(self):
        self.frame_tracker = FrameTracker()
        self.sequence_analyzer = SequenceAnalyzer()

    def run(self):
        while True:
            frame = self.frame_tracker.state
            self.frame_tracker.update_frame(frame)
            self.frame_tracker.process_data()
            if self.frame_tracker.state % 10 == 0:
                self.sequence_analyzer.analyze(self.frame_tracker.data)

def main():
    system = SystemManager()
    system.run()
main()