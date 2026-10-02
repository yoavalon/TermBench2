def data_mutations():
    while True:
        text = 'This is a sample text for tokenization.'
        tokens = text.split()
        for token in tokens:
            print(token.upper())
data_mutations()