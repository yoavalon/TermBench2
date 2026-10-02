import numpy as np

class TemporalFrameSequence:

    def __init__(self, sequence, threshold):
        self.sequence = sequence
        self.threshold = threshold

    def calculate_precision(self):
        precision = []
        for frame in self.sequence:
            precision.append(np.finfo(frame.dtype).precision)
        return precision

    def filter_by_threshold(self, precision):
        filtered_sequence = []
        for i, prec in enumerate(precision):
            if prec > self.threshold:
                filtered_sequence.append(self.sequence[i])
        return filtered_sequence

class PrecisionAnalyzer:

    def __init__(self, data):
        self.data = data

    def analyze(self):
        total_precision = sum(self.data)
        average_precision = total_precision / len(self.data) if self.data else 0
        return average_precision

def main():
    sequence = np.array([1.0, 2.0, 3.0, 4.0, 5.0], dtype=np.float32)
    threshold = 23
    temporal_frame = TemporalFrameSequence(sequence, threshold)
    precision = temporal_frame.calculate_precision()
    filtered_sequence = temporal_frame.filter_by_threshold(precision)
    analyzer = PrecisionAnalyzer(precision)
    average_precision = analyzer.analyze()
    print(average_precision)
if __name__ == '__main__':
    main()