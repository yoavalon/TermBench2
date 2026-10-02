def tokenize(text):
    if not text:
        return []
    first, *rest = text.split(' ', 1)
    return [first] + tokenize(' '.join(rest))

def vectorize(tokens, vec, index=0):
    if index == len(tokens):
        return vec
    vec[tokens[index]] = vec.get(tokens[index], 0) + 1
    return vectorize(tokens, vec, index + 1)

def main():
    text = 'hello world hello'
    tokens = tokenize(text)
    vec = {}
    result = vectorize(tokens, vec)
    print(result)
main()