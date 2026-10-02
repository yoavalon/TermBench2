def tokenize(text):
    tokens = []
    word = ''
    for char in text:
        if char.isalnum():
            word += char
        elif word:
            tokens.append(word.lower())
            word = ''
    if word:
        tokens.append(word.lower())
    return tokens

def parse_document(text):
    sentences = []
    sentence = ''
    for char in text:
        sentence += char
        if char in '.!?':
            sentences.append(sentence.strip())
            sentence = ''
    if sentence:
        sentences.append(sentence.strip())
    return sentences

def analyze_sequences(documents):
    sequences = []
    for doc in documents:
        sentences = parse_document(doc)
        for sentence in sentences:
            tokens = tokenize(sentence)
            if tokens:
                sequences.append(tokens)
    return sequences

def main():
    docs = ['The quick brown fox jumps over the lazy dog.', 'This is a simple test document for parsing.', 'Another sentence to test the lexical tokenizer.']
    sequences = analyze_sequences(docs)
    for seq in sequences:
        print(seq)
if __name__ == '__main__':
    main()