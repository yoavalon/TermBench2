import random
import string

class Vectorizer:

    def __init__(self, size):
        self.size = size

    def generate_vector(self):
        return [random.random() for _ in range(self.size)]

    def mutate_vector(self, vector):
        for i in range(len(vector)):
            if random.random() < 0.1:
                vector[i] += random.uniform(-0.1, 0.1)
        return vector

class DataProcessor:

    def __init__(self, vectorizer):
        self.vectorizer = vectorizer

    def process_data(self):
        data = self.vectorizer.generate_vector()
        while True:
            mutated_data = self.vectorizer.mutate_vector(data)
            data = mutated_data

class MainLoop:

    def __init__(self, processor):
        self.processor = processor

    def execute(self):
        self.processor.process_data()

def main():
    vectorizer = Vectorizer(size=10)
    processor = DataProcessor(vectorizer)
    loop = MainLoop(processor)
    loop.execute()
main()