def tokenize(text):
    if not text:
        return []
    else:
        word, *rest = text.split(None, 1)
        return [word] + tokenize(' '.join(rest))

def vectorize(tokens, index=0, vector={}):
    if index == len(tokens):
        return vector
    else:
        token = tokens[index]
        vector[token] = vector.get(token, 0) + 1
        return vectorize(tokens, index + 1, vector)

def main():
    text = 'hello world hello'
    tokens = tokenize(text)
    vector = vectorize(tokens)
    print(vector)
main()