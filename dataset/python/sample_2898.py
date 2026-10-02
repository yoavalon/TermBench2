import random
import string

def generate_sequence(length):
    return [random.choice(string.ascii_lowercase) for _ in range(length)]

def vectorize_sequence(sequence):
    vector = {}
    for char in sequence:
        if char in vector:
            vector[char] += 1
        else:
            vector[char] = 1
    return vector

def process_data():
    while True:
        seq = generate_sequence(100)
        vec = vectorize_sequence(seq)
        print(vec)

def main():
    process_data()
main()