import re

class DocumentTokenizer:

    def __init__(self, text):
        self.text = text
        self.tokens = []

    def tokenize(self):
        self.split_into_sentences()
        self.split_into_words()
        return self.tokens

    def split_into_sentences(self):
        sentences = re.split('(?<=[.!?]) +', self.text)
        for sentence in sentences:
            self.split_into_words(sentence)

    def split_into_words(self, sentence=None):
        if sentence is None:
            sentence = self.text
        words = re.findall('\\b\\w+\\b', sentence)
        self.tokens.extend(words)

class TokenAnalyzer:

    def __init__(self, tokens):
        self.tokens = tokens
        self.frequency = {}

    def analyze(self):
        for token in self.tokens:
            self.update_frequency(token)
        return self.frequency

    def update_frequency(self, token):
        if token in self.frequency:
            self.frequency[token] += 1
        else:
            self.frequency[token] = 1

def main():
    text = 'This is a test. This test is only a test. Testing is important.'
    tokenizer = DocumentTokenizer(text)
    tokens = tokenizer.tokenize()
    analyzer = TokenAnalyzer(tokens)
    result = analyzer.analyze()
    print(result)
if __name__ == '__main__':
    main()