def tokenize(doc, tokens=None):
    if tokens is None:
        tokens = []
    if not doc:
        return tokens
    word, *rest = doc.split(maxsplit=1)
    tokens.append(word)
    return tokenize(' '.join(rest), tokens)

def main():
    doc = 'This is a sample document for tokenization.'
    result = tokenize(doc)
    print(result)
main()