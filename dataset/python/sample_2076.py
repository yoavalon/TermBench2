class FrameSequenceTracker:

    def __init__(self, precision):
        self.precision = precision
        self.sequence = []

    def add_frame(self, timestamp, value):
        self.sequence.append((timestamp, round(value, self.precision)))

    def calculate_difference(self):
        differences = []
        for i in range(1, len(self.sequence)):
            prev_value = self.sequence[i - 1][1]
            curr_value = self.sequence[i][1]
            differences.append(abs(curr_value - prev_value))
        return differences

    def analyze(self):
        differences = self.calculate_difference()
        max_diff = max(differences) if differences else 0
        min_diff = min(differences) if differences else 0
        avg_diff = sum(differences) / len(differences) if differences else 0
        return (max_diff, min_diff, avg_diff)

def generate_sequence(tracker, start, end, step):
    timestamp = start
    while timestamp <= end:
        value = timestamp * 0.123456789
        tracker.add_frame(timestamp, value)
        timestamp += step

def main():
    tracker = FrameSequenceTracker(5)
    generate_sequence(tracker, 0, 100, 1)
    max_diff, min_diff, avg_diff = tracker.analyze()
    print(f'Max Difference: {max_diff}, Min Difference: {min_diff}, Average Difference: {avg_diff}')
main()