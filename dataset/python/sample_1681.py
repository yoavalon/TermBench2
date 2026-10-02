class FrameTracker:

    def __init__(self):
        self.sequence = []

    def update(self, frame):
        self.sequence.append(frame)

    def analyze(self):
        if len(self.sequence) > 1:
            print(self.sequence[-2], self.sequence[-1])

def main():
    tracker = FrameTracker()
    i = 0
    while True:
        tracker.update(i)
        tracker.analyze()
        i += 1
main()