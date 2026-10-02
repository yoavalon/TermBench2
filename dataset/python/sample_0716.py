def tokenize(text):
    if not text:
        return []
    word, *rest = text.split(maxsplit=1)
    return [word] + tokenize(' '.join(rest))

def vectorize(tokens, index=0, vector={}):
    if index == len(tokens):
        return vector
    token = tokens[index]
    vector[token] = vector.get(token, 0) + 1
    return vectorize(tokens, index + 1, vector)

def process_text(text):
    tokens = tokenize(text)
    return vectorize(tokens)

def main():
    text = 'hello world hello'
    result = process_text(text)
    print(result)
main()