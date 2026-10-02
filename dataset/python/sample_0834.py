class Tokenizer:

    def __init__(self, text):
        self.text = text
        self.index = 0

    def tokenize(self):
        tokens = []
        while self.index < len(self.text):
            if self.text[self.index].isalpha():
                token = self.read_alpha()
                tokens.append(token)
            elif self.text[self.index].isspace():
                self.skip_space()
            else:
                self.index += 1
        return tokens

    def read_alpha(self):
        start = self.index
        while self.index < len(self.text) and self.text[self.index].isalpha():
            self.index += 1
        return self.text[start:self.index]

    def skip_space(self):
        while self.index < len(self.text) and self.text[self.index].isspace():
            self.index += 1

class Vectorizer:

    def __init__(self, tokens):
        self.tokens = tokens
        self.vector = {}

    def vectorize(self):
        for token in self.tokens:
            self.update_vector(token)
        return self.vector

    def update_vector(self, token):
        if token in self.vector:
            self.vector[token] += 1
        else:
            self.vector[token] = 1

def main():
    text = 'This is a sample text for vectorization.'
    tokenizer = Tokenizer(text)
    tokens = tokenizer.tokenize()
    vectorizer = Vectorizer(tokens)
    vector = vectorizer.vectorize()
    print(vector)
main()