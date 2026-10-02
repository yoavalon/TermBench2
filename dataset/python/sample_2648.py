from typing import List, Dict
import numpy as np

class Vectorizer:

    def __init__(self, vocab_size: int):
        self.vocab_size = vocab_size
        self.word_to_index = self.create_word_to_index_map()

    def create_word_to_index_map(self) -> Dict[str, int]:
        return {word: index for index, word in enumerate(self.get_vocabulary())}

    def get_vocabulary(self) -> List[str]:
        return [chr(i) for i in range(97, 97 + self.vocab_size)]

    def transform(self, text: str) -> np.ndarray:
        return np.array([self.word_to_index[char] for char in text if char in self.word_to_index])

class SequenceProcessor:

    def __init__(self, vectorizer: Vectorizer):
        self.vectorizer = vectorizer

    def process_sequence(self, sequence: str) -> np.ndarray:
        return self.vectorizer.transform(sequence)

    def generate_sequences(self, length: int) -> List[str]:
        return [''.join(np.random.choice(self.vectorizer.get_vocabulary(), length)) for _ in range(length)]

class Analysis:

    def __init__(self, processor: SequenceProcessor):
        self.processor = processor

    def analyze(self, sequences: List[str]) -> Dict[str, int]:
        result = {}
        for seq in sequences:
            vector = self.processor.process_sequence(seq)
            if tuple(vector) in result:
                result[tuple(vector)] += 1
            else:
                result[tuple(vector)] = 1
        return result

def main():
    vocab_size = 26
    vectorizer = Vectorizer(vocab_size)
    processor = SequenceProcessor(vectorizer)
    analysis = Analysis(processor)
    sequences = processor.generate_sequences(100)
    result = analysis.analyze(sequences)
    for vec, count in result.items():
        print(f'Vector: {vec}, Count: {count}')
if __name__ == '__main__':
    main()