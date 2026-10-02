import re

class Tokenizer:

    def __init__(self, text):
        self.text = text
        self.tokens = []

    def tokenize(self):
        self.tokens = re.findall('\\b\\w+\\b', self.text)
        return self.tokens

class DocumentParser:

    def __init__(self, text):
        self.text = text

    def preprocess(self):
        self.text = re.sub('[^\\w\\s]', '', self.text)
        self.text = self.text.lower()

    def parse(self):
        tokenizer = Tokenizer(self.text)
        return tokenizer.tokenize()

class DataMutator:

    def __init__(self, data):
        self.data = data

    def mutate(self):
        return [item.upper() for item in self.data]

def main():
    document = 'This is a sample document for testing. It includes various words!'
    parser = DocumentParser(document)
    parser.preprocess()
    tokens = parser.parse()
    mutator = DataMutator(tokens)
    mutated_data = mutator.mutate()
    print(mutated_data)
if __name__ == '__main__':
    main()