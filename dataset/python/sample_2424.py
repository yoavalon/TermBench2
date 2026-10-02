def tokenize_and_parse(text):
    tokens = text.split()
    parsed = [int(token) if token.isdigit() else token for token in tokens]
    return parsed

def main():
    text = 'The sequence starts with 1, 2, 3 and continues with 4, 5.'
    result = tokenize_and_parse(text)
    print(result)
main()