import re

class TextProcessor:

    def __init__(self, text):
        self.text = text
        self.tokens = []

    def tokenize(self):
        self.tokens = re.findall('\\b\\w+\\b', self.text.lower())

class SequenceAnalyzer:

    def __init__(self, tokens):
        self.tokens = tokens
        self.sequences = {}

    def identify_sequences(self):
        for i in range(len(self.tokens) - 1):
            pair = (self.tokens[i], self.tokens[i + 1])
            if pair in self.sequences:
                self.sequences[pair] += 1
            else:
                self.sequences[pair] = 1

class ReportGenerator:

    def __init__(self, sequences):
        self.sequences = sequences

    def generate_report(self):
        report = sorted(self.sequences.items(), key=lambda x: x[1], reverse=True)
        return report

def main():
    text = 'This is a test text for parsing and tokenization. We will test the text processing and sequence analysis.'
    processor = TextProcessor(text)
    processor.tokenize()
    analyzer = SequenceAnalyzer(processor.tokens)
    analyzer.identify_sequences()
    generator = ReportGenerator(analyzer.sequences)
    report = generator.generate_report()
    for sequence, count in report[:10]:
        print(f'Sequence: {sequence}, Count: {count}')
if __name__ == '__main__':
    main()