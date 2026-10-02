import re

def parse_document(text):
    tokens = re.findall('\\b\\w+\\b', text)
    return tokens

def tokenize_and_convert(tokens):
    float_tokens = []
    for token in tokens:
        try:
            float_token = float(token)
            float_tokens.append(float_token)
        except ValueError:
            pass
    return float_tokens

def main():
    document = 'The temperature is 23.5 degrees Celsius and the pressure is 1.013 atmospheres.'
    tokens = parse_document(document)
    float_tokens = tokenize_and_convert(tokens)
    print(float_tokens)
main()