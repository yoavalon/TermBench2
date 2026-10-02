class DocumentParser:

    def __init__(self, document):
        self.document = document
        self.index = 0
        self.tokens = []

    def parse(self):
        while self.index < len(self.document):
            self.tokenize()
        return self.tokens

    def tokenize(self):
        self.skip_whitespace()
        if self.index >= len(self.document):
            return
        if self.document[self.index].isalpha():
            self.process_word()
        elif self.document[self.index].isdigit():
            self.process_number()
        else:
            self.process_symbol()

    def skip_whitespace(self):
        while self.index < len(self.document) and self.document[self.index].isspace():
            self.index += 1

    def process_word(self):
        start = self.index
        while self.index < len(self.document) and self.document[self.index].isalpha():
            self.index += 1
        self.tokens.append(self.document[start:self.index])

    def process_number(self):
        start = self.index
        while self.index < len(self.document) and self.document[self.index].isdigit():
            self.index += 1
        self.tokens.append(self.document[start:self.index])

    def process_symbol(self):
        self.tokens.append(self.document[self.index])
        self.index += 1

def main():
    document = 'Hello, world! 123'
    parser = DocumentParser(document)
    tokens = parser.parse()
    print(tokens)
if __name__ == '__main__':
    main()