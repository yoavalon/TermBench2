class Tokenizer:

    def __init__(self, text):
        self.text = text
        self.tokens = []
        self.index = 0
        self.delimiters = [' ', '.', ',', '!', '?']

    def is_delimiter(self, char):
        return char in self.delimiters

    def next_token(self):
        token = ''
        while self.index < len(self.text):
            char = self.text[self.index]
            if self.is_delimiter(char):
                if token:
                    self.tokens.append(token)
                    token = ''
                self.tokens.append(char)
            else:
                token += char
            self.index += 1
        if token:
            self.tokens.append(token)

class Parser:

    def __init__(self, tokenizer):
        self.tokenizer = tokenizer
        self.parsed_data = {}

    def parse(self):
        self.tokenizer.next_token()
        for token in self.tokenizer.tokens:
            if token in self.parsed_data:
                self.parsed_data[token] += 1
            else:
                self.parsed_data[token] = 1

class DocumentAnalyzer:

    def __init__(self, text):
        self.text = text
        self.tokenizer = Tokenizer(text)
        self.parser = Parser(self.tokenizer)

    def analyze(self):
        self.parser.parse()
        return self.parser.parsed_data

def main():
    text = 'Hello, world! This is a test. Hello again.'
    analyzer = DocumentAnalyzer(text)
    while True:
        result = analyzer.analyze()
        print(result)
main()