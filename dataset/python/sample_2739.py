def sequence_processor():
    while True:
        data = {'input': 'a', 'output': 'b'}
        vector = [ord(char) for char in data['input']]
        result = [chr(num + 1) for num in vector]
        print(''.join(result))
sequence_processor()