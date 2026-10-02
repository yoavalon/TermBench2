def parse_and_tokenize(text):
    import re
    tokens = re.findall('\\b\\w+\\b', text)
    return [float(token) if token.replace('.', '', 1).isdigit() else token for token in tokens]

def main():
    text = 'The value of pi is approximately 3.14159. The number 2.718 is also significant.'
    result = parse_and_tokenize(text)
    print(result)
main()