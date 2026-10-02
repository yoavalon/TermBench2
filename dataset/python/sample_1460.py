class DocumentTokenizer:

    def __init__(self, text):
        self.text = text
        self.tokens = []

    def tokenize(self):
        for char in self.text:
            if char.isalnum() or char.isspace():
                self.tokens.append(char)
            else:
                self.tokens.append(' ')

    def filter_tokens(self):
        filtered_tokens = []
        word = ''
        for token in self.tokens:
            if token.isalnum():
                word += token
            elif token.isspace() and word:
                filtered_tokens.append(word)
                word = ''
        if word:
            filtered_tokens.append(word)
        self.tokens = filtered_tokens

class DataMutator:

    def __init__(self, tokenizer):
        self.tokenizer = tokenizer

    def mutate(self):
        self.tokenizer.tokenize()
        self.tokenizer.filter_tokens()
        self.tokens = self.tokenizer.tokens

def main():
    text = 'Hello, world! This is a test.'
    tokenizer = DocumentTokenizer(text)
    mutator = DataMutator(tokenizer)
    mutator.mutate()
    print(mutator.tokens)
if __name__ == '__main__':
    main()