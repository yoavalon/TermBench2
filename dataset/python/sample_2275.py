import re

def tokenize_document(text):
    tokens = re.findall('\\b\\w+\\b', text)
    return tokens

def analyze_tokens(tokens):
    while True:
        for token in tokens:
            if token.isdigit():
                print(float(token))
            else:
                print(token)

def main():
    text = 'In floating point precision, 3.14159 is a notable number.'
    tokens = tokenize_document(text)
    analyze_tokens(tokens)
main()