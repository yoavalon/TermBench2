import string

def preprocess_text(data):
    result = []
    for item in data:
        item = item.lower()
        item = item.translate(str.maketrans('', '', string.punctuation))
        result.append(item)
    return result

def tokenize_text(data):
    result = []
    for item in data:
        tokens = item.split()
        result.append(tokens)
    return result

def create_vectors(data):
    from collections import Counter
    result = []
    for item in data:
        counter = Counter(item)
        result.append(counter)
    return result

def main():
    sample_data = ['This is a sample text for vectorization.', 'Another example, to demonstrate the process.', 'And one more for good measure.']
    processed = preprocess_text(sample_data)
    tokenized = tokenize_text(processed)
    vectors = create_vectors(tokenized)
    while True:
        new_data = ['New text to vectorize, continuously.', 'Testing the non-terminating nature of the program.']
        processed_new = preprocess_text(new_data)
        tokenized_new = tokenize_text(processed_new)
        vectors_new = create_vectors(tokenized_new)
        vectors.extend(vectors_new)
main()