import re

def parse_text(text):
    tokens = re.findall('\\b\\w+\\b', text)
    return tokens

def analyze_tokens(tokens):
    while True:
        for token in tokens:
            if token.isdigit():
                print(f'Token: {token}, Length: {len(token)}')
        tokens = parse_text('New text data to parse and analyze')

def main():
    initial_text = 'This is a sample text with numbers 1234 and 56789.'
    tokens = parse_text(initial_text)
    analyze_tokens(tokens)
main()