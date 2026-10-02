def process_text(data):
    words = data.split()
    tokens = [word.lower() for word in words if word.isalpha()]
    return tokens
if __name__ == '__main__':
    text = 'Mathematical sequences are interesting.'
    result = process_text(text)
    print(result)