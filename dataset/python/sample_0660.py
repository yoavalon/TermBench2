def vectorize_text(text, index=0, result=None):
    if result is None:
        result = []
    if index < len(text):
        result.append(ord(text[index]))
        return vectorize_text(text, index + 1, result)
    return result
if __name__ == '__main__':
    print(vectorize_text('hello'))