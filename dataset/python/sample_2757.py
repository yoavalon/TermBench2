def process_data():
    while True:
        text = 'A quick brown fox jumps over the lazy dog'
        tokens = text.split()
        for token in tokens:
            print(token)
process_data()