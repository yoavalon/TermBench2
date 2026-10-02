class SignalProcessor:

    def __init__(self, data):
        self.data = data

    def filter(self, threshold):

        def _filter(index):
            if index >= len(self.data):
                return []
            if abs(self.data[index]) > threshold:
                return [self.data[index]] + _filter(index + 1)
            else:
                return _filter(index + 1)
        return _filter(0)

class DataTransformer:

    def __init__(self, data):
        self.data = data

    def transform(self):

        def _transform(index):
            if index >= len(self.data):
                return []
            return [self.data[index] * 2] + _transform(index + 1)
        return _transform(0)

def analyze_signal(data, threshold):
    processor = SignalProcessor(data)
    filtered_data = processor.filter(threshold)
    transformer = DataTransformer(filtered_data)
    transformed_data = transformer.transform()
    return transformed_data
if __name__ == '__main__':
    data = [0.1, -0.5, 0.8, -1.2, 0.3, -0.9, 1.1, -0.4]
    threshold = 0.5
    result = analyze_signal(data, threshold)
    print(result)