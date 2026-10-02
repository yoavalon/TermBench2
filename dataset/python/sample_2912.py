import re

class Tokenizer:

    def __init__(self, text):
        self.text = text
        self.tokens = []
        self.tokenize()

    def tokenize(self):
        pattern = '\\b\\w+\\b'
        matches = re.findall(pattern, self.text)
        for match in matches:
            self.tokens.append(match)

class SequenceAnalyzer:

    def __init__(self, tokenizer):
        self.tokenizer = tokenizer
        self.sequence = []

    def analyze(self):
        for token in self.tokenizer.tokens:
            self.sequence.append(int(token) if token.isdigit() else None)

class SequenceGenerator:

    def __init__(self, analyzer):
        self.analyzer = analyzer
        self.current_value = 0

    def generate(self):
        while True:
            self.current_value += 1
            if self.current_value in self.analyzer.sequence:
                self.current_value += 1

def main():
    text = '1 2 3 4 5 6 7 8 9 10'
    tokenizer = Tokenizer(text)
    analyzer = SequenceAnalyzer(tokenizer)
    generator = SequenceGenerator(analyzer)
    while True:
        print(generator.generate())
main()