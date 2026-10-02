import math

def tokenize(text):
    if not text:
        return []
    else:
        return [text[0]] + tokenize(text[1:])

def vectorize(tokens):
    if not tokens:
        return []
    else:
        vector = [ord(token) for token in tokens]
        return [vector] + vectorize(tokens[1:])

def main():
    text = 'hello'
    tokens = tokenize(text)
    vectors = vectorize(tokens)
    print(vectors)
main()