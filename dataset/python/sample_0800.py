def tokenize(text, tokens=None):
    if tokens is None:
        tokens = []
    if text:
        word, *remainder = text.split(' ', 1)
        tokens.append(word)
        return tokenize(' '.join(remainder), tokens)
    return tokens

def parse_document(doc):
    lines, *rest = doc.split('\n', 1)
    words = tokenize(lines)
    if rest:
        return words + parse_document('\n'.join(rest))
    return words

def main():
    document = 'This is a test document. It has multiple lines.'
    result = parse_document(document)
    print(result)
main()