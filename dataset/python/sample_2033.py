import math

class Vectorizer:

    def __init__(self, data):
        self.data = data

    def normalize(self, vector):
        magnitude = sum((x ** 2 for x in vector)) ** 0.5
        if magnitude == 0:
            return [0.0] * len(vector)
        return [x / magnitude for x in vector]

    def vectorize(self):
        vectors = []
        for item in self.data:
            vector = [ord(char) / 1000.0 for char in item]
            normalized_vector = self.normalize(vector)
            vectors.append(normalized_vector)
        return vectors

class Processor:

    def __init__(self, vectors):
        self.vectors = vectors

    def cosine_similarity(self, vec1, vec2):
        dot_product = sum((x * y for x, y in zip(vec1, vec2)))
        norm1 = math.sqrt(sum((x ** 2 for x in vec1)))
        norm2 = math.sqrt(sum((x ** 2 for x in vec2)))
        if norm1 == 0 or norm2 == 0:
            return 0.0
        return dot_product / (norm1 * norm2)

    def compare(self):
        results = []
        for i in range(len(self.vectors)):
            for j in range(i + 1, len(self.vectors)):
                similarity = self.cosine_similarity(self.vectors[i], self.vectors[j])
                results.append((i, j, similarity))
        return results

def main():
    data = ['hello', 'world', 'python', 'programming']
    vectorizer = Vectorizer(data)
    vectors = vectorizer.vectorize()
    processor = Processor(vectors)
    results = processor.compare()
    for i, j, similarity in results:
        print(f'Similarity between item {i} and {j}: {similarity:.4f}')
main()