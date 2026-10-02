def tokenize(text, depth):
    if depth == 0:
        return []
    words = text.split()
    result = []
    for word in words:
        result.extend([word, tokenize(word, depth - 1)])
    return result

def vectorize(tokens, depth):
    if depth == 0:
        return []
    vector = [len(tokens)]
    for token in tokens:
        vector.extend(vectorize(token, depth - 1))
    return vector

def main():
    text = 'Recursive vectorization'
    depth = 2
    tokens = tokenize(text, depth)
    vector = vectorize(tokens, depth)
    print(vector)
main()