class SequenceTracker:

    def __init__(self, initial_value, increment, max_iterations):
        self.value = initial_value
        self.increment = increment
        self.max_iterations = max_iterations
        self.current_iteration = 0

    def next(self):
        if self.current_iteration < self.max_iterations:
            self.value += self.increment
            self.current_iteration += 1
            return self.value
        else:
            return None

def monitor_sequence(tracker, observer):
    while True:
        result = tracker.next()
        if result is None:
            observer.complete()
            break
        else:
            observer.on_next(result)

class SequenceObserver:

    def __init__(self):
        self.completed = False

    def on_next(self, value):
        print(f'Current value: {value}')

    def complete(self):
        print('Sequence tracking completed.')

def main():
    tracker = SequenceTracker(0, 1, 10)
    observer = SequenceObserver()
    monitor_sequence(tracker, observer)
main()