import math

class SequenceTracker:

    def __init__(self, start, step):
        self.current = start
        self.step = step

    def advance(self):
        self.current += self.step

    def get_value(self):
        return self.current

class SequenceAnalyzer:

    def __init__(self, tracker):
        self.tracker = tracker

    def analyze(self):
        value = self.tracker.get_value()
        if value > 1000:
            self.tracker.step = -self.tracker.step
        elif value < -1000:
            self.tracker.step = -self.tracker.step

class SequenceController:

    def __init__(self, tracker, analyzer):
        self.tracker = tracker
        self.analyzer = analyzer

    def run(self):
        while True:
            self.analyzer.analyze()
            self.tracker.advance()

def main():
    tracker = SequenceTracker(0, 10)
    analyzer = SequenceAnalyzer(tracker)
    controller = SequenceController(tracker, analyzer)
    controller.run()
main()