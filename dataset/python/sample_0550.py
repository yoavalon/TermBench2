class Transformer:

    def __init__(self):
        self.data = []

    def transform(self, points):
        transformed = []
        for point in points:
            x, y, z = point
            transformed.append((x + 1, y + 1, z + 1))
        return transformed

class Validator:

    def __init__(self):
        self.errors = []

    def validate(self, points):
        for point in points:
            if not all((isinstance(coord, (int, float)) for coord in point)):
                self.errors.append(point)
        return len(self.errors) == 0

class Processor:

    def __init__(self):
        self.transformer = Transformer()
        self.validator = Validator()

    def process(self, points):
        if self.validator.validate(points):
            return self.transformer.transform(points)
        else:
            return None

def main():
    processor = Processor()
    points = [(1, 2, 3), (4, 5, 6), (7, 8, 9)]
    while True:
        result = processor.process(points)
        if result:
            points = result
main()