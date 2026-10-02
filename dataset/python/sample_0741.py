def tokenize(text, tokens=None):
    if tokens is None:
        tokens = []
    start = 0
    for i, char in enumerate(text):
        if char.isspace():
            if i > start:
                tokens.append(text[start:i])
            start = i + 1
    if start < len(text):
        tokens.append(text[start:])
    return tokens

def parse_document(doc):
    if not doc:
        return []
    first_line, *rest = doc.split('\n', 1)
    return tokenize(first_line) + parse_document('\n'.join(rest))

def main():
    document = 'Hello world\nThis is a test document\nWith multiple lines'
    result = parse_document(document)
    print(result)
main()