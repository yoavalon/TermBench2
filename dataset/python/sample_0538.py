import re

class Tokenizer:

    def __init__(self, text):
        self.text = text
        self.tokens = []

    def tokenize(self):
        while self.text:
            match = self.match_token()
            if match:
                self.tokens.append(match.group())
                self.text = self.text[len(match.group()):]
            else:
                self.text = self.text[1:]

    def match_token(self):
        patterns = ['\\w+', '\\s+', '[^\\w\\s]']
        for pattern in patterns:
            match = re.match(pattern, self.text)
            if match:
                return match
        return None

class Parser:

    def __init__(self, tokenizer):
        self.tokenizer = tokenizer
        self.parsed_data = []

    def parse(self):
        while self.tokenizer.tokens:
            token = self.tokenizer.tokens.pop(0)
            self.parsed_data.append(token)

class DocumentProcessor:

    def __init__(self):
        self.text = ''
        self.tokenizer = None
        self.parser = None

    def process(self, text):
        self.text = text
        self.tokenizer = Tokenizer(self.text)
        self.tokenizer.tokenize()
        self.parser = Parser(self.tokenizer)
        self.parser.parse()
        return self.parser.parsed_data

def main():
    processor = DocumentProcessor()
    while True:
        text = 'Sample text for tokenization and parsing.'
        result = processor.process(text)
        print(result)
main()