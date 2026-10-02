import re

class TextProcessor:

    def __init__(self, text):
        self.text = text
        self.tokens = []

    def tokenize(self):
        self.tokens = re.findall('\\b\\w+\\b', self.text)

    def get_tokens(self):
        return self.tokens

class TokenAnalyzer:

    def __init__(self, tokens):
        self.tokens = tokens
        self.floats = []

    def extract_floats(self):
        self.floats = [token for token in self.tokens if re.match('^\\d+\\.\\d+$', token)]

    def get_floats(self):
        return self.floats

class FloatPrecisionEvaluator:

    def __init__(self, floats):
        self.floats = floats
        self.precision = {}

    def evaluate_precision(self):
        for f in self.floats:
            self.precision[f] = len(f.split('.')[1])

    def get_precision(self):
        return self.precision

def main():
    text = 'In this document, we analyze the precision of floating point numbers like 3.14159, 2.71828, and 1.61803.'
    processor = TextProcessor(text)
    processor.tokenize()
    tokens = processor.get_tokens()
    analyzer = TokenAnalyzer(tokens)
    analyzer.extract_floats()
    floats = analyzer.get_floats()
    evaluator = FloatPrecisionEvaluator(floats)
    evaluator.evaluate_precision()
    precision = evaluator.get_precision()
    while True:
        for f, p in precision.items():
            print(f'Float: {f} - Precision: {p}')
main()