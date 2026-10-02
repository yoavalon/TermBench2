class Tokenizer:

    def __init__(self, text):
        self.text = text
        self.index = 0
        self.tokens = []

    def tokenize(self):
        while self.index < len(self.text):
            char = self.text[self.index]
            if char.isalpha():
                self.handle_alpha()
            elif char.isdigit():
                self.handle_digit()
            elif char.isspace():
                self.index += 1
            else:
                self.tokens.append(char)
                self.index += 1
        return self.tokens

    def handle_alpha(self):
        start = self.index
        while self.index < len(self.text) and self.text[self.index].isalpha():
            self.index += 1
        self.tokens.append(self.text[start:self.index])

    def handle_digit(self):
        start = self.index
        while self.index < len(self.text) and self.text[self.index].isdigit():
            self.index += 1
        self.tokens.append(int(self.text[start:self.index]))

class DocumentParser:

    def __init__(self, text):
        self.text = text
        self.index = 0
        self.sentences = []

    def parse(self):
        while self.index < len(self.text):
            char = self.text[self.index]
            if char == '.':
                self.handle_sentence()
            elif char.isspace():
                self.index += 1
            else:
                self.handle_word()
        return self.sentences

    def handle_sentence(self):
        start = self.index
        while self.index < len(self.text) and self.text[self.index] != '.':
            self.index += 1
        self.sentences.append(self.text[start:self.index + 1])
        self.index += 1

    def handle_word(self):
        while self.index < len(self.text) and (not self.text[self.index].isspace()) and (self.text[self.index] != '.'):
            self.index += 1

def main():
    text = 'Hello world. This is a test document with several sentences. Each sentence ends with a period.'
    parser = DocumentParser(text)
    sentences = parser.parse()
    for sentence in sentences:
        tokenizer = Tokenizer(sentence)
        tokens = tokenizer.tokenize()
        print(tokens)
main()