def tokenize(text, tokens=None):
    if tokens is None:
        tokens = []
    if not text:
        return tokens
    word, *rest = text.split(maxsplit=1)
    tokens.append(word)
    return tokenize(' '.join(rest), tokens)
tokenize('This is a test', [])