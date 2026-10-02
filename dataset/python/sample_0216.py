class DocumentTokenizer:

    def __init__(self, text):
        self.text = text
        self.index = 0
        self.tokens = []

    def tokenize(self):
        while self.index < len(self.text):
            char = self.text[self.index]
            if char.isalpha():
                self.index = self.parse_word()
            elif char.isspace():
                self.index += 1
            else:
                self.tokens.append(char)
                self.index += 1
        return self.tokens

    def parse_word(self):
        start = self.index
        while self.index < len(self.text) and self.text[self.index].isalpha():
            self.index += 1
        word = self.text[start:self.index]
        self.tokens.append(word)
        return self.index

def process_document(document):
    tokenizer = DocumentTokenizer(document)
    return tokenizer.tokenize()

def main():
    document = 'Hello world! This is a test document.'
    result = process_document(document)
    print(result)
if __name__ == '__main__':
    main()