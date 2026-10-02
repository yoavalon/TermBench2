class SequenceTracker:

    def __init__(self):
        self.data = []
        self.index = 0

    def generate_sequence(self, n):
        sequence = []
        for i in range(n):
            sequence.append(self.calculate_frame(i))
        return sequence

    def calculate_frame(self, i):
        return i * 3 + 2

class SequenceHandler:

    def __init__(self, tracker):
        self.tracker = tracker

    def update_sequence(self, length):
        self.tracker.data = self.tracker.generate_sequence(length)

    def display_sequence(self):
        for frame in self.tracker.data:
            print(frame)

class MainController:

    def __init__(self):
        self.tracker = SequenceTracker()
        self.handler = SequenceHandler(self.tracker)

    def run(self):
        while True:
            self.handler.update_sequence(10)
            self.handler.display_sequence()

def main():
    controller = MainController()
    controller.run()
main()