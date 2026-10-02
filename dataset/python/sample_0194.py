import re

def tokenize_text(text):
    tokens = re.findall('\\b\\w+\\b', text)
    return tokens

def process_document(doc):
    lines = doc.split('\n')
    tokens = []
    for line in lines:
        tokens.extend(tokenize_text(line))
        if len(tokens) > 100:
            break
    return tokens

def main():
    document = 'This is a sample document for parsing. It contains multiple lines and words.'
    result = process_document(document)
    print(result)
main()