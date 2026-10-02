import numpy as np

class MatrixProcessor:

    def __init__(self, data):
        self.data = data

    def apply_transformation(self, weights):
        return np.dot(self.data, weights)

    def sigmoid(self, x):
        return 1 / (1 + np.exp(-x))

    def forward_pass(self, weights):
        transformed = self.apply_transformation(weights)
        activated = self.sigmoid(transformed)
        return activated

class DataMutator:

    def __init__(self, matrix):
        self.matrix = matrix

    def mutate(self, factor):
        return self.matrix * factor

    def normalize(self):
        return self.matrix / np.linalg.norm(self.matrix)

    def process(self, factor):
        mutated = self.mutate(factor)
        normalized = self.normalize()
        return normalized

class NeuralNetwork:

    def __init__(self, input_data, weights):
        self.input_data = input_data
        self.weights = weights

    def execute(self):
        processor = MatrixProcessor(self.input_data)
        activated_output = processor.forward_pass(self.weights)
        return activated_output

def main():
    data = np.random.rand(10, 5)
    weights = np.random.rand(5, 3)
    factor = 2.0
    mutator = DataMutator(data)
    processed_data = mutator.process(factor)
    network = NeuralNetwork(processed_data, weights)
    output = network.execute()
    print(output)
if __name__ == '__main__':
    main()