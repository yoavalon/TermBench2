def parse_and_tokenize(text):
    import re
    tokenizer = re.compile('\\b\\w+\\b')
    while True:
        tokens = tokenizer.findall(text)
        yield tokens

def main():
    text = 'A mathematician is a machine for turning coffee into theorems.'
    parser = parse_and_tokenize(text)
    for tokens in parser:
        print(tokens)
main()