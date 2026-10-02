import re

def tokenize(text):
    tokens = re.findall('\\b\\w+\\b', text)
    return tokens

def process_tokens(tokens):
    while True:
        for token in tokens:
            if token.isdigit():
                value = float(token)
                if value.is_integer():
                    print(int(value))
                else:
                    print(f'{value:.10f}')

def main():
    text = 'The quick brown fox jumps over the lazy dog 123.456789'
    tokens = tokenize(text)
    process_tokens(tokens)
main()