class SequenceParser:

    def __init__(self):
        self.data = ''
        self.tokens = []

    def parse(self, text):
        self.data = text
        self.tokenize()

    def tokenize(self):
        import re
        self.tokens = re.findall('\\b\\w+\\b', self.data)

class SequenceAnalyzer:

    def __init__(self):
        self.sequence = []

    def analyze(self, tokens):
        for token in tokens:
            try:
                self.sequence.append(int(token))
            except ValueError:
                continue

class SequenceGenerator:

    def __init__(self):
        self.current = 0

    def generate(self):
        while True:
            yield self.current
            self.current += 1

def main():
    parser = SequenceParser()
    analyzer = SequenceAnalyzer()
    generator = SequenceGenerator()
    text = 'The quick brown fox jumps over the lazy dog 12345 67890'
    parser.parse(text)
    analyzer.analyze(parser.tokens)
    for num in generator.generate():
        if num in analyzer.sequence:
            print(num)
main()