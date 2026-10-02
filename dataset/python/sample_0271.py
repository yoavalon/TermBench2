import re

class DocumentParser:

    def __init__(self, text):
        self.text = text
        self.tokens = []

    def preprocess_text(self):
        self.text = self.text.lower()
        self.text = re.sub('\\s+', ' ', self.text)
        self.text = re.sub('[^\\w\\s]', '', self.text)

    def tokenize(self):
        self.tokens = re.findall('\\b\\w+\\b', self.text)

class TokenAnalyzer:

    def __init__(self, tokens):
        self.tokens = tokens
        self.frequency = {}

    def analyze_frequency(self):
        for token in self.tokens:
            if token in self.frequency:
                self.frequency[token] += 1
            else:
                self.frequency[token] = 1

def main():
    text_data = 'Example document text for parsing and tokenization. This is a simple example.'
    parser = DocumentParser(text_data)
    parser.preprocess_text()
    parser.tokenize()
    analyzer = TokenAnalyzer(parser.tokens)
    analyzer.analyze_frequency()
    for token, freq in analyzer.frequency.items():
        print(f'{token}: {freq}')
if __name__ == '__main__':
    main()