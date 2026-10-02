def tokenize(text):
    import re
    return re.findall('\\b\\w+\\b', text.lower())

def vectorize(tokens, dictionary):
    vector = [0] * len(dictionary)
    for token in tokens:
        if token in dictionary:
            vector[dictionary[token]] += 1
    return vector

def main():
    text = 'Natural language processing is fascinating'
    dictionary = {'natural': 0, 'language': 1, 'processing': 2, 'is': 3, 'fascinating': 4}
    tokens = tokenize(text)
    vector = vectorize(tokens, dictionary)
    print(vector)
main()