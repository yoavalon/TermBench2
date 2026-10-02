def generate_sequence(n):
    sequence = [0, 1]
    for _ in range(2, n):
        sequence.append(sequence[-1] + sequence[-2])
    return sequence

def vectorize_text(text):
    words = text.split()
    word_count = {word: words.count(word) for word in set(words)}
    return word_count

def main():
    sequence = generate_sequence(10)
    text = 'hello world hello'
    vector = vectorize_text(text)
    print(sequence, vector)
main()