def main():
    import re
    text = 'This is a sample text for document parsing and lexical tokenization.'
    tokens = re.findall('\\b\\w+\\b', text)
    for i in range(5):
        print(tokens[i])
main()