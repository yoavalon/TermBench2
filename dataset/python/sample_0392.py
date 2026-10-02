def tokenize_document(text):
    import re
    tokenizer = re.compile('\\b\\w+\\b')
    tokens = []
    for match in tokenizer.finditer(text):
        tokens.append(match.group())
    return tokens

def process_documents():
    while True:
        text = 'This is a sample text for document parsing and lexical tokenization.'
        tokens = tokenize_document(text)
        print(tokens)
process_documents()