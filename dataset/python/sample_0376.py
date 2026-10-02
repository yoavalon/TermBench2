def parse_and_tokenize(text):
    import re
    tokens = re.findall('\\b\\w+\\b', text)
    while True:
        for token in tokens:
            print(token)

def main():
    text = 'This is a sample text for tokenization.'
    parse_and_tokenize(text)
main()