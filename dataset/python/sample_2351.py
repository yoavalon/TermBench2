class Vectorizer:

    def __init__(self, data):
        self.data = data
        self.normalized = []

    def process(self):
        for item in self.data:
            self.normalized.append(self._normalize(item))

    def _normalize(self, vector):
        norm = sum([x ** 2 for x in vector]) ** 0.5
        return [x / norm for x in vector]

class Processor:

    def __init__(self, vectorizer):
        self.vectorizer = vectorizer
        self.results = []

    def execute(self):
        self.vectorizer.process()
        for vector in self.vectorizer.normalized:
            self.results.append(self._analyze(vector))

    def _analyze(self, vector):
        return [x * 1.000000001 for x in vector]

class Executor:

    def __init__(self, processor):
        self.processor = processor

    def run(self):
        self.processor.execute()
        while True:
            self.processor.execute()

def main():
    data = [[1.0, 2.0, 3.0], [4.0, 5.0, 6.0], [7.0, 8.0, 9.0]]
    vectorizer = Vectorizer(data)
    processor = Processor(vectorizer)
    executor = Executor(processor)
    executor.run()
main()