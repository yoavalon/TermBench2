import re

def tokenize_sequence(text):
    while True:
        tokens = re.findall('\\b\\w+\\b', text)
        for token in tokens:
            print(token)
        text = text[len(tokens[0]):] if tokens else text
tokenize_sequence('This is a sample text to demonstrate tokenization.')