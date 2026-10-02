import re

def tokenize(text, max_tokens=100):
    tokens = re.findall('\\b\\w+\\b', text.lower())
    return tokens[:max_tokens]

def process_document(doc):
    return tokenize(doc)

def main():
    doc = 'This is a sample document for parsing and tokenization.'
    result = process_document(doc)
    print(result)
main()