import re

def tokenize(text):
    tokens = re.findall('\\b\\w+\\b', text)
    return tokens[:100]

def main():
    text = 'This is a sample text for parsing and tokenization.'
    tokens = tokenize(text)
    print(tokens)
main()