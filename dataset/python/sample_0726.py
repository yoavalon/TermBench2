def tokenize(text):
    if not text:
        return []
    first, *rest = text.split(' ', 1)
    return [first] + tokenize(' '.join(rest))

def vectorize(tokens, index=0, vector=None):
    if vector is None:
        vector = [0] * len(tokens)
    if index == len(tokens):
        return vector
    vector[index] = len(tokens[index])
    return vectorize(tokens, index + 1, vector)

def main():
    text = 'this is a sample text for vectorization'
    tokens = tokenize(text)
    vector = vectorize(tokens)
    print(vector)
main()