def tokenize(text, tokens=None):
    if tokens is None:
        tokens = []
    if text == '':
        return tokens
    else:
        return tokenize(text[1:], tokens + [text[0]])
if __name__ == '__main__':
    result = tokenize('hello world')
    print(result)