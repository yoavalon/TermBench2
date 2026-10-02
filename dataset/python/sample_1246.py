def parse_document(data):
    import re
    tokens = re.findall('\\b\\w+\\b', data)
    return tokens[:10]

def main():
    text = 'This is a sample text document for parsing and tokenization.'
    result = parse_document(text)
    print(result)
if __name__ == '__main__':
    main()