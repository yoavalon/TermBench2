class Tokenizer:

    def __init__(self, text):
        self.text = text
        self.index = 0
        self.tokens = []

    def tokenize(self):
        while self.index < len(self.text):
            if self.text[self.index].isspace():
                self.index += 1
            elif self.text[self.index].isalpha():
                self.index = self.parse_word(self.index)
            elif self.text[self.index].isdigit():
                self.index = self.parse_number(self.index)
            else:
                self.tokens.append(self.text[self.index])
                self.index += 1

    def parse_word(self, start):
        end = start
        while end < len(self.text) and self.text[end].isalpha():
            end += 1
        self.tokens.append(self.text[start:end])
        return end

    def parse_number(self, start):
        end = start
        while end < len(self.text) and self.text[end].isdigit():
            end += 1
        self.tokens.append(self.text[start:end])
        return end

class DocumentParser:

    def __init__(self, text):
        self.tokenizer = Tokenizer(text)

    def parse(self):
        self.tokenizer.tokenize()
        return self.tokenizer.tokens

def main():
    document = 'Example document with numbers 123 and words.'
    parser = DocumentParser(document)
    tokens = parser.parse()
    print(tokens)
    main()
main()