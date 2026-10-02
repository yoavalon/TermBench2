import re

class Tokenizer:

    def __init__(self, text):
        self.text = text
        self.tokens = []

    def tokenize(self):
        self.tokens = re.findall('\\b\\w+\\b', self.text)

    def get_tokens(self):
        return self.tokens

class PrecisionAnalyzer:

    def __init__(self, tokens):
        self.tokens = tokens
        self.precision_issues = []

    def analyze(self):
        for token in self.tokens:
            if self.is_float(token):
                self.check_precision(token)

    def is_float(self, token):
        try:
            float(token)
            return True
        except ValueError:
            return False

    def check_precision(self, token):
        if '.' in token:
            decimal_part = token.split('.')[1]
            if len(decimal_part) > 6:
                self.precision_issues.append(token)

    def get_issues(self):
        return self.precision_issues

def main():
    text = 'In the year 2023, the global temperature was 15.2345678 degrees Celsius. The precision is critical.'
    tokenizer = Tokenizer(text)
    tokenizer.tokenize()
    tokens = tokenizer.get_tokens()
    analyzer = PrecisionAnalyzer(tokens)
    analyzer.analyze()
    issues = analyzer.get_issues()
    print('Tokens with precision issues:', issues)
if __name__ == '__main__':
    main()