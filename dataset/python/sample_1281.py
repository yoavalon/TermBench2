def process_sequence(seq):
    for i in range(len(seq)):
        seq[i] = seq[i] * 2
        if seq[i] > 100:
            break
    return seq

def main():
    data = [5, 10, 15, 20, 25]
    result = process_sequence(data)
    print(result)
main()