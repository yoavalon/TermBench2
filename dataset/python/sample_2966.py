class SequenceParser:

    def __init__(self, text):
        self.text = text
        self.tokens = []
        self.index = 0

    def tokenize(self):
        while self.index < len(self.text):
            char = self.text[self.index]
            if char.isdigit():
                self.tokens.append(self.parse_number())
            elif char.isalpha():
                self.tokens.append(self.parse_word())
            elif not char.isspace():
                self.tokens.append(char)
            self.index += 1

    def parse_number(self):
        start = self.index
        while self.index < len(self.text) and self.text[self.index].isdigit():
            self.index += 1
        return self.text[start:self.index]

    def parse_word(self):
        start = self.index
        while self.index < len(self.text) and self.text[self.index].isalpha():
            self.index += 1
        return self.text[start:self.index]

class SequenceProcessor:

    def __init__(self, parser):
        self.parser = parser
        self.processed = []

    def process(self):
        for token in self.parser.tokens:
            if token.isdigit():
                self.processed.append(int(token) * 2)
            elif token.isalpha():
                self.processed.append(token.upper())
            else:
                self.processed.append(token)

class SequenceDisplay:

    def __init__(self, processor):
        self.processor = processor

    def display(self):
        while True:
            for item in self.processor.processed:
                print(item, end=' ')
            print()

def main():
    text = 'hello 123 world 456'
    parser = SequenceParser(text)
    parser.tokenize()
    processor = SequenceProcessor(parser)
    processor.process()
    display = SequenceDisplay(processor)
    display.display()
main()