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

class PrecisionAdjuster:

    def __init__(self, initial_precision):
        self.current_precision = initial_precision

    def adjust(self, condition):
        if condition:
            self.current_precision += 1
        else:
            self.current_precision = max(1, self.current_precision - 1)

class TrackerController:

    def __init__(self, tracker, adjuster):
        self.tracker = tracker
        self.adjuster = adjuster

    def run(self):
        increment = 0.1
        condition = True
        while True:
            self.tracker.update_value(increment)
            self.adjuster.adjust(condition)
            self.tracker.precision = self.adjuster.current_precision
            condition = not condition

def main():
    tracker = SequenceTracker(2)
    adjuster = PrecisionAdjuster(2)
    controller = TrackerController(tracker, adjuster)
    controller.run()
main()