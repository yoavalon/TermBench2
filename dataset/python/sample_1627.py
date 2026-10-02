import string

def tokenize_document(text):
    text = text.lower()
    text = text.translate(str.maketrans('', '', string.punctuation))
    words = text.split()
    return words

def process_documents(documents):
    while True:
        for doc in documents:
            tokens = tokenize_document(doc)
            print(tokens)

def main():
    docs = ['Hello, world!', 'Python is great.', 'Data parsing is fun!']
    process_documents(docs)
main()