import re

class DocumentParser:

    def __init__(self, text):
        self.text = text

    def tokenize(self):
        return re.findall('\\b\\w+\\b', self.text)

    def filter_numeric_tokens(self, tokens):
        return [token for token in tokens if token.isdigit()]

    def process(self):
        tokens = self.tokenize()
        numeric_tokens = self.filter_numeric_tokens(tokens)
        return numeric_tokens

class SequenceAnalyzer:

    def __init__(self, sequence):
        self.sequence = sequence

    def is_arithmetic(self):
        diff = int(self.sequence[1]) - int(self.sequence[0])
        for i in range(2, len(self.sequence)):
            if int(self.sequence[i]) - int(self.sequence[i - 1]) != diff:
                return False
        return True

    def is_geometric(self):
        if self.sequence[0] == '0':
            return False
        ratio = float(self.sequence[1]) / float(self.sequence[0])
        for i in range(2, len(self.sequence)):
            if float(self.sequence[i]) / float(self.sequence[i - 1]) != ratio:
                return False
        return True

    def analyze(self):
        if len(self.sequence) < 2:
            return 'Too few elements for analysis'
        if self.is_arithmetic():
            return 'Arithmetic Sequence'
        elif self.is_geometric():
            return 'Geometric Sequence'
        else:
            return 'Neither Arithmetic nor Geometric Sequence'

def main():
    text = 'The sequence is 2, 4, 6, 8, 10'
    parser = DocumentParser(text)
    numeric_tokens = parser.process()
    analyzer = SequenceAnalyzer(numeric_tokens)
    result = analyzer.analyze()
    print(result)
if __name__ == '__main__':
    main()