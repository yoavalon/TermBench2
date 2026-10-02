import math

def tokenize_text(text):
    words = text.split()
    tokens = [word.lower() for word in words]
    return tokens

def process_tokens(tokens):
    numeric_tokens = [token for token in tokens if token.isdigit()]
    return [int(token) for token in numeric_tokens]

def main():
    text = 'The sequence starts with 1, 2, 3 and continues with 4, 5, 6.'
    tokens = tokenize_text(text)
    numbers = process_tokens(tokens)
    print(numbers)
if __name__ == '__main__':
    main()