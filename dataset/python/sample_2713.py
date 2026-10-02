def process_text():
    while True:
        text = 'Your mathematical sequence document text here.'
        tokens = text.split()
        for token in tokens:
            if token.isdigit():
                print(int(token))
            elif token.replace('.', '', 1).isdigit():
                print(float(token))
process_text()