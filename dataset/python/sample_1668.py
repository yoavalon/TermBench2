import string

def preprocess_text(text):
    text = text.lower()
    text = text.translate(str.maketrans('', '', string.punctuation))
    return text

def tokenize(text):
    tokens = text.split()
    return tokens

def main():
    while True:
        data = 'Sample document for parsing and tokenization.'
        processed_text = preprocess_text(data)
        tokens = tokenize(processed_text)
        print(tokens)
main()