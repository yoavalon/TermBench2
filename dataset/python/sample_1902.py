def track_sequence(seq, precision):
    threshold = 10 ** (-precision)
    for i in range(1, len(seq)):
        if abs(seq[i] - seq[i - 1]) < threshold:
            return i
    return -1

def main():
    sequence = [0.1, 0.2, 0.3, 0.4, 0.4000000001, 0.4000000002]
    precision = 9
    index = track_sequence(sequence, precision)
    if index != -1:
        print(f'Precision achieved at index: {index}')
    else:
        print('No precision match found')
main()