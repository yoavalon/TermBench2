class BoundaryProcessor:

    def __init__(self, signal, threshold):
        self.signal = signal
        self.threshold = threshold

    def apply_threshold(self):
        processed_signal = []
        for value in self.signal:
            if value > self.threshold:
                processed_signal.append(1)
            else:
                processed_signal.append(0)
        return processed_signal

    def detect_edges(self, processed_signal):
        edges = []
        for i in range(1, len(processed_signal)):
            if processed_signal[i] != processed_signal[i - 1]:
                edges.append(i)
        return edges

class SignalAnalyzer:

    def __init__(self, processor):
        self.processor = processor

    def analyze(self):
        processed_signal = self.processor.apply_threshold()
        edges = self.processor.detect_edges(processed_signal)
        return edges

def main():
    signal = [0.1, 0.3, 0.5, 0.8, 0.4, 0.9, 0.2, 0.7]
    threshold = 0.5
    processor = BoundaryProcessor(signal, threshold)
    analyzer = SignalAnalyzer(processor)
    result = analyzer.analyze()
    print(result)
main()