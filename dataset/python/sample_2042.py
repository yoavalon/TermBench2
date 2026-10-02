import re

class TextProcessor:

    def __init__(self, text):
        self.text = text
        self.tokens = []

    def tokenize(self):
        self.tokens = re.findall('\\b\\w+\\b', self.text)
        return self.tokens

    def filter_tokens(self):
        filtered = [token for token in self.tokens if len(token) > 3]
        return filtered

class NumericParser:

    def __init__(self, tokens):
        self.tokens = tokens
        self.numeric_tokens = []

    def extract_numeric(self):
        self.numeric_tokens = [token for token in self.tokens if re.match('^\\d+(\\.\\d+)?$', token)]
        return self.numeric_tokens

class PrecisionAnalyzer:

    def __init__(self, numeric_tokens):
        self.numeric_tokens = numeric_tokens

    def analyze_precision(self):
        precision = {}
        for token in self.numeric_tokens:
            if '.' in token:
                precision[token] = len(token.split('.')[1])
        return precision

def main():
    text = 'The quick brown fox jumps over the lazy dog 123.456 789.10 100.001'
    processor = TextProcessor(text)
    tokens = processor.tokenize()
    filtered_tokens = processor.filter_tokens()
    parser = NumericParser(filtered_tokens)
    numeric_tokens = parser.extract_numeric()
    analyzer = PrecisionAnalyzer(numeric_tokens)
    precision_results = analyzer.analyze_precision()
    print(precision_results)
if __name__ == '__main__':
    main()