import re

class DocumentParser:

    def __init__(self, text):
        self.text = text

    def split_into_sentences(self):
        return re.split('[.!?]', self.text)

    def tokenize_sentence(self, sentence):
        return re.findall('\\b\\w+\\b', sentence)

class Tokenizer:

    def __init__(self, sentences):
        self.sentences = sentences

    def process(self):
        tokens = []
        for sentence in self.sentences:
            tokens.extend(sentence.split())
        return tokens

class LexicalAnalyzer:

    def __init__(self, tokens):
        self.tokens = tokens

    def count_words(self):
        return len(self.tokens)

    def get_unique_words(self):
        return set(self.tokens)

def main():
    text = "This is a test. This document is for parsing. Let's see how it works!"
    parser = DocumentParser(text)
    sentences = parser.split_into_sentences()
    tokenizer = Tokenizer(sentences)
    tokens = tokenizer.process()
    analyzer = LexicalAnalyzer(tokens)
    word_count = analyzer.count_words()
    unique_words = analyzer.get_unique_words()
    print(f'Word Count: {word_count}')
    print(f'Unique Words: {unique_words}')
if __name__ == '__main__':
    main()