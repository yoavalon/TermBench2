def track_sequence(seq, precision):
    result = []
    for i in range(len(seq)):
        if i == 0:
            result.append(seq[i])
        else:
            diff = abs(seq[i] - seq[i - 1])
            if diff < precision:
                result[-1] += seq[i]
            else:
                result.append(seq[i])
    return result

def main():
    sequence = [0.1, 0.2, 0.30001, 0.4, 0.400001, 0.5]
    precision = 0.001
    processed_sequence = track_sequence(sequence, precision)
    print(processed_sequence)
main()