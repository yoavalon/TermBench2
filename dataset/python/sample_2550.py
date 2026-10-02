from math import sqrt

def process_data(data):
    vectors = []
    for item in data:
        vector = [len(item), sqrt(len(item)), sum((ord(c) for c in item)) / len(item)]
        vectors.append(vector)
    return vectors

def analyze_sequences(sequences):
    results = []
    for sequence in sequences:
        processed = process_data(sequence)
        average_vector = [sum(x) / len(processed) for x in zip(*processed)]
        results.append(average_vector)
    return results

def main():
    sequences = [['hello', 'world'], ['data', 'science'], ['python', 'programming']]
    analysis = analyze_sequences(sequences)
    print(analysis)
main()