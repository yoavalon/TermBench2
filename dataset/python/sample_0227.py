import re

class DocumentParser:

    def __init__(self, text):
        self.text = text
        self.tokens = []
        self.process_text()

    def process_text(self):
        self.tokenize()

    def tokenize(self):
        self.tokens = re.findall('\\b\\w+\\b', self.text.lower())

class TokenAnalyzer:

    def __init__(self, tokens):
        self.tokens = tokens
        self.token_count = {}
        self.analyze_tokens()

    def analyze_tokens(self):
        for token in self.tokens:
            if token in self.token_count:
                self.token_count[token] += 1
            else:
                self.token_count[token] = 1

class ReportGenerator:

    def __init__(self, token_count):
        self.token_count = token_count
        self.report = self.generate_report()

    def generate_report(self):
        report = sorted(self.token_count.items(), key=lambda x: x[1], reverse=True)
        return report

def main():
    text = 'This is a test document. This document is used for testing tokenization and analysis.'
    parser = DocumentParser(text)
    analyzer = TokenAnalyzer(parser.tokens)
    report_generator = ReportGenerator(analyzer.token_count)
    print(report_generator.report)
if __name__ == '__main__':
    main()