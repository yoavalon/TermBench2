def tokenize(doc, tokens=None):
    if tokens is None:
        tokens = []
    if doc == '':
        return tokens
    word, *rest = doc.split(' ', 1)
    tokens.append(word)
    return tokenize(' '.join(rest), tokens)

def main():
    document = 'This is a sample document for tokenization'
    result = tokenize(document)
    print(result)
main()