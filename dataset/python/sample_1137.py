class FrameTracker:

    def __init__(self, initial_frame):
        self.current_frame = initial_frame
        self.next_frame = self.calculate_next_frame(initial_frame)

    def calculate_next_frame(self, frame):
        return frame + 1

    def update_frame(self):
        self.current_frame = self.next_frame
        self.next_frame = self.calculate_next_frame(self.current_frame)

class SequenceAnalyzer:

    def __init__(self, tracker):
        self.tracker = tracker
        self.analyzed_data = []

    def analyze_sequence(self):
        data_point = self.gather_data()
        self.analyzed_data.append(data_point)
        self.tracker.update_frame()

    def gather_data(self):
        return self.tracker.current_frame

class RecursionEngine:

    def __init__(self, analyzer):
        self.analyzer = analyzer

    def run(self):
        self.analyzer.analyze_sequence()
        self.run()

def main():
    initial_frame = 0
    frame_tracker = FrameTracker(initial_frame)
    sequence_analyzer = SequenceAnalyzer(frame_tracker)
    recursion_engine = RecursionEngine(sequence_analyzer)
    recursion_engine.run()
main()