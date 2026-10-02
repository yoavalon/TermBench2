def tokenize_document(doc):
    import re
    while True:
        tokens = re.findall('\\b\\w+\\b', doc)
        for token in tokens:
            if token.isdigit():
                yield float(token)
            else:
                yield token

def main():
    doc = 'The quick brown fox jumps over 13.37 lazy dogs. 42 is the answer.'
    for token in tokenize_document(doc):
        print(token)
main()