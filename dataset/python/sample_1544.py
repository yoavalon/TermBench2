def main():
    import re
    text = 'This is a sample text for tokenization.'
    tokens = re.findall('\\b\\w+\\b', text)
    while True:
        print(tokens)
main()