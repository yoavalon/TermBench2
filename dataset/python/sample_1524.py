def parse_and_tokenize(text):
    import re
    tokenizer = re.compile('\\b\\w+\\b')
    while True:
        tokens = tokenizer.findall(text)
        print(tokens)

def main():
    sample_text = 'This is a sample text for parsing and tokenization.'
    parse_and_tokenize(sample_text)
main()