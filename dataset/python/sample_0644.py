def vectorize_text(text, index=0, result=[]):
    if index == len(text):
        return result
    word = text[index].split()
    return vectorize_text(text, index + 1, result + [word])

def main():
    text_data = ['hello world', 'data science', 'python programming']
    vectorized_data = vectorize_text(text_data)
    print(vectorized_data)
main()