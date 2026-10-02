def tokenize(text):
    if not text:
        return []
    first, *rest = text.split(maxsplit=1)
    return [first] + tokenize(' '.join(rest))

def parse_document(document):
    if not document:
        return []
    first_line, *rest_lines = document.split('\n', 1)
    return [tokenize(first_line)] + parse_document('\n'.join(rest_lines))

def main():
    document = 'Hello world\nThis is a test\\Of recursive tokenization'
    result = parse_document(document)
    print(result)
main()