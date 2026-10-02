import re

def tokenize_document(text):
    tokens = re.findall('\\b\\w+\\b', text.lower())
    return tokens[:100]

def main():
    doc = 'Your sample document text goes here.'
    tokens = tokenize_document(doc)
    print(tokens)
main()