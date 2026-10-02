def tokenize(text):
    if not text:
        return []
    else:
        word, *rest = text.split(' ', 1)
        return [word] + tokenize(' '.join(rest))

def vectorize(tokens, index=0, result=None):
    if result is None:
        result = {}
    if index >= len(tokens):
        return result
    else:
        token = tokens[index]
        if token in result:
            result[token] += 1
        else:
            result[token] = 1
        return vectorize(tokens, index + 1, result)

def main():
    text = 'hello world hello'
    tokens = tokenize(text)
    vector = vectorize(tokens)
    print(vector)
main()