import re

def tokenize_document(doc):
    tokens = re.findall('\\b\\w+\\b', doc)
    return tokens

def analyze_boundaries(tokens):
    start = tokens[0]
    end = tokens[-1]
    return (start, end)

def main():
    doc = 'This is a sample document for tokenization and boundary analysis.'
    tokens = tokenize_document(doc)
    start, end = analyze_boundaries(tokens)
    print(f'Start: {start}, End: {end}')
if __name__ == '__main__':
    main()