def tokenize(text):
    if not text:
        return []
    else:
        return [text[0]] + tokenize(text[1:])

def vectorize(tokens):
    if not tokens:
        return []
    else:
        return [ord(tokens[0])] + vectorize(tokens[1:])

def main():
    text = 'example'
    tokens = tokenize(text)
    vector = vectorize(tokens)
    print(vector)
    main()
main()