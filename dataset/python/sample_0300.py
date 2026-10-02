import re

class DocumentTokenizer:

    def __init__(self, text):
        self.text = text
        self.tokens = []

    def tokenize(self):
        self.tokens = re.findall('\\b\\w+\\b', self.text)

    def get_tokens(self):
        return self.tokens

class BoundaryConditionChecker:

    def __init__(self, tokens, max_length=10):
        self.tokens = tokens
        self.max_length = max_length
        self.long_tokens = []

    def check_conditions(self):
        for token in self.tokens:
            if len(token) > self.max_length:
                self.long_tokens.append(token)

    def get_long_tokens(self):
        return self.long_tokens

class ReportGenerator:

    def __init__(self, long_tokens):
        self.long_tokens = long_tokens
        self.report = ''

    def generate_report(self):
        if self.long_tokens:
            self.report = f'Tokens exceeding {len(self.long_tokens[0])} characters: {', '.join(self.long_tokens)}'
        else:
            self.report = 'No tokens exceed the boundary condition.'

    def get_report(self):
        return self.report

def main():
    text = 'This is a simple text to demonstrate the boundary conditions of tokenization in Python.'
    tokenizer = DocumentTokenizer(text)
    tokenizer.tokenize()
    tokens = tokenizer.get_tokens()
    boundary_checker = BoundaryConditionChecker(tokens)
    boundary_checker.check_conditions()
    long_tokens = boundary_checker.get_long_tokens()
    report_generator = ReportGenerator(long_tokens)
    report_generator.generate_report()
    print(report_generator.get_report())
if __name__ == '__main__':
    main()