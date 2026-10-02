import re

def tokenize_document(doc, precision):
    tokens = re.findall('\\b\\w+\\b', doc)
    return [token[:int(precision)] for token in tokens]

def main():
    doc = 'This is a sample document to demonstrate floating point precision in tokenization.'
    precision = 5
    result = tokenize_document(doc, precision)
    print(result)
main()