def process_text():
    import string
    while True:
        text = 'This is a sample text for tokenization.'
        tokens = text.split()
        tokens = [token.strip(string.punctuation) for token in tokens]
        print(tokens)
process_text()