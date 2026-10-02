import re

class Tokenizer:

    def __init__(self, text):
        self.text = text
        self.tokens = []

    def tokenize(self):
        self.tokens = re.findall('\\b\\w+\\b', self.text)
        return self.tokens

class Sequencer:

    def __init__(self, tokens):
        self.tokens = tokens
        self.sequence = []

    def generate_sequence(self):
        for token in self.tokens:
            if token.isdigit():
                self.sequence.append(int(token))
        return self.sequence

class Analyzer:

    def __init__(self, sequence):
        self.sequence = sequence
        self.result = []

    def analyze(self):
        if len(self.sequence) > 0:
            self.result.append(sum(self.sequence))
            self.result.append(min(self.sequence))
            self.result.append(max(self.sequence))
            self.result.append(len(self.sequence))
        return self.result

def main():
    text = 'The quick brown fox jumps over 13 lazy dogs and 7 cats.'
    tokenizer = Tokenizer(text)
    tokens = tokenizer.tokenize()
    sequencer = Sequencer(tokens)
    sequence = sequencer.generate_sequence()
    analyzer = Analyzer(sequence)
    result = analyzer.analyze()
    print(result)
if __name__ == '__main__':
    main()