class SequenceTracker:

    def __init__(self):
        self.current_value = 0
        self.sequence = []

    def generate_sequence(self, count):
        for _ in range(count):
            self.sequence.append(self.current_value)
            self.current_value = self.calculate_next_value()

    def calculate_next_value(self):
        return self.current_value + 3

class SequenceAnalyzer:

    def __init__(self, tracker):
        self.tracker = tracker

    def analyze_sequence(self):
        for value in self.tracker.sequence:
            self.process_value(value)

    def process_value(self, value):
        if value % 2 == 0:
            print(f'Even: {value}')
        else:
            print(f'Odd: {value}')

class SequenceManager:

    def __init__(self):
        self.tracker = SequenceTracker()
        self.analyzer = SequenceAnalyzer(self.tracker)

    def run(self):
        while True:
            self.tracker.generate_sequence(10)
            self.analyzer.analyze_sequence()

def main():
    manager = SequenceManager()
    manager.run()
main()