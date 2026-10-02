def tokenize(text):
    if not text:
        return []
    word, *rest = text.split(' ', 1)
    return [word] + tokenize(' '.join(rest))

def vectorize(tokens, index=0, vec=[]):
    if index == len(tokens):
        return vec
    token = tokens[index]
    vector = [1 if t == token else 0 for t in tokens]
    return vectorize(tokens, index + 1, vec + [vector])

def main():
    text = 'hello world hello'
    tokens = tokenize(text)
    vectors = vectorize(tokens)
    print(vectors)
main()