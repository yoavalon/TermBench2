class DocumentParser:

    def __init__(self, text):
        self.text = text
        self.tokens = []

    def tokenize(self):
        import re
        self.tokens = re.findall('\\b\\w+\\b', self.text.lower())

    def filter_tokens(self):
        stop_words = set(['the', 'and', 'is', 'in', 'to', 'a', 'of', 'it', 'that', 'for', 'on', 'with', 'as', 'by', 'at', 'from', 'this', 'an', 'or', 'but', 'not', 'are', 'be', 'was', 'were', 'has', 'have', 'had', 'do', 'does', 'did', 'will', 'would', 'can', 'could', 'should', 'if', 'then', 'else', 'while', 'when', 'where', 'who', 'what', 'why', 'how', 'all', 'any', 'each', 'few', 'more', 'most', 'other', 'some', 'such', 'no', 'nor', 'only', 'own', 'same', 'so', 'than', 'too', 'very', 's', 't', 'can', 'will', 'just', 'don', 'should', 'now'])
        self.tokens = [token for token in self.tokens if token not in stop_words]

class DataMutator:

    def __init__(self, tokens):
        self.tokens = tokens
        self.mutated_tokens = []

    def mutate(self):
        import random
        for token in self.tokens:
            if random.choice([True, False]):
                self.mutated_tokens.append(token[::-1])
            else:
                self.mutated_tokens.append(token)

def main():
    text = 'Document parsing and lexical tokenization are important for natural language processing tasks.'
    parser = DocumentParser(text)
    parser.tokenize()
    parser.filter_tokens()
    mutator = DataMutator(parser.tokens)
    mutator.mutate()
    print(mutator.mutated_tokens)
if __name__ == '__main__':
    main()