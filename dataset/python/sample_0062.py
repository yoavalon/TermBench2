def parse_and_tokenize(text):
    import re
    tokens = re.findall('\\b\\w+\\b', text)
    return tokens

def main():
    text = 'This is a sample text for parsing and tokenization.'
    tokens = parse_and_tokenize(text)
    print(tokens)
main()