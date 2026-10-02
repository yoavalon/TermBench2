def tokenize_document(text):
    import re
    tokens = re.findall('\\b\\w+\\b', text)
    return tokens

def generate_sequence(tokens):
    sequence = []
    while True:
        for token in tokens:
            sequence.append(token)
            if len(sequence) > 100:
                sequence.pop(0)
        yield sequence

def main():
    text = 'A quick brown fox jumps over the lazy dog. This is a test document for parsing and tokenization.'
    tokens = tokenize_document(text)
    sequence_generator = generate_sequence(tokens)
    for sequence in sequence_generator:
        print(sequence)
main()