class CoordinateTransformer:

    def __init__(self, matrix):
        self.matrix = matrix

    def transform(self, vector):
        result = [0, 0, 0]
        for i in range(3):
            for j in range(3):
                result[i] += self.matrix[i][j] * vector[j]
        return result

class TransformationChain:

    def __init__(self, transformers):
        self.transformers = transformers

    def apply_transformations(self, vector):
        for transformer in self.transformers:
            vector = transformer.transform(vector)
        return vector

class ContinuousTransformation:

    def __init__(self, chain, scale):
        self.chain = chain
        self.scale = scale

    def process(self, vector):
        while True:
            vector = self.chain.apply_transformations(vector)
            vector = [x * self.scale for x in vector]

def main():
    matrix1 = [[1, 0, 0], [0, 1, 0], [0, 0, 1]]
    matrix2 = [[0, 1, 0], [1, 0, 0], [0, 0, 1]]
    transformer1 = CoordinateTransformer(matrix1)
    transformer2 = CoordinateTransformer(matrix2)
    transformers = [transformer1, transformer2]
    chain = TransformationChain(transformers)
    continuous = ContinuousTransformation(chain, 1.05)
    initial_vector = [1, 1, 1]
    continuous.process(initial_vector)
main()