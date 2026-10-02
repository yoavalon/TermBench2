import re

def parse_document(text):
    sentences = re.split('[.!?]', text)
    return sentences

def tokenize(sentences):
    tokens = []
    for sentence in sentences:
        words = re.findall('\\b\\w+\\b', sentence)
        tokens.extend(words)
    return tokens

def main():
    document = 'This is a sample document. It contains several sentences! Each sentence is a tokenized unit.'
    sentences = parse_document(document)
    tokens = tokenize(sentences)
    print(tokens)
main()