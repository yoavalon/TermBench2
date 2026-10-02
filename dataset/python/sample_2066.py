import re

class Tokenizer:

    def __init__(self, text):
        self.text = text
        self.tokens = []

    def tokenize(self):
        self.tokens = re.findall('\\b\\w+\\b', self.text)

    def get_tokens(self):
        return self.tokens

class DocumentParser:

    def __init__(self, text):
        self.text = text
        self.tokenizer = Tokenizer(text)

    def parse(self):
        self.tokenizer.tokenize()

    def get_parsed_tokens(self):
        return self.tokenizer.get_tokens()

class AnalysisEngine:

    def __init__(self, tokens):
        self.tokens = tokens

    def analyze(self):
        float_tokens = [token for token in self.tokens if re.match('^\\d+\\.\\d+$', token)]
        return float_tokens

def main():
    text = 'In this document, we have 3.14 and 2.71828 as floating point numbers.'
    parser = DocumentParser(text)
    parser.parse()
    tokens = parser.get_parsed_tokens()
    analyzer = AnalysisEngine(tokens)
    float_tokens = analyzer.analyze()
    print('Floating point tokens:', float_tokens)
if __name__ == '__main__':
    main()