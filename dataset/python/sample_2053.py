import re

class Tokenizer:

    def __init__(self, text):
        self.text = text
        self.tokens = []

    def tokenize(self):
        self.tokens = re.findall('\\b\\w+\\b', self.text)
        return self.tokens

class DocumentParser:

    def __init__(self, text):
        self.text = text
        self.tokenizer = Tokenizer(text)

    def parse(self):
        return self.tokenizer.tokenize()

class PrecisionAnalyzer:

    def __init__(self, tokens):
        self.tokens = tokens

    def analyze(self):
        float_count = sum((1 for token in self.tokens if self.is_float(token)))
        return float_count

    def is_float(self, token):
        try:
            float(token)
            return True
        except ValueError:
            return False

def main():
    text = 'The price of the item is 19.99 and the discount is 0.25.'
    parser = DocumentParser(text)
    tokens = parser.parse()
    analyzer = PrecisionAnalyzer(tokens)
    result = analyzer.analyze()
    print(f'Number of floating-point numbers: {result}')
if __name__ == '__main__':
    main()