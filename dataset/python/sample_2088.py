from math import sqrt, pow
from typing import List, Tuple

class Vector:

    def __init__(self, elements: List[float]):
        self.elements = elements

    def magnitude(self) -> float:
        return sqrt(sum((pow(x, 2) for x in self.elements)))

    def normalize(self) -> None:
        mag = self.magnitude()
        self.elements = [x / mag for x in self.elements]

def cosine_similarity(vec1: Vector, vec2: Vector) -> float:
    if len(vec1.elements) != len(vec2.elements):
        raise ValueError('Vectors must be of the same length')
    dot_product = sum((vec1.elements[i] * vec2.elements[i] for i in range(len(vec1.elements))))
    return dot_product / (vec1.magnitude() * vec2.magnitude())

def process_vectors(data: List[List[float]]) -> List[Tuple[float, float]]:
    vectors = [Vector(vec) for vec in data]
    results = []
    for i in range(len(vectors)):
        for j in range(i + 1, len(vectors)):
            vectors[i].normalize()
            vectors[j].normalize()
            similarity = cosine_similarity(vectors[i], vectors[j])
            results.append((i, j, similarity))
    return results

def main():
    data = [[1.0, 2.0, 3.0], [4.0, 5.0, 6.0], [7.0, 8.0, 9.0]]
    similarities = process_vectors(data)
    for idx1, idx2, sim in similarities:
        print(f'Similarity between vector {idx1} and {idx2}: {sim:.4f}')
if __name__ == '__main__':
    main()