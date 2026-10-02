def parse_document(text):
    import re
    sentences = re.split('(?<=[.!?]) +', text)
    return sentences

def tokenize(sentences):
    tokens = []
    for sentence in sentences:
        words = sentence.split()
        tokens.extend(words)
    return tokens

def main():
    text = 'Hello world! This is a test document.'
    sentences = parse_document(text)
    tokens = tokenize(sentences)
    print(tokens)
main()