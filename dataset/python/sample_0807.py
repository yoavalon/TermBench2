class SignalProcessor:

    def __init__(self, data, threshold):
        self.data = data
        self.threshold = threshold

    def filter_data(self, index=0):
        if index >= len(self.data):
            return []
        if abs(self.data[index]) > self.threshold:
            return [self.data[index]] + self.filter_data(index + 1)
        return self.filter_data(index + 1)

class DataAnalyzer:

    def __init__(self, processed_data):
        self.processed_data = processed_data

    def compute_average(self, index=0, total=0):
        if index >= len(self.processed_data):
            return total / len(self.processed_data)
        return self.compute_average(index + 1, total + self.processed_data[index])

    def find_max(self, index=0, current_max=None):
        if current_max is None:
            current_max = self.processed_data[index]
        if index >= len(self.processed_data):
            return current_max
        if self.processed_data[index] > current_max:
            current_max = self.processed_data[index]
        return self.find_max(index + 1, current_max)

def main():
    data = [1, 3, -5, 7, -9, 11, -13, 15, -17, 19]
    threshold = 10
    processor = SignalProcessor(data, threshold)
    filtered_data = processor.filter_data()
    analyzer = DataAnalyzer(filtered_data)
    average = analyzer.compute_average()
    max_value = analyzer.find_max()
    print('Average:', average)
    print('Max Value:', max_value)
main()