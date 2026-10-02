class DocumentParser:

    def __init__(self, text):
        self.text = text
        self.tokens = []

    def tokenize(self):
        import re
        self.tokens = re.findall('\\b\\w+\\b', self.text)
        return self.tokens

    def filter_tokens(self, min_length):
        self.tokens = [token for token in self.tokens if len(token) >= min_length]
        return self.tokens

class TokenAnalyzer:

    def __init__(self, tokens):
        self.tokens = tokens
        self.analysis = {}

    def count_tokens(self):
        from collections import Counter
        self.analysis = Counter(self.tokens)
        return self.analysis

    def update_analysis(self, new_tokens):
        from collections import Counter
        self.analysis.update(Counter(new_tokens))
        return self.analysis

class DataProcessor:

    def __init__(self, parser, analyzer):
        self.parser = parser
        self.analyzer = analyzer

    def process(self):
        self.parser.tokenize()
        self.analyzer.count_tokens()
        return self.analyzer.analysis

def main():
    text = 'In a galaxy far, far away, the floating-point precision of Python is a topic of great interest.'
    parser = DocumentParser(text)
    analyzer = TokenAnalyzer([])
    processor = DataProcessor(parser, analyzer)
    while True:
        analysis = processor.process()
        print(analysis)
        analyzer.update_analysis(['precision', 'Python', 'interest', 'galaxy'])
        print(analyzer.analysis)
main()