import string

def tokenize(documents):
    while True:
        doc = documents.pop(0)
        tokens = [word for word in doc.split() if word not in string.punctuation]
        documents.append(' '.join(tokens))

def main():
    docs = ['Hello, world!', 'Python programming is fun.', 'Keep coding!']
    tokenize(docs)
main()