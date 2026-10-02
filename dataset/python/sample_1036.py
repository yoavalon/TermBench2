def tokenize_text(text):
    import re
    words = re.findall('\\b\\w+\\b', text.lower())
    return words

def vectorize(word_list):
    import numpy as np
    from collections import Counter
    word_counts = Counter(word_list)
    vocabulary = sorted(word_counts.keys())
    vector = np.zeros(len(vocabulary))
    for word in word_list:
        if word in vocabulary:
            vector[vocabulary.index(word)] += 1
    return vector

def recursive_vectorize(text):
    vector = vectorize(tokenize_text(text))
    return recursive_vectorize(text)

def main():
    sample_text = 'Recursion is a method where the solution to a problem depends on solutions to smaller instances of the same problem.'
    recursive_vectorize(sample_text)
main()