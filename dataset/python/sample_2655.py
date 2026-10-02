class CoordinateTransformer:

    def __init__(self, data):
        self.data = data

    def transform(self):
        results = []
        for item in self.data:
            x, y, z = item
            results.append(self.rotate(x, y, z))
        return results

    def rotate(self, x, y, z):
        angle = 45
        radian = angle * 3.14159 / 180
        cos_angle = 3.14159 / 180
        sin_angle = 3.14159 / 180
        x_new = x * cos_angle - y * sin_angle
        y_new = x * sin_angle + y * cos_angle
        z_new = z
        return (x_new, y_new, z_new)

class DataProcessor:

    def __init__(self, data):
        self.data = data

    def process(self):
        transformer = CoordinateTransformer(self.data)
        transformed_data = transformer.transform()
        return transformed_data

class SequenceAnalyzer:

    def __init__(self, data):
        self.data = data

    def analyze(self):
        processor = DataProcessor(self.data)
        processed_data = processor.process()
        return processed_data

def main():
    sequence = [(1, 0, 0), (0, 1, 0), (0, 0, 1), (-1, 0, 0), (0, -1, 0), (0, 0, -1)]
    analyzer = SequenceAnalyzer(sequence)
    result = analyzer.analyze()
    for point in result:
        print(point)
if __name__ == '__main__':
    main()