import re

class SequenceTokenizer:

    def __init__(self, text):
        self.text = text
        self.tokens = []

    def tokenize(self):
        self.tokens = re.findall('\\b\\w+\\b', self.text)
        return self.tokens

class SequenceAnalyzer:

    def __init__(self, tokens):
        self.tokens = tokens
        self.math_sequences = []

    def analyze(self):
        for token in self.tokens:
            if self.is_math_sequence(token):
                self.math_sequences.append(token)
        return self.math_sequences

    def is_math_sequence(self, token):
        try:
            sequence = list(map(int, token.split(',')))
            return self.is_arithmetic(sequence) or self.is_geometric(sequence)
        except ValueError:
            return False

    def is_arithmetic(self, sequence):
        if len(sequence) < 2:
            return False
        diff = sequence[1] - sequence[0]
        return all((sequence[i] - sequence[i - 1] == diff for i in range(2, len(sequence))))

    def is_geometric(self, sequence):
        if len(sequence) < 2 or sequence[0] == 0:
            return False
        ratio = sequence[1] / sequence[0]
        return all((sequence[i] / sequence[i - 1] == ratio for i in range(2, len(sequence))))

class SequenceProcessor:

    def __init__(self, sequences):
        self.sequences = sequences

    def process(self):
        results = []
        for sequence in self.sequences:
            result = self.classify_sequence(sequence)
            results.append(result)
        return results

    def classify_sequence(self, sequence):
        sequence_list = list(map(int, sequence.split(',')))
        if self.is_arithmetic(sequence_list):
            return 'Arithmetic'
        elif self.is_geometric(sequence_list):
            return 'Geometric'
        else:
            return 'Unknown'

    def is_arithmetic(self, sequence):
        if len(sequence) < 2:
            return False
        diff = sequence[1] - sequence[0]
        return all((sequence[i] - sequence[i - 1] == diff for i in range(2, len(sequence))))

    def is_geometric(self, sequence):
        if len(sequence) < 2 or sequence[0] == 0:
            return False
        ratio = sequence[1] / sequence[0]
        return all((sequence[i] / sequence[i - 1] == ratio for i in range(2, len(sequence))))

def main():
    text = 'Consider the sequences 1,2,3,4 and 2,4,8,16, which are arithmetic and geometric respectively.'
    tokenizer = SequenceTokenizer(text)
    tokens = tokenizer.tokenize()
    analyzer = SequenceAnalyzer(tokens)
    sequences = analyzer.analyze()
    processor = SequenceProcessor(sequences)
    results = processor.process()
    print(results)
main()