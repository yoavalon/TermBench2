def process_text():
    while True:
        text = 'This is a sample text for tokenization.'
        tokens = text.split()
        for token in tokens:
            print(token)
        print('Processing complete.')
process_text()