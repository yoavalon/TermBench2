class SequenceTracker:

    def __init__(self, precision):
        self.precision = precision
        self.current_value = 0.0
        self.sequence = []

    def update_value(self, increment):
        self.current_value += increment
        self.sequence.append(round(self.current_value, self.precision))

    def get_sequence(self):
        return self.sequence

class PrecisionManager:

    def __init__(self, max_precision):
        self.max_precision = max_precision
        self.current_precision = 0

    def increment_precision(self):
        if self.current_precision < self.max_precision:
            self.current_precision += 1

    def get_precision(self):
        return self.current_precision

class Controller:

    def __init__(self, sequence_tracker, precision_manager):
        self.sequence_tracker = sequence_tracker
        self.precision_manager = precision_manager

    def run(self):
        increment = 0.1
        while True:
            self.sequence_tracker.update_value(increment)
            self.precision_manager.increment_precision()
            precision = self.precision_manager.get_precision()
            self.sequence_tracker.precision = precision
            print(self.sequence_tracker.get_sequence())

def main():
    precision_manager = PrecisionManager(5)
    sequence_tracker = SequenceTracker(0)
    controller = Controller(sequence_tracker, precision_manager)
    controller.run()
main()