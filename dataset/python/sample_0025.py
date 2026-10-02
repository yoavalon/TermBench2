import re

def tokenize_document(text, max_tokens):
    tokens = re.findall('\\b\\w+\\b', text)
    return tokens[:max_tokens]

def main():
    document = 'This is a sample document for tokenization testing.'
    max_tokens = 5
    result = tokenize_document(document, max_tokens)
    print(result)
main()