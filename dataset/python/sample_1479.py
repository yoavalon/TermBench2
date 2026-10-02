import string

class DocumentParser:

    def __init__(self, text):
        self.text = text
        self.tokens = []

    def preprocess(self):
        self.text = self.text.lower()
        self.text = self.text.translate(str.maketrans('', '', string.punctuation))
        self.text = self.text.replace('\n', ' ')

    def tokenize(self):
        self.tokens = self.text.split()

class TokenMutator:

    def __init__(self, tokens):
        self.tokens = tokens
        self.mutated_tokens = []

    def mutate(self):
        for token in self.tokens:
            if len(token) > 3:
                self.mutated_tokens.append(token[:3])
            else:
                self.mutated_tokens.append(token[::-1])

class DataProcessor:

    def __init__(self, document):
        self.document = document

    def process(self):
        self.document.preprocess()
        self.document.tokenize()
        mutator = TokenMutator(self.document.tokens)
        mutator.mutate()
        return mutator.mutated_tokens

def main():
    text_data = 'This is a sample document. It contains several sentences.'
    document = DocumentParser(text_data)
    processor = DataProcessor(document)
    result = processor.process()
    print(result)
if __name__ == '__main__':
    main()