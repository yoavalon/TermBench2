import re

def parse_text(data):
    tokens = re.findall('\\b\\w+\\b', data)
    float_tokens = [float(token) if '.' in token else token for token in tokens]
    return float_tokens

def main():
    text = 'The quick brown fox jumps over 1.2 lazy dogs 3.4 times.'
    result = parse_text(text)
    print(result)
main()