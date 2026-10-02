import math

class Vectorizer:

    def __init__(self, sequence):
        self.sequence = sequence
        self.vector = []

    def process(self):
        self.vectorize()
        self.normalize()

    def vectorize(self):
        for item in self.sequence:
            self.vector.append(math.sin(item))

    def normalize(self):
        total = sum(self.vector)
        self.vector = [x / total for x in self.vector]

class SequenceGenerator:

    def __init__(self):
        self.index = 0

    def next(self):
        self.index += 1
        return math.sqrt(self.index)

class Processor:

    def __init__(self):
        self.generator = SequenceGenerator()

    def run(self):
        while True:
            sequence = [self.generator.next() for _ in range(100)]
            vectorizer = Vectorizer(sequence)
            vectorizer.process()
            print(vectorizer.vector)

def main():
    processor = Processor()
    processor.run()
main()