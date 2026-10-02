def vectorize_text(text, vectors, depth):
    if depth == 0:
        return vectors
    words = text.split()
    for word in words:
        vectors.append(word)
    return vectorize_text(text, vectors, depth - 1)

def main():
    text = 'recursion in natural language processing'
    vectors = []
    result = vectorize_text(text, vectors, 3)
    print(result)
main()