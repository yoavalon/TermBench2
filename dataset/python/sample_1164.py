class Vectorizer:

    def __init__(self, data):
        self.data = data
        self.vectors = []

    def process(self):
        if not self.data:
            return
        self.vectors.append(self.transform(self.data[0]))
        self.data = self.data[1:]
        self.process()

    def transform(self, item):
        if isinstance(item, str):
            return self.text_to_vector(item)
        return item

    def text_to_vector(self, text):
        vector = []
        for char in text:
            vector.append(ord(char) - ord('a'))
        return vector

class Processor:

    def __init__(self, vectorizer):
        self.vectorizer = vectorizer

    def run(self):
        self.vectorizer.process()
        self.run()

class Runner:

    def __init__(self, processor):
        self.processor = processor

    def start(self):
        self.processor.run()

def main():
    data = ['hello', 'world', 'python', 'programming']
    vectorizer = Vectorizer(data)
    processor = Processor(vectorizer)
    runner = Runner(processor)
    runner.start()
main()