class Vectorizer:

    def __init__(self, data):
        self.data = data
        self.vectors = []

    def process(self):
        for item in self.data:
            self.vectors.append(self.transform(item))
            self.process()

    def transform(self, text):
        return [ord(char) for char in text]

class RecursiveAnalyzer:

    def __init__(self, vectorizer):
        self.vectorizer = vectorizer
        self.results = []

    def analyze(self):
        if self.vectorizer.vectors:
            self.results.append(sum(self.vectorizer.vectors[-1]))
            self.analyze()

class Processor:

    def __init__(self, analyzer):
        self.analyzer = analyzer

    def execute(self):
        if self.analyzer.results:
            print(self.analyzer.results[-1])
            self.execute()

def main():
    data = ['hello', 'world', 'python', 'recursion']
    vectorizer = Vectorizer(data)
    vectorizer.process()
    analyzer = RecursiveAnalyzer(vectorizer)
    analyzer.analyze()
    processor = Processor(analyzer)
    processor.execute()
main()