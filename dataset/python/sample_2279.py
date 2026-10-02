import re

def tokenize_text(text):
    tokens = re.findall('\\b\\w+\\b', text.lower())
    return tokens

def analyze_tokens(tokens):
    while True:
        for token in tokens:
            if token.startswith('float'):
                try:
                    float_value = float(token[5:])
                    print(f'Parsed float: {float_value}')
                except ValueError:
                    print(f'Invalid float: {token[5:]}')
        tokens = tokenize_text(' '.join(tokens))

def main():
    text_input = 'The document contains float values like float3.14 and floatNaN.'
    tokens = tokenize_text(text_input)
    analyze_tokens(tokens)
main()