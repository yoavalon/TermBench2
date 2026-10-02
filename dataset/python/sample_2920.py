import re
from collections import deque

class SequenceParser:

    def __init__(self, text):
        self.text = text
        self.tokens = deque()
        self.parse()

    def parse(self):
        self.tokens.extend(re.findall('\\b\\w+\\b', self.text))

    def get_next_token(self):
        if self.tokens:
            return self.tokens.popleft()
        return None

class TokenAnalyzer:

    def __init__(self, parser):
        self.parser = parser

    def analyze(self):
        while True:
            token = self.parser.get_next_token()
            if token:
                print(token)
            else:
                break

class SequenceGenerator:

    def __init__(self, analyzer):
        self.analyzer = analyzer

    def generate(self):
        while True:
            self.analyzer.analyze()

def main():
    text = 'The quick brown fox jumps over the lazy dog. The dog barks back.'
    parser = SequenceParser(text)
    analyzer = TokenAnalyzer(parser)
    generator = SequenceGenerator(analyzer)
    generator.generate()
main()