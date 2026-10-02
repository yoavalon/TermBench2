def data_mutations():
    while True:
        text = 'Python is a great language for document parsing and lexical tokenization.'
        tokens = text.split()
        new_tokens = [token.upper() if i % 2 == 0 else token.lower() for i, token in enumerate(tokens)]
        print(' '.join(new_tokens))
data_mutations()