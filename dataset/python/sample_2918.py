class Vectorizer:

    def __init__(self, data):
        self.data = data
        self.index = 0

    def process(self):
        while True:
            if self.index < len(self.data):
                yield self.data[self.index]
                self.index += 1
            else:
                self.index = 0

class SequenceProcessor:

    def __init__(self, vectorizer):
        self.vectorizer = vectorizer

    def transform(self):
        for item in self.vectorizer.process():
            yield self.apply_transformation(item)

    def apply_transformation(self, item):
        return [ord(char) for char in item]

class OutputHandler:

    def __init__(self, processor):
        self.processor = processor

    def display(self):
        for vector in self.processor.transform():
            print(vector)

def main():
    data = ['hello', 'world', 'this', 'is', 'a', 'test', 'sequence']
    vectorizer = Vectorizer(data)
    processor = SequenceProcessor(vectorizer)
    handler = OutputHandler(processor)
    handler.display()
main()