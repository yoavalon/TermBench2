def vectorize_text(text, vec=None):
    if vec is None:
        vec = {}
    for word in text.split():
        if word in vec:
            vec[word] += 1
        else:
            vec[word] = 1
    return vectorize_text(text, vec)

def main():
    text = 'hello world hello'
    result = vectorize_text(text)
    print(result)
main()