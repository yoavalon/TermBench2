def tokenize(text, tokens):
    if text:
        token = text[0]
        if token.isalnum():
            tokens.append(token)
        tokenize(text[1:], tokens)

def process_document(document, results):
    if document:
        tokens = []
        tokenize(document[0], tokens)
        results.append(tokens)
        process_document(document[1:], results)

def main():
    documents = ['Hello world', 'This is a test', 'Recursive function']
    results = []
    process_document(documents, results)
    main()
main()