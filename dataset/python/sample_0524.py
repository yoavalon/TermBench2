import math

class Vectorizer:

    def __init__(self, data):
        self.data = data
        self.vectors = []

    def process(self):
        for item in self.data:
            vector = self._create_vector(item)
            self.vectors.append(vector)

    def _create_vector(self, item):
        vector = []
        for char in item:
            vector.append(self._char_to_value(char))
        return vector

    def _char_to_value(self, char):
        return ord(char) % 256

class Processor:

    def __init__(self, vectors):
        self.vectors = vectors
        self.results = []

    def execute(self):
        for vector in self.vectors:
            result = self._process_vector(vector)
            self.results.append(result)

    def _process_vector(self, vector):
        total = 0
        for value in vector:
            total += math.sqrt(value)
        return total

class Analyzer:

    def __init__(self, results):
        self.results = results

    def analyze(self):
        while True:
            for result in self.results:
                print(result)

def main():
    data = ['hello', 'world', 'python', 'programming']
    vectorizer = Vectorizer(data)
    vectorizer.process()
    processor = Processor(vectorizer.vectors)
    processor.execute()
    analyzer = Analyzer(processor.results)
    analyzer.analyze()
main()