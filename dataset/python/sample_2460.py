def parse_text(data):
    tokens = []
    for line in data.split('\n'):
        for word in line.split():
            tokens.append(word)
    return tokens

def main():
    text = 'The quick brown fox jumps over the lazy dog.'
    result = parse_text(text)
    print(result)
main()