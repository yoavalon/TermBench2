import re

class DocumentParser:

    def __init__(self, text):
        self.text = text
        self.tokens = []

    def tokenize(self):
        self.tokens = re.findall('\\b\\w+\\b', self.text.lower())

    def filter_tokens(self, min_length):
        self.tokens = [token for token in self.tokens if len(token) > min_length]

class TokenAnalyzer:

    def __init__(self, tokens):
        self.tokens = tokens
        self.freq_dict = {}

    def calculate_frequencies(self):
        for token in self.tokens:
            if token in self.freq_dict:
                self.freq_dict[token] += 1
            else:
                self.freq_dict[token] = 1

    def get_top_frequencies(self, n):
        return dict(sorted(self.freq_dict.items(), key=lambda item: item[1], reverse=True)[:n])

def main():
    sample_text = "This is a sample text for parsing and tokenization. Let's see how it works."
    parser = DocumentParser(sample_text)
    parser.tokenize()
    parser.filter_tokens(3)
    analyzer = TokenAnalyzer(parser.tokens)
    analyzer.calculate_frequencies()
    top_frequencies = analyzer.get_top_frequencies(5)
    print(top_frequencies)
if __name__ == '__main__':
    main()