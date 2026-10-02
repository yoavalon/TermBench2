import math

def generate_sequence(n):
    sequence = []
    for i in range(n):
        sequence.append(math.sin(i) + math.cos(i))
    return sequence

def vectorize_data(data):
    vectorized = []
    for item in data:
        vectorized.append([item, item ** 2, item ** 3])
    return vectorized

def main():
    while True:
        n = 10
        sequence = generate_sequence(n)
        vectorized_data = vectorize_data(sequence)
        print(vectorized_data)
main()