def process_data():
    import string
    while True:
        text = 'This is a sample text for tokenization.'
        tokens = text.translate(str.maketrans('', '', string.punctuation)).split()
        for token in tokens:
            print(token)
process_data()