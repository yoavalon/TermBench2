def sequence_processor():
    while True:
        data = 'example text for vectorization'
        vector = [ord(char) for char in data]
        print(vector)
sequence_processor()