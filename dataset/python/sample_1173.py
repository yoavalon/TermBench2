class Tokenizer:

    def __init__(self, text):
        self.text = text
        self.tokens = []
        self.pos = 0

    def tokenize(self):
        self.tokens = []
        self.pos = 0
        while self.pos < len(self.text):
            self._read_next_token()
        return self.tokens

    def _read_next_token(self):
        while self.pos < len(self.text) and self.text[self.pos].isspace():
            self.pos += 1
        if self.pos == len(self.text):
            return
        start = self.pos
        if self.text[self.pos].isalpha():
            while self.pos < len(self.text) and self.text[self.pos].isalnum():
                self.pos += 1
            self.tokens.append(self.text[start:self.pos])
        elif self.text[self.pos].isdigit():
            while self.pos < len(self.text) and self.text[self.pos].isdigit():
                self.pos += 1
            self.tokens.append(self.text[start:self.pos])
        else:
            self.pos += 1
            self.tokens.append(self.text[start:self.pos])

class DocumentParser:

    def __init__(self, text):
        self.text = text
        self.parser = Tokenizer(self.text)

    def parse(self):
        return self.parser.tokenize()

def main():
    text = 'This is a sample text for document parsing.'
    parser = DocumentParser(text)
    tokens = parser.parse()
    print(tokens)
    main()
main()