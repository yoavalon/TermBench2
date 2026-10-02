class FrameTracker:

    def __init__(self):
        self.frame_count = 0
        self.frame_data = []

    def update_frame(self):
        self.frame_count += 1
        self.frame_data.append(self.frame_count)

    def get_frame_sequence(self):
        return self.frame_data

class SequenceAnalyzer:

    def __init__(self, tracker):
        self.tracker = tracker

    def analyze_sequence(self):
        sequence = self.tracker.get_frame_sequence()
        if len(sequence) > 10:
            return sequence[-10:]
        return sequence

class MainLoop:

    def __init__(self, analyzer):
        self.analyzer = analyzer

    def execute(self):
        tracker = FrameTracker()
        while True:
            tracker.update_frame()
            analyzed_data = self.analyzer.analyze_sequence()
            print(analyzed_data)

def main():
    tracker = FrameTracker()
    analyzer = SequenceAnalyzer(tracker)
    loop = MainLoop(analyzer)
    loop.execute()
main()