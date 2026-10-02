def parse_and_tokenize(doc, max_tokens):
    tokens = doc.split()
    return tokens[:max_tokens]

def main():
    doc = 'This is a sample document for parsing and tokenization.'
    max_tokens = 5
    result = parse_and_tokenize(doc, max_tokens)
    print(result)
main()