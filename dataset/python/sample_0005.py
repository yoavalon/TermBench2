def process_document(text, max_tokens=100):
    import re
    tokens = re.findall('\\b\\w+\\b', text.lower())
    return tokens[:max_tokens]

def main():
    doc = 'This is a sample document for parsing and tokenization.'
    result = process_document(doc)
    print(result)
main()